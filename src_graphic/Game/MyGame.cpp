#include "MyGame.hh"

#include "NetWork.hh"

MyGame::MyGame(int width, int heigth) : _width(width), _height(heigth)
{
  new Sound();
}

MyGame::~MyGame()
{
}

bool		MyGame::initialize()
{
  if (!_context.start(WIN_X, WIN_Y, "Zappy"))
    throw GameError("Error while initializing context");
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  if (!_shader.load("./src_graphic/lib/gdl/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./src_graphic/lib/gdl/shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    throw GameError("Error while initializing shaders");
  glAlphaFunc(GL_GREATER, 0.1f);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_ALPHA_TEST);
  new texture();
  _hud = new HUD();

  initMap();

  this->_camera = new Camera(_width, _height, _shader);
  this->_time = 0;
  this->_ToTrack = NULL;

  this->_bg = new Plan(2, glm::vec3(0, 0, 0), "BG");
  this->_bg->rotate(glm::vec3(0, 1, 0), 90);
  this->_bg->rotate(glm::vec3(0, 0, 1), -90);

  Sound::play("game");
  return true;
}

void			MyGame::result(__attribute__((unused))std::string const &winner)
{
  texture::addImage(IMG_Load("./src_graphic/res/end.jpg"), "result");

  Plan	*res = new Plan(2, glm::vec3(0, 0, 0), "result");
  res->rotate(glm::vec3(0, 1, 0), 90);
  res->rotate(glm::vec3(0, 0, 1), -90);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  res->update(_clock, _input);
  this->_camera->drawOrtho();
  res->draw(_shader, _clock);
  _context.flush();
  std::this_thread::sleep_for(std::chrono::seconds(5));
}

void			MyGame::setCase(int const pos, Case *tmp)
{
  this->_map[pos] = tmp;
}

HUD			*MyGame::getHUD()
{
  return _hud;
}

std::vector<Case*>	MyGame::getMap() const
{
  return _map;
}

std::vector<Team*>	MyGame::getTeam() const
{
  return _teams;
}

void	MyGame::addTeam(std::string const &name)
{
  this->_teams.push_back(new Team(name));
}

void	MyGame::addPlayer(std::string const &s)
{
  std::vector<std::string>	tmp = Parser<std::string>::StringToVector(s);
}

void	MyGame::initMap()
{
  for (int x = 0; x != _width; ++x)
    {
      for (int y = 0; y != _height; ++y)
	{
	  if (y == 0 && x == 0)
	    _map.push_back(new Case(glm::vec3(x, 0, y), "GCORNER", 90));
	  else if (y == 0 && x == (_width - 1))
	    _map.push_back(new Case(glm::vec3(x, 0, y), "GCORNER", 0));
	  else if (y == (_height - 1) && x == (_width - 1))
	    _map.push_back(new Case(glm::vec3(x, 0, y), "GCORNER", -90));
	  if (y == (_height - 1) && x == 0)
	    _map.push_back(new Case(glm::vec3(x, 0, y), "GCORNER", 180));
	  else if (y == 0)
	    _map.push_back(new Case(glm::vec3(x, 0, y), "GEDGE", 0));
	  else if (y == (_height - 1))
	    _map.push_back(new Case(glm::vec3(x, 0, y), "GEDGE", 180));
	  else if (x == 0)
	    _map.push_back(new Case(glm::vec3(x, 0, y), "GEDGE", 90));
	  else if (x == _width - 1)
	    _map.push_back(new Case(glm::vec3(x, 0, y), "GEDGE", -90));
	  else
	    _map.push_back(new Case(glm::vec3(x, 0, y), "GROUND", 0));
	}
    }
}

void	MyGame::setTime(const int time)
{
  this->_time = time;
}

void	MyGame::setTimeLower()
{
  this->_time -= 10;
  if (this->_time <= 0)
    this->_time = 1;
  std::string time = "sst " + std::to_string(this->_time) + "\n";
  NetWork::sendToServer(time);
}

void	MyGame::setTimeHigher()
{
  if (this->_time < 150)
    {
      this->_time += 10;
      std::string time = "sst " + std::to_string(this->_time) + "\n";
      NetWork::sendToServer(time);
    }
}

bool	MyGame::update()
{
  _context.updateInputs(_input);
  _context.updateClock(_clock);

  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  if (_input.getKeyPressed(SDL_BUTTON_LEFT, _clock))
    this->intersect(_input.getMousePosition().x, _input.getMousePosition().y, 0);
  if (_input.getKeyPressed(SDL_BUTTON_RIGHT, _clock))
    this->intersect(_input.getMousePosition().x, _input.getMousePosition().y, 1);
  if (_input.getKeyPressed(SDLK_F6, _clock))
    setTimeLower();
  if (_input.getKeyPressed(SDLK_F7, _clock))
    setTimeHigher();

  if (!_map.empty())
    for (int i = 0; i < static_cast<int>(_map.size()); ++i)
      this->_map[i]->update(_clock, _input);
  if (!_teams.empty())
    for (int i = 0; i < static_cast<int>(_teams.size()); ++i)
      this->_teams[i]->update(_clock, _input, _width, _height);

  if (this->_ToTrack)
    this->_camera->update(_clock, _input, _ToTrack);
  else
    this->_camera->update(_clock, _input);

  _hud->updatetime(_time);
  return true;
}

void	MyGame::intersect(const int _posx, const int _posy, const int player)
{
  int mouseX = _posx;
  int mouseY = WIN_Y - _posy;

  glm::vec3 vA = glm::unProject(glm::vec3(mouseX, mouseY, 0.0f),
				_camera->getTransformation(),
				_camera->getProjection(),
				glm::vec4(0, 0, WIN_X, WIN_Y));
  glm::vec3 vB = glm::unProject(glm::vec3(mouseX, mouseY, 1.0f),
				_camera->getTransformation(),
				_camera->getProjection(),
				glm::vec4(0, 0, WIN_X, WIN_Y));

  if (!player)
    {
      std::vector<Case*> _case = this->getMap();
      for (int i = 0; i < static_cast<int>(_case.size()); i++)
        {
	  if (checkCollision(_case[i]->getPos(), 0.5f, vA, vB))
            {
	      _hud->update(_clock, _input, _case[i]);
	      this->_ToTrack = NULL;
	      return;
            }
        }
    }
  else
    {
      std::vector<Team*> team = this->getTeam();
      for (int i = 0; i < static_cast<int>(team.size()); i++)
	{
	  std::vector<Vivi *> vivis = team[i]->getPlayer();
	  for (int j = 0; j < static_cast<int>(vivis.size()); j++)
	    {
	      if (checkCollision(vivis[j]->getPos(), 0.5f, vA, vB))
		{
		  _hud->update(_clock, _input, vivis[j]);
		  this->_ToTrack = vivis[j];
		  return;
		}
	    }
	}
    }
  this->_hud->setDraw(false);
  this->_ToTrack = NULL;
}

bool MyGame::checkCollision(glm::vec3 sphereCenter, float sphereRadius, glm::vec3 vA,
			    glm::vec3 vB) const
{
  glm::vec3 vDirToSphere = sphereCenter - vA;
  glm::vec3 vLineDir = glm::normalize(vB - vA);
  glm::vec3 vClosestPoint;

  float fLineLength = glm::distance(vA, vB);
  float t = glm::dot(vDirToSphere, vLineDir);

  if (t <= 0.0f)
    vClosestPoint = vA;
  else if (t >= fLineLength)
    vClosestPoint = vB;
  else
    vClosestPoint = vA + vLineDir* t;

  return (glm::distance(sphereCenter, vClosestPoint) <= sphereRadius);
}

void	MyGame::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();

  glDisable(GL_DEPTH_TEST);
  this->_camera->drawOrtho();
  this->_bg->draw(_shader, _clock);

  glEnable(GL_DEPTH_TEST);

  _hud->draw(_shader, _clock);

  this->_camera->draw();

  /*
    if (!_map.empty())
    for (int i = 0; i < static_cast<int>(_map.size()); i++)
    this->_map[i]->draw(_shader, _clock);
  */
  if (!_teams.empty())
    for (int i = 0; i < static_cast<int>(_teams.size()); ++i)
      this->_teams[i]->draw(_shader, _clock.getElapsed());
  _context.flush();
}
