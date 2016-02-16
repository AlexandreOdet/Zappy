#include "Sound.hh"

std::map<std::string, FMOD_SOUND*>	GSound;
FMOD_SYSTEM				*Sound::system;

Sound::Sound()
{
  FMOD_System_Create(&system);
  FMOD_System_Init(system, 2, FMOD_INIT_NORMAL, NULL);

  resultat = FMOD_System_CreateSound(system, "src_graphic/res/sound/bg.mp3", FMOD_LOOP_NORMAL | FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &game);
  if (resultat != FMOD_OK)
    throw ResError("src_graphic/res/sound/bg.mp3");

  resultat = FMOD_System_CreateSound(system, "src_graphic/res/sound/pori_chocobo.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &broadcast);
  if (resultat != FMOD_OK)
    throw ResError("src_graphic/res/sound/pori_chocobo.mp3");

  GSound["game"] = game;
  GSound["broadcast"] = broadcast;

  FMOD_System_GetChannel(system, 9, &channel);
}

Sound::~Sound()
{
  FMOD_System_Close(system);
  FMOD_System_Release(system);
}

void	Sound::play(std::string const &music)
{
  FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, GSound[music], 0, NULL);
}

void	Sound::stop(std::string const &music)
{
  FMOD_Sound_Release(GSound[music]);
}

