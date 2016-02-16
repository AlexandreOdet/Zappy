#include "texture.hh"

std::map<std::string, GLuint>	GTexture;

GLuint		texture::id = 0;
SDL_Color	texture::_color = {255, 255, 255, 255};
TTF_Font	*texture::_font = NULL;

texture::texture()
{

  if (TTF_Init() == -1)
    throw MenuError(TTF_GetError());
  if (!(_font = TTF_OpenFont("src_graphic/res/DejaVuSans.ttf", 50)))
    throw ResError(TTF_GetError());

  addImage(IMG_Load("src_graphic/res/hud.png"), "HUD");
  int i = 0;
  std::string s;
  while (i < 300)
    {
      s = std::to_string(i);
      TextTotexture(s);
      i += 1;
    }
  TextTotexture("lvl:");
  TextTotexture("time:");

  addImage(IMG_Load("src_graphic/res/ground/Grass.png"), "GROUND");
  addImage(IMG_Load("src_graphic/res/ground/Gcorner.png"), "GCORNER");
  addImage(IMG_Load("src_graphic/res/ground/GEdge.png"), "GEDGE");
  addImage(IMG_Load("src_graphic/res/bg2.jpg"), "BG");
  addImage(IMG_Load("src_graphic/res/broadcast.png"), "BROADCAST");
  addImage(IMG_Load("src_graphic/res/lvlup.png"), "LVLUP");

  addImage(IMG_Load("src_graphic/res/gemme/food.png"), "food");
  addImage(IMG_Load("src_graphic/res/gemme/cyan.png"), "linemate");
  addImage(IMG_Load("src_graphic/res/gemme/green.png"), "deraumere");
  addImage(IMG_Load("src_graphic/res/gemme/lopez.png"), "sibur");
  addImage(IMG_Load("src_graphic/res/gemme/purple.png"), "Mendiane");
  addImage(IMG_Load("src_graphic/res/gemme/red.png"), "Phiras");
  addImage(IMG_Load("src_graphic/res/gemme/yellow.png"), "Thystame");
}

texture::~texture()
{
}

GLuint	texture::addImage(SDL_Surface *Surface, std::string const &name)
{
  if (Surface)
    {
      int Mode = GL_RGB;

      glGenTextures(1, &id);
      glBindTexture(GL_TEXTURE_2D, id);

      if (Surface->format->BytesPerPixel == 4)
	Mode = GL_RGBA;

      glTexImage2D(GL_TEXTURE_2D, 0, Mode, Surface->w, Surface->h, 0,
		   Mode, GL_UNSIGNED_BYTE, Surface->pixels);
      glRotatef(90, 1, 0, 0);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      GTexture[name] = id;
    }
  return id++;
}

GLuint	texture::TextTotexture(std::string const &text)
{
  return addImage(TTF_RenderText_Blended(_font, text.c_str(), _color), text);
}
