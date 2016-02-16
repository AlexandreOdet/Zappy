#include "Team.hh"

Team::Team(std::string const &name)
{
  this->_name = name;

  _orientation[LEFT] = glm::vec3(90, 90, -90);
  _orientation[UP] = glm::vec3(180, 0, 180);
  _orientation[RIGHT] = glm::vec3(270, 270, -90);
  _orientation[DOWN] = glm::vec3(180, 180, 180);
}

Team::~Team()
{
}

std::string	Team::getName() const
{
  return _name;
}

glm::vec3	Team::getRot(int x)
{
  side	tmp = static_cast<side>(x);
  return _orientation[tmp];
}

void	Team::addPlayer(std::string const &pos)
{
  std::vector<int>	v = Parser<int>::StringToVector(pos);

  side	tmp = static_cast<side>(v[3]);

  _players.push_back(new Vivi(v[0], glm::vec3(v[1], 1, v[2]), _orientation[tmp], v[4]));
}

void	Team::addEgg(std::string const &pos)
{
  std::vector<int>	v = Parser<int>::StringToVector(pos);

  _egg.push_back(new Egg(v[0], v[1], glm::vec3(v[2], 1, v[3])));
}

void	Team::deletePlayer(const int x)
{
  _players.erase(_players.begin() + x);
}

void	Team::deleteEgg(const int pos)
{
  _egg.erase(_egg.begin() + pos);
}

void	Team::update(gdl::Clock const &clock, gdl::Input &input, int width, int height)
{
  if (_players.size() >= 1)
    for (std::vector<Vivi*>::iterator it = _players.begin(); it != _players.end(); ++it)
      (*it)->update(clock, input, width, height);
  if (_egg.size() >= 1)
    for (std::vector<Egg*>::iterator it = _egg.begin(); it != _egg.end(); ++it)
      (*it)->update(clock, input);
}

void	Team::draw(gdl::AShader &shader, double deltaTime)
{
  if (_players.size() >= 1)
    for (std::vector<Vivi*>::iterator it = _players.begin(); it != _players.end(); ++it)
      (*it)->draw(shader, (*it)->getTransformation(), deltaTime);
  if (_egg.size() >= 1)
    for (std::vector<Egg*>::iterator it = _egg.begin(); it != _egg.end(); ++it)
      (*it)->draw(shader, (*it)->getTransformation(), deltaTime);
}

std::vector<Vivi*>	Team::getPlayer() const
{
  return this->_players;
}

std::vector<Egg*>	Team::getEgg() const
{
  return this->_egg;
}
