#ifndef	HUD_HH
#define	HUD_HH

#include <iostream>
#include <string>

#include "Case.hh"
#include "Vivi.hh"
#include "Plan.hh"
#include "Ressource.hh"
#include "texture.hh"

class	HUD
{
public:
  HUD();
 ~HUD();


  void	updatetime(int);
  void	setDraw(bool const);
  void	update(gdl::Clock const &c, gdl::Input const &i, Case const *);
  void	update(gdl::Clock const &c, gdl::Input const &i, Vivi const *);
  void	update();

  void	draw(gdl::AShader &s, gdl::Clock &c);

  Plan	*addPlan(float x, float y, glm::vec3 const &v, std::string const &name) const;
  void	addTeam(std::string const &team);

private:
  bool			_p;
  bool			_draw;
  Plan                  *_obj;
  std::vector<Plan*>    _num;
  Ressource		*r;
  std::vector<Plan*>	_team;
};

#endif
