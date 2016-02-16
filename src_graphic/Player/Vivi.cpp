#include "Vivi.hh"
#include "Sound.hh"

static std::map<int, glm::vec4>		_color =
  {
    {1, glm::vec4(0.16, 0.16, 0.16, 1)},
    {2, glm::vec4(0.55, 0.08, 0.08, 1)},
    {3, glm::vec4(0.44, 0.18, 0.73, 1)},
    {4, glm::vec4(0.06, 0.35, 0.71, 1)},
    {5, glm::vec4(0.04, 0.67, 0.04, 1)},
    {6, glm::vec4(0.24, 0.86, 0.67, 1)},
    {7, glm::vec4(0.90, 0.90, 0.24, 1)},
    {8, glm::vec4(1, 1, 1, 1)}
  };

Vivi::Vivi(int id, glm::vec3 const &pos, glm::vec3 const &rot, int lvl)
  : _position(pos), _rotation(rot), _id(id),  _lvl(lvl)
{
  this->_scale = glm::vec3(0.003, 0.003, 0.003);

  this->_model = new gdl::Model;
  if (!this->_model->load("./src_graphic/res/model/vivi/vivi.fbx"))
    throw ResError("./src_graphic/res/model/vivi/vivi.fbx");

  this->_inventory = new Ressource();

  this->_running = false;
  this->_incant = false;

  this->_speed = 2.0f;
  this->_Btime = 0.0f;
  this->_Gtime = 0.0f;
  this->_UPtime = 0.0f;

  this->_broadcast = new Plan(0.7, pos, "BROADCAST");
  this->_lvlup = new Plan(0.7, pos, "LVLUP");

  this->_model->createSubAnim(0, "pick", 10 , 74);
  this->_model->createSubAnim(0, "wait", 0 , 0);
  this->_model->createSubAnim(0, "incantation", 80 , 182);
  this->_model->createSubAnim(0, "run", 195, 240);
}

Vivi::~Vivi()
{
  delete _model;
}

int		Vivi::getLvl() const
{
  return _lvl;
}

glm::vec3	Vivi::getPos() const
{
  return _position;
}

int		Vivi::getId() const
{
  return _id;
}

Ressource             *Vivi::getRessource() const
{
  return _inventory;
}

glm::mat4	Vivi::getTransformation() const
{
  glm::mat4   transform(1);

  transform = glm::translate(transform, glm::vec3(_position.x, _position.y - 0.5, _position.z));
  transform = glm::rotate(transform, this->_rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, this->_rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, this->_rotation.z, glm::vec3(0, 0, 1));
  transform = glm::scale(transform, this->_scale);
  return (transform);
}

void		Vivi::setPos(glm::vec3 const &pos, glm::vec3 const &orientation)
{
  this->_goTo.push_back(std::pair<glm::vec3, glm::vec3>(pos, orientation));
}

void		Vivi::isRunning()
{
  if (this->_running == false)
    {
      this->_model->setCurrentSubAnim("run", true);
      this->_running = true;
      this->_incant = false;
    }
}

void		Vivi::wait()
{
  if (this->_running || this->_incant)
    {
      this->_model->setCurrentSubAnim("wait", true);
      this->_running = false;
      this->_incant = false;
    }
}

void		Vivi::incant()
{
  if (!this->_incant)
    {
      this->_model->setCurrentSubAnim("incantation", true);
      this->_running = false;
      this->_incant = true;
    }
}

void		Vivi::pick()
{
  this->_model->setCurrentSubAnim("pick", true);
  this->_Gtime = 0.8f;
}

void		Vivi::updateLevel(const int level)
{
  this->_UPtime = 2.0f;
  this->_lvl = level;
  Sound::play("broadcast");
}

void		Vivi::broadcast()
{
  this->_Btime = 2.0f;
}

void		Vivi::translate(glm::vec3 const &v)
{
  this->_position += v;
}

void		Vivi::rotate(glm::vec3 const &axis, float angle)
{
  this->_rotation = axis * angle;
}

void		Vivi::moveLeft()
{
  isRunning();
  translate(glm::vec3(1, 0, 0) * static_cast<float>(_clock.getElapsed()) * this->_speed);
  if (_position.x >= _goTo.front().first.x)
    {
      this->_position = _goTo.front().first;
      this->_goTo.pop_front();
    }
}

void		Vivi::moveRight()
{
  isRunning();
  translate(glm::vec3(-1, 0, 0) * static_cast<float>(_clock.getElapsed()) * this->_speed);
  if (_position.x <= _goTo.front().first.x)
    {
      this->_position = _goTo.front().first;
      this->_goTo.pop_front();
    }
}

void		Vivi::moveUp()
{
  isRunning();
  translate(glm::vec3(0, 0, 1) * static_cast<float>(_clock.getElapsed()) * this->_speed);
  if (_position.z >= _goTo.front().first.z)
    {
      this->_position = _goTo.front().first;
      this->_goTo.pop_front();
    }
}

void		Vivi::moveDown()
{
  isRunning();
  translate(glm::vec3(0, 0, -1) * static_cast<float>(_clock.getElapsed()) * this->_speed);
  if (_position.z <= _goTo.front().first.z)
    {
      this->_position = _goTo.front().first;
      this->_goTo.pop_front();
    }
}

void		Vivi::update(gdl::Clock const &clock,
			     __attribute__((unused))gdl::Input const &input,
			     int w, int h)
{
  if (_Btime > 0)
    {
      _Btime -= _clock.getElapsed();
      this->_broadcast->setPosition(glm::vec3(_position.x, _position.y + 0.5, _position.z));
    }
  if (_UPtime > 0)
    {
      _UPtime -= _clock.getElapsed();
      this->_lvlup->setPosition(glm::vec3(_position.x, _position.y + 0.5, _position.z));
    }
  if (_Gtime > 0)
    _Gtime -= _clock.getElapsed();

  this->_clock = clock;
  w -= 1;
  h -= 1;
  if (_goTo.size() >= 1)
    {
      this->_rotation = _goTo.front().second;
      if (_goTo.front().first != _position)
	{
	  if (((_position.x - _goTo.front().first.x) == -w)
	      || ((_position.x - _goTo.front().first.x) == w)
	      || ((_position.z - _goTo.front().first.z) == -h)
	      || ((_position.z - _goTo.front().first.z) == h))
	    {
	      this->_position = _goTo.front().first;
	      this->_goTo.pop_front();
	    }
	  else if (_position.z < _goTo.front().first.z)
	    moveUp();
	  else if (_position.z > _goTo.front().first.z)
	    moveDown();
	  else if (_position.x < _goTo.front().first.x)
	    moveLeft();
	  else if (_position.x > _goTo.front().first.x)
	    moveRight();
	}
      else
	this->_goTo.pop_front();
    }
  else if (!_incant && _Gtime <= 0)
    wait();
}

void		Vivi::draw(gdl::AShader &s, glm::mat4 const &t,  double deltaTime)
{
  if (_Btime > 0)
    this->_broadcast->draw(s, _clock);
  if (_UPtime > 0)
    this->_lvlup->draw(s, _clock);

  s.setUniform("myColor", _color[_lvl]);
  this->_model->draw(s, t, deltaTime);
  s.setUniform("myColor", glm::vec4(0, 0, 0, 1));
}

void		Vivi::setInventory(const std::vector<int> & v) const
{
  this->_inventory->fill(v);
}
