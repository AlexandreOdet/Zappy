
#include <Clock.hh>
#include <Input.hh>
#include <SdlContext.hh>
#include <Geometry.hh>
#include <Texture.hh>
#include <BasicShader.hh>
#include <Model.hh>
#include <OpenGL.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <iostream>
#include <fmod.h>

#include "MyGame.hh"
#include "Sound.hh"
#include "NetWork.hh"

int	main(int argc, char **argv)
{
  if (argc >= 3)
    {
      try
	{
	  NetWork *n = new NetWork(argv[1], std::atoi(argv[2]));
	  n->loop();
	  delete n;
	}
      catch (GameError const &e)
	{
	  std::cerr << "Game Error : " << e.what() << std::endl;
	}
      catch (ResError const &e)
	{
	  std::cerr << "Error while loading ressource : " << e.what() << std::endl;
	}
      catch (NetWorkError const &e)
	{
	  std::cerr << e.what() << std::endl;
	}
    }
  else
    {
      std::cerr << "Usage : ./graphic [HOST] [PORT]" << std::endl;
      return -1;
    }
  return EXIT_SUCCESS;
}
