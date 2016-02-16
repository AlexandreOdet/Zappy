#include "Camera.hh"

Camera::Camera(int width, int height, gdl::BasicShader const &shader) :
  _shader(shader), _width(width), _height(height)
{
  this->_zoom = (_width > _height) ? _width : _height;
  this->_pos = glm::vec3(this->_height / 2, _zoom, 0);
  this->_lookAt = glm::vec3((_width / 2), 0, (_height / 2));
  this->_speed = 20.0f;
  this->_projection = glm::perspective(60.f, 1280.0f/720.0f, 0.001f, 10000.0f);
  this->_transformation = glm::lookAt(this->_pos, this->_lookAt, glm::vec3(0, 2, 0));
  this->_shader.setUniform("view", this->_transformation);
  this->_shader.setUniform("projection", this->_projection);
  this->_shader.bind();

  this->anglez = 0;
  this->anglex = 0;
}

glm::mat4 const Camera::getProjection() const
{
  return this->_projection;
}

glm::mat4 const Camera::getTransformation() const
{
  return this->_transformation;
}

Camera::~Camera()
{
}

void		Camera::trackPlayer(Vivi const *player)
{
  glm::vec3	tmp = player->getPos();

  this->_pos = glm::vec3(tmp.x , this->_pos.y, tmp.z - 2);
  this->_lookAt = tmp;
}

void		Camera::translate(glm::vec3 const &v)
{
  this->_pos += v;
  this->_lookAt += v;
}

void		Camera::setZoom(float const z)
{
  this->_zoom = z;
}

void		Camera::moveleft()
{
  anglex += MOVE;
  anglez -= MOVE;
  this->_pos.x = _zoom * cos(anglex);
  this->_pos.z = _zoom * sin(anglez);
  this->_pos.y = _zoom;
}

void		Camera::moveright()
{
  anglex -= MOVE;
  anglez += MOVE;
  this->_pos.x = _zoom * cos(anglex);
  this->_pos.z = _zoom * sin(anglez);
  this->_pos.y = _zoom;
}

void		Camera::move(gdl::Clock const &clock, gdl::Input &input)
{
  if (input.getKey(SDLK_UP))
    {
      this->_pos = glm::vec3((_width / 2), _zoom, (_height / 2) - 0.01);
      this->_lookAt = glm::vec3((_width / 2), 0, (_height / 2));
    }
  if (input.getKey(SDLK_LEFT))
    moveleft();
  if (input.getKey(SDLK_RIGHT))
    moveright();
  if (input.getKey(SDLK_KP_PLUS) && this->_pos.y > 1.5)
    translate(glm::vec3(0, -1, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_KP_MINUS))
    translate(glm::vec3(0, 1, 0) * static_cast<float>(clock.getElapsed()) * _speed);

  if (input.getKey(SDLK_z) && _pos.z < _width)
    translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_s) && _pos.z > -1)
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_q)  && _pos.x < _height)
    translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_d) && _pos.x > (_height * -0.5))
    translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
}

void		Camera::update(gdl::Clock const &clock, gdl::Input &input)
{
  move(clock, input);
}

void		Camera::update(gdl::Clock const &clock, gdl::Input &input,
			       Vivi const *player)
{
  if (player)
    trackPlayer(player);
  move(clock, input);
}

void		Camera::draw()
{
  this->_projection = glm::perspective(60.f, 1280.0f/720.0f, 0.001f, 10000.0f);
  this->_transformation = glm::lookAt(this->_pos, this->_lookAt, glm::vec3(0, 2, 0));
  this->_shader.bind();
  this->_shader.setUniform("view", this->_transformation);
  this->_shader.setUniform("projection", this->_projection);
}

void		Camera::drawOrtho()
{
  this->_projection = glm::mat4(1);
  this->_transformation = glm::mat4(1);
  this->_shader.bind();
  this->_shader.setUniform("view", this->_transformation);
  this->_shader.setUniform("projection", this->_projection);
}

glm::vec3 const	&Camera::getPos() const
{
  return _pos;
}

void		Camera::setPos(glm::vec3 const &pos)
{
  this->_pos = pos;
}
