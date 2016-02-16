#ifndef __VIVI_HH__
#define __VIVI_HH__

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Game.hh>
#include <Clock.hh>
#include <Model.hh>
#include <SdlContext.hh>
#include <string>
#include <map>
#include <vector>

#include "Exception.hpp"
#include "Ressource.hh"
#include "Plan.hh"

class Vivi
{
private:
  gdl::Model	*_model;
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;
  gdl::Clock	_clock;

  Ressource	*_inventory;

  std::list<std::pair<glm::vec3, glm::vec3> >	_goTo;

  int		_id;
  int		_lvl;
  float		_speed;
  bool		_running;
  bool		_incant;

  float		_Gtime;
  float		_UPtime;
  float		_Btime;
  AObject	*_broadcast;
  AObject	*_lvlup;

public:
  Vivi(int, glm::vec3 const &, glm::vec3 const &, int);
  ~Vivi();

  void			update(gdl::Clock const &, gdl::Input const &, int, int);
  void			draw(gdl::AShader &, glm::mat4 const &, double);
  Ressource		*getRessource() const;
  int			getLvl() const;
  void			updateLevel(const int);

  void			broadcast();
  void			incant();
  void			wait();
  void			pick();

  int			getId() const;
  glm::mat4		getTransformation() const;
  void			setPos(glm::vec3 const &, glm::vec3 const&);
  glm::vec3		getPos() const;

  void			setInventory(const std::vector<int> &) const;

private:
  void			moveLeft();
  void			moveRight();
  void			moveUp();
  void			moveDown();
  void			isRunning();

  void			translate(glm::vec3 const &);
  void			rotate(glm::vec3 const &axis, float angle);
};

#endif
