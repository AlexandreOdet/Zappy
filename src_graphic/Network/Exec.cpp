#include "Exec.hh"

#include "NetWork.hh"

Exec::Exec()
{
}

Exec::~Exec()
{
  delete this->engine;
}

MyGame	*Exec::getEngine() const
{
  return engine;
}

void	Exec::setEngine(int const x, int const y)
{
  this->engine = new MyGame(x, y);
}

void	Exec::bct(std::string const &res)
{
  std::vector<int>	values = Parser<int>::StringToVector(res);
  std::vector<Case*>	tmp = engine->getMap();

  for (int i = 0; i < static_cast<int>(tmp.size()); i++)
    {
      if (tmp[i]->getPos() == glm::vec3(values[0], 0, values[1]))
	{
	  values.erase(values.begin(), values.begin() + 2);
	  engine->getMap().at(i)->fill(values);
	  return;
	}
    }
}

void	Exec::tna(std::string const &name)
{
  this->engine->addTeam(name);
  this->engine->getHUD()->addTeam(name);
}

void	Exec::pnw(std::string const & arg)
{
  std::vector<std::string> values = Parser<std::string>::StringToVector(arg);
  std::vector<Team*> teams = this->engine->getTeam();

  for (int i = 0; i < static_cast<int>(teams.size()); i++)
    {
      if (teams[i]->getName() == values.back())
	{
	  teams[i]->addPlayer(arg);
	  return;
	}
    }
}

void	Exec::pin(std::string const & arg)
{
  std::vector<int> values = Parser<int>::StringToVector(arg);
  std::vector<Team*> teams = this->engine->getTeam();

  for (int i = 0; i < static_cast<int>(teams.size()); i++)
    {
      std::vector<Vivi*> players = teams[i]->getPlayer();
      for (int j = 0; j < static_cast<int>(players.size()); j++)
	{
	  if (players[j]->getId() == values.front())
	    {
	      values.erase(values.begin(), values.begin() + 3);
	      players[j]->setInventory(values);
	      return;
	    }
	}
    }
}

void	Exec::pdi(std::string const & arg)
{
  std::vector<Team*> teams = this->engine->getTeam();

  for (int i = 0; i < static_cast<int>(teams.size()); i++)
    {
      std::vector<Vivi*> players = teams[i]->getPlayer();
      for (int j = 0; j < static_cast<int>(players.size()); j++)
	{
	  if (players[j]->getId() == std::stoi(arg))
	    {
	      teams[i]->deletePlayer(j);
	      return;
	    }
	}
    }
}

void	Exec::pic(std::string const & arg)
{
  std::vector<Team*> teams = this->engine->getTeam();
  std::string x, y, level, tmp;

  tmp = arg;

  x = tmp.substr(0, tmp.find_first_of(" "));
  tmp.erase(0, tmp.find_first_of(" ") + 1);
  y = tmp.substr(0, tmp.find_first_of(" "));
  tmp.erase(0, tmp.find_first_of(" ") + 1);
  level = tmp.substr(0, tmp.find_first_of(" "));
  tmp.erase(0, tmp.find_first_of(" ") + 1);

  for (int i = 0; i < static_cast<int>(teams.size()); i++)
    {
      std::vector<Vivi*> players = teams[i]->getPlayer();
      for (int j = 0; j < static_cast<int>(players.size()); j++)
	{
	  if (players[j]->getId() == std::stoi(tmp))
	    {
	      _list.push_back(std::pair<int, glm::vec3>(std::stoi(tmp), players[j]->getPos()));
	      players[j]->incant();
	      return;
	    }
	}
    }
}

void	Exec::pex(std::string const & arg)
{
  std::cout << "Le joueur " << arg << " a poussé un joueur !" << std::endl;
}

void	Exec::sgt(std::string const &res)
{
  this->engine->setTime(std::stoi(res));
}

void	Exec::plv(std::string const & arg)
{
  std::string	tmp = arg, id;
  int		level;

  id = tmp.substr(0, tmp.find_first_of(" "));
  tmp.erase(0, tmp.find_first_of(" ") + 1);
  level = std::stoi(tmp);

  std::vector<int>	v = Parser<int>::StringToVector(arg);
  std::vector<Team*> teams = this->engine->getTeam();

  for (int i = 0; i < static_cast<int>(teams.size()); i++)
    {
      std::vector<Vivi*> players = teams[i]->getPlayer();
      for (int j = 0; j < static_cast<int>(players.size()); j++)
	{
	  if (players[j]->getId() == std::stoi(id))
	    {
	      players[j]->updateLevel(level);
	      return;
	    }
	}
    }

}

void	Exec::ppo(std::string const &arg)
{
  std::vector<int>	v = Parser<int>::StringToVector(arg);
  std::vector<Team*> teams = this->engine->getTeam();

  for (int i = 0; i < static_cast<int>(teams.size()); i++)
    {
      std::vector<Vivi*> players = teams[i]->getPlayer();
      for (int j = 0; j < static_cast<int>(players.size()); j++)
	{
	  if (players[j]->getId() == v[0])
	    {
	      players[j]->setPos(glm::vec3(v[1], 1, v[2]), teams[i]->getRot(v[3]));
	      return;
	    }
	}
    }
}

void	Exec::pbc(std::string const &arg)
{
  std::vector<int>	v = Parser<int>::StringToVector(arg);
  std::vector<Team*>	teams = this->engine->getTeam();

  for (int i = 0; i < static_cast<int>(teams.size()); i++)
    {
      std::vector<Vivi*> players = teams[i]->getPlayer();
      for (int j = 0; j < static_cast<int>(players.size()); j++)
	{
	  if (players[j]->getId() == v[0])
	    {
	      players[j]->broadcast();
	      return;
	    }
	}
    }
}

void	Exec::seg(__attribute__((unused))std::string const & arg)
{
  engine->result(arg);
}

void	Exec::smg(__attribute__((unused))std::string const & arg)
{}

void	Exec::suc(__attribute__((unused))std::string const & arg)
{

}

void	Exec::pfk(__attribute__((unused))std::string const &arg)
{

}

void	Exec::enw(std::string const & arg)
{
  std::vector<int> values = Parser<int>::StringToVector(arg);
  std::vector<Team*> teams = this->engine->getTeam();

  for (int i = 0; i < static_cast<int>(teams.size()); i++)
    {
      std::vector<Vivi*> players = teams[i]->getPlayer();
      for (int j = 0; j < static_cast<int>(players.size()); j++)
	{
	  if (players[j]->getId() == values[1])
	    {
	      teams[i]->addEgg(arg);
	      return;
	    }
	}
    }
}

void	Exec::pie(std::string const & arg)
{
  std::string x, y, tmp;
  x.clear();
  y.clear();
  tmp = arg;

  x = tmp.substr(0, tmp.find_first_of(" "));
  tmp.erase(0, tmp.find_first_of(" ") + 1);
  y = tmp.substr(0, tmp.find_first_of(" "));
  tmp.erase(0, tmp.find_first_of(" ") + 1);

  std::vector<Team*> teams = this->engine->getTeam();
  for (int i = 0; i < static_cast<int>(teams.size()); i++)
    {
      std::vector<Vivi*> players = teams[i]->getPlayer();
      for (int j = 0; j < static_cast<int>(players.size()); j++)
	{
	  for (std::list<std::pair<int, glm::vec3> >::iterator it = _list.begin(); it != _list.end(); ++it)
	    {
	      if ((*it).second.x == std::stoi(x) && (*it).second.z == std::stoi(y)
		  && players[j]->getId() == (*it).first)
		{
		  players[j]->wait();
		  _list.erase(it);
		  return;
		}
	    }
	}
    }
}

void	Exec::pgt(std::string const & arg)
{
  std::vector<int>	v = Parser<int>::StringToVector(arg);
  std::vector<Team*> teams = this->engine->getTeam();

  for (int i = 0; i < static_cast<int>(teams.size()); i++)
    {
      std::vector<Vivi*> players = teams[i]->getPlayer();
      for (int j = 0; j < static_cast<int>(players.size()); j++)
	{
	  if (players[j]->getId() == v[0])
	    {
	      players[j]->pick();
	      return;
	    }
	}
    }
}

void	Exec::pdr(std::string const & arg)
{
  std::vector<int>	v = Parser<int>::StringToVector(arg);
  std::vector<Team*> teams = this->engine->getTeam();

  for (int i = 0; i < static_cast<int>(teams.size()); i++)
    {
      std::vector<Vivi*> players = teams[i]->getPlayer();
      for (int j = 0; j < static_cast<int>(players.size()); j++)
	{
	  if (players[j]->getId() == v[0])
	    {
	      players[j]->pick();
	      return;
	    }
	}
    }
}

void	Exec::edi(std::string const & arg)
{
  std::vector<Team*> teams = this->engine->getTeam();

  for (int i = 0; i < static_cast<int>(teams.size()); i++)
    {
      std::vector<Egg*> players = teams[i]->getEgg();
      for (int j = 0; j < static_cast<int>(players.size()); j++)
	{
	  if (players[j]->getId() == std::stoi(arg))
	    {
	      teams[i]->deleteEgg(j);
	      return;
	    }
	}
    }
}

void	Exec::eht(std::string const & arg)
{
  std::vector<Team*> teams = this->engine->getTeam();

  for (int i = 0; i < static_cast<int>(teams.size()); i++)
    {
      std::vector<Egg*> players = teams[i]->getEgg();
      for (int j = 0; j < static_cast<int>(players.size()); j++)
	{
	  if (players[j]->getId() == std::stoi(arg))
	    {
	      teams[i]->deleteEgg(j);
	      return;
	    }
	}
    }
}

void	Exec::ebo(std::string const & arg)
{
  std::vector<Team*> teams = this->engine->getTeam();

  for (int i = 0; i < static_cast<int>(teams.size()); i++)
    {
      std::vector<Egg*> players = teams[i]->getEgg();
      for (int j = 0; j < static_cast<int>(players.size()); j++)
	{
	  if (players[j]->getId() == std::stoi(arg))
	    {
	      teams[i]->deleteEgg(j);
	      return;
	    }
	}
    }
}
