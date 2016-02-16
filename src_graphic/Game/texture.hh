#ifndef	TEXTURE_HH
#define	TEXTURE_HH

#include <iostream>
#include <sstream>
#include <string>
#include <Model.hh>
#include <texture.hh>
#include <SdlContext.hh>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <map>
#include <vector>
#include "Exception.hpp"

extern std::map<std::string, GLuint>	GTexture;

class	texture
{
public:
  texture();
  ~texture();

  static GLuint		id;
  static SDL_Color	_color;
  static TTF_Font	*_font;

public:
  static GLuint	addImage(SDL_Surface *, std::string const&);
  static GLuint	TextTotexture(std::string const &);
};

#endif
