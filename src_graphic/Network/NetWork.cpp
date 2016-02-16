//
// NetWork.cpp for NetWork in /home/odet_a/PSU_2014_zappy/src_graphic/Network
//
// Made by Alexandre Odet
// Login   <odet_a@epitech.net>
//
// Started on  Fri Jun 19 15:53:30 2015 Alexandre Odet
// Last update Sun Jul  5 20:42:00 2015 Alexandre Odet
//

#include "NetWork.hh"
#include "MyGame.hh"

RingBuff	*NetWork::_wrBuff = NULL;
static int	g_continue = 1;

NetWork::NetWork(const std::string & ip, const int port)
{
  if (signal(SIGINT, sighandler) == SIG_ERR)
    throw NetWorkError("Cannot handle signal");

  const struct protoent	*p = this->getProto("TCP");
  int			fd = this->createSock(p);
  struct sockaddr_in	s_in;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(ip.c_str());

  _graphic = new Exec();

  this->print = false;
  this->sgt = false;
  this->bct = false;

  this->tryConnect(fd, s_in);
  this->_fd = fd;
  this->_wrBuff = new RingBuff();
  this->_rdBuff = new RingBuff();
  initInstr();
}

NetWork::~NetWork()
{
  close(this->_fd);
  delete this->_graphic;
}

void		sighandler(__attribute__((unused))int s)
{
  g_continue = 0;
}

struct protoent	*NetWork::getProto(const std::string &proto) const
{
  struct	protoent *pe = getprotobyname(proto.c_str());
  if (pe == NULL)
    throw NetWorkError("Cannot get the proto");
  return pe;
}

int		NetWork::createSock(const struct protoent *p) const
{
  int			fd;

  fd = socket(AF_INET, SOCK_STREAM, p->p_proto);
  if (fd == -1)
    throw NetWorkError("Cannot create socket");
  return fd;
}

void		NetWork::tryConnect(const int fd, const struct sockaddr_in s_in) const
{
  int	ret;

  ret = connect(fd, (struct sockaddr *)&s_in, sizeof(s_in));
  if (ret == -1)
    {
      close(fd);
      throw NetWorkError("Cannot connect");
    }
}

const std::string	NetWork::getInstruction() const
{
  std::string cmd = this->_rdBuff->getBuff().substr(0, this->_rdBuff->getBuff().find_first_of("\n"));
  return cmd;
}

int		NetWork::loop()
{
  std::string	cmd = "";

  write(_fd, "GRAPHIC\n", strlen("GRAPHIC\n"));
  while (g_continue == 1)
    {
      if (this->selectPart() == -1)
	g_continue = 0;
      if ((cmd = this->getInstruction()) != "")
	{
	  this->execInstr(cmd);
	  cmd.clear();
	}
      if (this->print == true)
	{
	  if (_graphic->getEngine()->update() == true)
	    _graphic->getEngine()->draw();
	  else
	    return (0);
	}
      cmd.clear();
    }
  return (0);
}

void		NetWork::initInstr()
{
  handleCommand["sgt"] = &Exec::sgt;
  handleCommand["bct"] = &Exec::bct;
  handleCommand["tna"] = &Exec::tna;
  handleCommand["pnw"] = &Exec::pnw;
  handleCommand["pdi"] = &Exec::pdi;
  handleCommand["pic"] = &Exec::pic;
  handleCommand["seg"] = &Exec::seg;
  handleCommand["smg"] = &Exec::smg;
  handleCommand["suc"] = &Exec::suc;
  handleCommand["ppo"] = &Exec::ppo;
  handleCommand["pie"] = &Exec::pie;
  handleCommand["enw"] = &Exec::enw;
  handleCommand["pin"] = &Exec::pin;
  handleCommand["plv"] = &Exec::plv;
  handleCommand["pex"] = &Exec::pex;
  handleCommand["pgt"] = &Exec::pgt;
  handleCommand["pdr"] = &Exec::pdr;
  handleCommand["edi"] = &Exec::edi;
  handleCommand["eht"] = &Exec::eht;
  handleCommand["ebo"] = &Exec::ebo;
  handleCommand["pbc"] = &Exec::pbc;
}

void		NetWork::execInstr(const std::string & cmd)
{
  std::string cmdToServer, args, tmp;
  void	(Exec::*ptr)(const std::string &);

  cmdToServer.clear();
  args.clear();
  tmp = cmd;

  cmdToServer = tmp.substr(0, tmp.find_first_of(" "));
  tmp.erase(0, tmp.find_first_of(" ") + 1);
  args = tmp;

  if (cmdToServer == "msz")
    {
      std::vector<int>	tmp = Parser<int>::StringToVector(args);
      this->_graphic->setEngine(tmp[0], tmp[1]);
      this->_graphic->getEngine()->initialize();
      print = true;

    }

  if (cmdToServer == "bct")
    bct = true;
  if (print && sgt && !bct)
    NetWork::sendToServer("mct\n");
  if (cmdToServer == "sgt")
    sgt = true;
  if (!print && cmdToServer != "BIENVENUE")
    NetWork::sendToServer("msz\n");
  if (!sgt && print)
    NetWork::sendToServer("sgt\n");
  if ((ptr = handleCommand[cmdToServer]) && print == true)
    (_graphic->*ptr)(args);
  this->_rdBuff->removeFromBuff(cmd.size() + 1);
  if (cmdToServer == "seg")
    print = true;
}

void		NetWork::sendToServer(const std::string & message)
{
  _wrBuff->append(message.c_str(), message.length());
}

int		NetWork::setFd()
{
  int		ret;

  ret = this->_fd;
  FD_ZERO(&this->_rdFd);
  FD_ZERO(&this->_wrFd);
  FD_SET(this->_fd, &this->_rdFd);
  if (_wrBuff->getSize() > 0)
    FD_SET(this->_fd, &this->_wrFd);
  this->_tv.tv_sec = 0;
  this->_tv.tv_usec = 10000;
  return ret;
}

int		NetWork::selectPart()
{
  char			buff[512];
  int			r;

  r = this->setFd();
  bzero(buff, 512);
  if (select(r + 1, &this->_rdFd, &this->_wrFd, NULL, &(this->_tv)) == -1)
    return (-1);
  if (FD_ISSET(this->_fd, &this->_rdFd))
    {
      r = read(this->_fd, buff, sizeof(buff));
      if (r <= 0 && this->_rdBuff->getSize() <= 0)
	return -1;
      else
	this->_rdBuff->append(buff, r);
    }
  if (FD_ISSET(this->_fd, &this->_wrFd))
    {
      r = write(this->_fd, this->_wrBuff->getBuff().c_str(), this->_wrBuff->getSize());
      if (r == -1)
	return -1;
      else
	this->_wrBuff->removeFromBuff(r);
    }
  return 1;
}
