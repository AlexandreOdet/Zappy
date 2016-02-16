#include "Case.hh"

Case::Case(glm::vec3 const &pos, std::string const &texture, int rot) : _pos(pos)
{
  this->_obj = new Cube(1, pos, texture);
  this->_res = new Ressource();
  this->_obj->rotate(glm::vec3(0, 1, 0), rot);

  this->_gem.push_back(new Plan(0.2, pos + glm::vec3(0.1, 0.52, 0.2), "food"));
  this->_gem.push_back(new Plan(0.2, pos + glm::vec3(-0.1, 0.52, 0.2), "linemate"));
  this->_gem.push_back(new Plan(0.2, pos + glm::vec3(0.2, 0.52, 0), "deraumere"));
  this->_gem.push_back(new Plan(0.2, pos + glm::vec3(0, 0.52, 0), "sibur"));
  this->_gem.push_back(new Plan(0.2, pos + glm::vec3(-0.2, 0.52, 0), "Mendiane"));
  this->_gem.push_back(new Plan(0.2, pos + glm::vec3(0.1, 0.52, -0.2), "Phiras"));
  this->_gem.push_back(new Plan(0.2, pos + glm::vec3(-0.1, 0.52, -0.2), "Thystame"));
}

Case::~Case()
{
}

void	Case::fill(std::vector<int> const &res)
{
  _res->fill(res);
}

void	Case::update(gdl::Clock &c, gdl::Input &i)
{
  this->_obj->update(c, i);
  if (_res->getFood() > 0)
    _gem[0]->update(c, i);
  if (_res->getLin() > 0)
    _gem[1]->update(c, i);
  if (_res->getDer() > 0)
    _gem[2]->update(c, i);
  if (_res->getSib() > 0)
    _gem[3]->update(c, i);
  if (_res->getMen() > 0)
    _gem[4]->update(c, i);
  if (_res->getPhi() > 0)
    _gem[5]->update(c, i);
  if (_res->getThy() > 0)
    _gem[6]->update(c, i);

}

void	Case::draw(gdl::AShader &s, gdl::Clock &c)
{
  this->_obj->draw(s, c);
  if (_res->getFood() > 0)
    _gem[0]->draw(s, c);
  if (_res->getLin() > 0)
    _gem[1]->draw(s, c);
  if (_res->getDer() > 0)
    _gem[2]->draw(s, c);
  if (_res->getSib() > 0)
    _gem[3]->draw(s, c);
  if (_res->getMen() > 0)
    _gem[4]->draw(s, c);
  if (_res->getPhi() > 0)
    _gem[5]->draw(s, c);
  if (_res->getThy() > 0)
    _gem[6]->draw(s, c);
}

Ressource     *Case::getRessource() const
{
  return _res;
}
glm::vec3	Case::getPos() const
{
  return _pos;
}
