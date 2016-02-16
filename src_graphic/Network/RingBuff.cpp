//
// RingBuff.cpp for RingBuff in /home/odet_a/PSU_2014_zappy/src_graphic/Network
// 
// Made by Alexandre Odet
// Login   <odet_a@epitech.net>
// 
// Started on  Fri Jun 19 15:38:31 2015 Alexandre Odet
// Last update Sun Jul  5 15:29:45 2015 Alexandre Odet
//

#include <iostream>
#include "RingBuff.hh"

RingBuff::RingBuff()
{
  this->_size = 0;
  this->_buff = "";
  this->_nbInstr = 0;
}

RingBuff::~RingBuff()
{}

int	RingBuff::getSize() const
{
  return this->_size;
}

void	RingBuff::removeFromBuff(const int len)
{
  int	i = 0, c = 0;

  this->_buff.erase(0, len);
  this->_size = this->_buff.length();
  while (i++ < this->_size)
    {
      if (_buff[(i + 1)] == '\n')
  	c++;
    }
  this->_nbInstr = c;
}

const std::string	RingBuff::getBuff() const
{
  return this->_buff;
}

void	RingBuff::append(const char *cmd, const int len)
{
  int i = 0, c = 0;
  std::string t(cmd, len);

  this->_buff += t;
  this->_size += len;
  while (i < this->_size)
    {
      if (_buff[i + 1] == '\n')
	{
	  if (c < MAX_INSTRUCTION)
	    c++;
	  else
	    this->_size = i;
	}
      i++;
    }
  this->_nbInstr = c;
}
