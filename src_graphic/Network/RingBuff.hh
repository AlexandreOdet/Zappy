//
// RingBuff.hh for RingBuff in /home/odet_a/PSU_2014_zappy/src_graphic/Network
// 
// Made by Alexandre Odet
// Login   <odet_a@epitech.net>
// 
// Started on  Fri Jun 19 15:38:58 2015 Alexandre Odet
// Last update Tue Jun 23 15:33:51 2015 Alexandre Odet
//

#ifndef RINGBUFF_H
#define RINGBUFF_H

#define MAX_INSTRUCTION (1000)

#include <string>

class	RingBuff
{
private:
  int		_size;
  std::string	_buff;
  int		_nbInstr;
public:
  RingBuff();
  ~RingBuff();

  int	getSize() const;
  const std::string	getBuff() const;

  void	removeFromBuff(const int);
  void	append(const char *, const int);

};

#endif /* RINGBUFF_H */

