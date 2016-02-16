#ifndef	SOUND_HH
#define	SOUND_HH

#include <iostream>
#include <string>
#include <fmod.h>
#include <map>
#include "Exception.hpp"

extern std::map<std::string, FMOD_SOUND*>	GSound;

class	Sound
{
public:
  Sound();
 ~Sound();

  static void	play(std::string const &music);
  static void	stop(std::string const &music);

private:
  FMOD_SOUND	*game;
  FMOD_SOUND	*broadcast;

  static FMOD_SYSTEM	*system;
  FMOD_CHANNEL		*channel;
  FMOD_RESULT		resultat;
};

extern  Sound   *son;

#endif
