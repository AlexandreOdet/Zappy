#ifndef __MYGAME_HH__
#define __MYGAME_HH__

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
#include <fmod.h>

#include <thread>
#include <chrono>

#include "HUD.hh"
#include "Camera.hh"
#include "Plan.hh"
#include "Sound.hh"
#include "Texture.hh"
#include "Case.hh"
#include "Team.hh"

class NetWork;

#define	WIN_X	1280
#define	WIN_Y	720

class MyGame : public gdl::Game
{
public:
  MyGame(int width, int heigth);
  ~MyGame();

  bool			initialize();
  bool			update();
  void			draw();
  void			result(std::string const &);

  std::vector<Case*>	getMap() const;
  Case*			getMapByPos(glm::vec3 const &) const;
  std::vector<Team*>	getTeam() const;
  void			setCase(int const pos, Case *);
  void			addTeam(std::string const &);
  void			addPlayer(std::string const &);

  void			processHits(GLint, GLuint *);
  void			picking();
  void			setTime(const int);
  HUD			*getHUD();

private:
  void			initMap();
  void			setTimeHigher();
  void			setTimeLower();
  void			intersect(const int, const int, const int);
  bool			checkCollision(glm::vec3, float, glm::vec3, glm::vec3) const;

private:
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;

  std::vector<Case*>	_map;
  std::vector<Team*>	_teams;

  Plan			*_bg;
  int			_width;
  int			_height;
  int			_time;

  bool			_track;
  Vivi			*_ToTrack;

  Camera		*_camera;
  FMOD_SOUND		*son;
  HUD			*_hud;
};

#endif
