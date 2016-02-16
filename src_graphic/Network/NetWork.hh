//
// NetWork.hh for NetWork in /home/odet_a/PSU_2014_zappy/src_graphic/Network
//
// Made by Alexandre Odet
// Login   <odet_a@epitech.net>
//
// Started on  Fri Jun 19 15:51:03 2015 Alexandre Odet
// Last update Sun Jul  5 20:42:07 2015 Alexandre Odet
//

#include <sys/types.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#include <exception>
#include <map>
#include <iostream>

#include "RingBuff.hh"
#include "Exec.hh"

class	NetWorkError : public std::exception
{
private:
  std::string	msg;
public:
  NetWorkError(std::string const & str = "") throw() : msg(str) {}
  virtual const char *what() const throw()
  {
    return msg.c_str();
  }
  virtual ~NetWorkError() throw() {}
};

class	NetWork
{
private:
  int			_fd;
  bool			sgt;
  fd_set		_rdFd;
  fd_set		_wrFd;
  Exec			*_graphic;
  bool			print;
  RingBuff		*_rdBuff;
  static RingBuff	*_wrBuff;
  struct timeval	_tv;
  static NetWork	*_netWork;
  bool			bct;



  typedef	void (Exec::*fct)(const std::string &);
  std::map<std::string, fct> handleCommand;

private:
  struct protoent	*getProto(const std::string &) const;
  int			createSock(const struct protoent *) const;
  void			tryConnect(const int, const struct sockaddr_in) const;
  int			selectPart();
  int			setFd();
  void			execInstr(const std::string &);
  const std::string	getInstruction() const;
  void			Create(const std::string &);
  void			initInstr();

public:
  NetWork(const std::string &, const int);
  ~NetWork();

  static	void sendToServer(const std::string &);

  int    loop();
};

void	sighandler(int);
