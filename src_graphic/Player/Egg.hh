#ifndef __EGG_HH__
#define __EGG_HH__

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

class Egg
{
protected:
  gdl::Model	*_model;
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;

  int		_Pid;
  int		_id;
  bool		_is_select;
  float		_speed;

public:
  Egg(int, int, glm::vec3 const &);
  ~Egg();

  glm::vec3 const	&getPosition() const;
  void			update(gdl::Clock const &, gdl::Input &);
  void			draw(gdl::AShader &, glm::mat4 const &, double);

  int			getId() const;
  glm::mat4		getTransformation() const;
};

#endif
