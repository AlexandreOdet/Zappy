#ifndef	CAMERA_HH
#define	CAMERA_HH

#include <iostream>
#include <string>
#include <Game.hh>
#include <Clock.hh>
#include <Input.hh>
#include <SdlContext.hh>
#include <Geometry.hh>
#include <Texture.hh>
#include <BasicShader.hh>
#include <Model.hh>
#include <OpenGL.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cstdlib>
#include <vector>
#include <math.h>

#include "Vivi.hh"

#define	MOVE 0.05

class	Camera
{
public:
  Camera(int, int, gdl::BasicShader const &);
  ~Camera();

public:
  glm::vec3 const	&getPos() const;
  void			setPos(glm::vec3 const &);
  void			setZoom(float const);
  void			setTrack(bool const);
  void			update(gdl::Clock const &, gdl::Input &, Vivi const *);
  void			update(gdl::Clock const &, gdl::Input &);
  void			draw();
  void			drawOrtho();
  glm::mat4 const	getProjection() const;
  glm::mat4 const	getTransformation() const;

private:
  void			translate(glm::vec3 const &);
  void			trackPlayer(Vivi const*);

  void			moveright();
  void			moveleft();
  void			move(gdl::Clock const &clock, gdl::Input &input);

private:
  gdl::BasicShader	_shader;
  glm::vec3		_pos;
  glm::vec3		_lookAt;
  glm::mat4		_projection;
  glm::mat4		_transformation;

  int			_width;
  int			_height;
  float			_speed;
  float			_zoom;

  double		anglex;
  double		anglez;
};

#endif
