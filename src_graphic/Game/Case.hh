#ifndef	CASE_HH
#define	CASE_HH

#include <iostream>
#include <string>
#include <sstream>
#include <SdlContext.hh>
#include <BasicShader.hh>

#include "Ressource.hh"
#include "Cube.hh"
#include "Plan.hh"

class	Case
{
public:
  Case(glm::vec3 const &, std::string const &, int);
  ~Case();

  void		update(gdl::Clock &c, gdl::Input &i);
  void		draw(gdl::AShader &s, gdl::Clock &c);
  void		fill(std::vector<int> const &);
  glm::vec3	getPos() const;
  Ressource     *getRessource() const;

private:
  glm::vec3	_pos;
  AObject	*_obj;
  std::vector<Plan*>	_gem;
  Ressource	*_res;
};

#endif
