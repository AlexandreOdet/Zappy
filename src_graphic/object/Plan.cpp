#include "Plan.hh"
#include "MyGame.hh"

gdl::Geometry	*Plan::_geometry = new gdl::Geometry;
bool		Plan::is_init = false;

Plan::Plan(float const size, glm::vec3 const &pos, std::string const &texture)
{
  this->_speed = 20.0f;
  setPosition(pos);
  setRotation(glm::vec3(0, 0, 0));
  setScale(glm::vec3(size, size, size));
  this->_texture = GTexture[texture];
  initialize();
}

Plan::Plan(float x, float y,  glm::vec3 const &pos, std::string const &texture)
{
  this->_speed = 20.0f;
  setPosition(pos);
  setRotation(glm::vec3(0, 0, 0));
  setScale(glm::vec3(x, 1, y));
  this->_texture = GTexture[texture];
  initialize();
}

void	Plan::initialize()
{
  if (!is_init)
    {
      this->_geometry->pushVertex(glm::vec3(-0.5, 0, 0.5));
      this->_geometry->pushVertex(glm::vec3(0.5, 0, 0.5));
      this->_geometry->pushVertex(glm::vec3(0.5, 0, -0.5));
      this->_geometry->pushVertex(glm::vec3(-0.5, 0, -0.5));
      setUV();

      this->_geometry->build();
      is_init = true;
    }
}

void	Plan::setUV()
{
  this->_geometry->pushUv(glm::vec2(1.0f, 0.0f));
  this->_geometry->pushUv(glm::vec2(1.0f, 1.0f));
  this->_geometry->pushUv(glm::vec2(0.0f, 1.0f));
  this->_geometry->pushUv(glm::vec2(0.0f, 0.0f));
}

void	Plan::changeTexture(std::string const &texture)
{
  _texture = GTexture[texture];
}

void	Plan::draw(gdl::AShader &shader, __attribute__((unused))gdl::Clock const &c)
{
  glBindTexture(GL_TEXTURE_2D, _texture);
  this->_geometry->draw(shader, getTransformation(), GL_QUADS);
}
