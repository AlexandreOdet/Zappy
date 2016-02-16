#ifndef PLAN_HH_
#define PLAN_HH_

#include "AObject.hpp"

class Plan : public AObject
{
public:
  Plan(float const size, glm::vec3 const &pos, std::string const &texture);
  Plan(float x, float y,  glm::vec3 const &pos, std::string const &texture);
  virtual ~Plan() { };

  virtual void	initialize();
  virtual void	setUV();
  virtual void	draw(gdl::AShader &shader,gdl::Clock const &clock);
  void		changeTexture(std::string const &texture);

private:
  static gdl::Geometry	*_geometry;
  static bool		is_init;
};

#endif /* PLAN_HH_ */
