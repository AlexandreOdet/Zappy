#ifndef	PARSER_HH
#define	PARSER_HH

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template<typename T>
class	Parser
{
public:
  Parser() {};
  ~Parser() {};

  static std::vector<T>	StringToVector(std::string const &list)
  {
    std::stringstream	stream(list);
    std::vector<T>	values;
    int			i = 0;

    while (1)
      {
	T tmp;
	stream >> tmp;
	if (!stream)
	  break;
	values.push_back(tmp);
	i++;
      }
    return values;
  }
};

#endif
