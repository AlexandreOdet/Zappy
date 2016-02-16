#include "Ressource.hh"

Ressource::Ressource()
{
  _food = 0;
  _linemate = 0;
  _deraumere = 0;
  _sibur = 0;
  _mendiane = 0;
  _phiras = 0;
  _thystame = 0;
}

Ressource::~Ressource()
{
}

void	Ressource::fill(std::vector<int> const &v)
{
  _food = v[0];
  _linemate = v[1];
  _deraumere = v[2];
  _sibur = v[3];
  _mendiane = v[4];
  _phiras = v[5];
  _thystame = v[6];
}

std::vector<int>	Ressource::getRes() const
{
  std::vector<int>	tmp;

  tmp.push_back(_food);
  tmp.push_back(_linemate);
  tmp.push_back(_deraumere);
  tmp.push_back(_sibur);
  tmp.push_back(_mendiane);
  tmp.push_back(_phiras);
  tmp.push_back(_thystame);
  return tmp;
}


int	Ressource::getFood() const
{
  return _food;
}

int	Ressource::getLin() const
{
  return _linemate;
}

int	Ressource::getDer() const
{
  return _deraumere;
}

int	Ressource::getSib() const
{
  return _sibur;
}

int	Ressource::getMen() const
{
  return _mendiane;
}

int	Ressource::getPhi() const
{
  return _phiras;
}

int	Ressource::getThy() const
{
  return _thystame;
}
