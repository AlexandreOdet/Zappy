#ifndef	EXEC_HH
#define	EXEC_HH

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "MyGame.hh"
#include "Parser.hh"
#include "Case.hh"

class NetWork;

class	Exec
{
private:
  MyGame	*engine;
  std::list<std::pair<int, glm::vec3> > _list;

public:
  Exec();
  ~Exec();

  MyGame	*getEngine() const;
  void		setEngine(int const x, int const y);

  void		bct(std::string const &);
  void		tna(std::string const &);
  void		pnw(std::string const &);
  void		pdi(std::string const &);
  void		pic(std::string const &);

  void		seg(std::string const &);
  void		enw(std::string const &);

  void		ppo(std::string const &);

  void		pfk(std::string const &);
  void		plv(std::string const &);
  void		pin(std::string const &);
  void		pex(std::string const &);
  void		pbc(std::string const &);
  void		pie(std::string const &);

  void		pdr(std::string const &);
  void		pgt(std::string const &);

  void		eht(std::string const &);
  void		ebo(std::string const &);
  void		edi(std::string const &);

  void		sgt(std::string const &);
  void		smg(std::string const &);
  void		suc(std::string const &);
  void		sbp(std::string const &);
};

#endif
