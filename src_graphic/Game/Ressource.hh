#ifndef	RESSOURCE_HH
#define	RESSOURCE_HH

#include <iostream>
#include <string>
#include <vector>

class	Ressource
{
public:
  Ressource();
  ~Ressource();

  void	fill(std::vector<int> const &v);
  std::vector<int>	getRes() const;
  int	getFood() const;
  int	getLin() const;
  int	getDer() const;
  int	getSib() const;
  int	getMen() const;
  int	getPhi() const;
  int	getThy() const;

private:
  int	_food;
  int	_linemate;
  int	_deraumere;
  int	_sibur;
  int	_mendiane;
  int	_phiras;
  int	_thystame;
};

#endif
