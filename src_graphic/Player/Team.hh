#ifndef __TEAM_HH__
#define __TEAM_HH__

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Game.hh>
#include <Clock.hh>
#include <Model.hh>
#include <SdlContext.hh>
#include <string>
#include <map>
#include <vector>

#include "Parser.hh"
#include "Exception.hpp"
#include "Vivi.hh"
#include "Egg.hh"

enum	side
  {
    UP = 1,
    LEFT = 2,
    DOWN = 3,
    RIGHT = 4
  };

class Team
{
public:
  Team(std::string const &);
  ~Team();

  std::string		getName() const;
  std::vector<Vivi*>	getPlayer() const;
  std::vector<Egg*>	getEgg() const;
  glm::vec3		getRot(int x);

  void			deletePlayer(const int);
  void			addPlayer(std::string const&);
  void			addEgg(std::string const&);
  void			deleteEgg(const int);
  void			update(gdl::Clock const &, gdl::Input &, int, int);
  void			draw(gdl::AShader &, double);

private:
  std::string			_name;
  std::vector<Vivi*>		_players;
  std::vector<Egg*>		_egg;
  std::map<side, glm::vec3>	_orientation;
};

#endif
