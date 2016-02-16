#include "Egg.hh"

Egg::Egg(int id, int Pid, glm::vec3 const &pos)
  : _position(pos), _Pid(Pid), _id(id)
{
  this->_rotation = glm::vec3(0, 0, 0);
  this->_scale = glm::vec3(0.001, 0.001, 0.001);

  this->_model = new gdl::Model;
  if (!this->_model->load("./src_graphic/res/model/egg/untitled.fbx"))
    throw ResError("./src_graphic/res/model/egg/untitled.fbx");

  this->_model->setCurrentAnim(1);
}

Egg::~Egg()
{
  delete _model;
}

int		Egg::getId() const
{
  return _id;
}

glm::mat4	Egg::getTransformation() const
{
  glm::mat4   transform(1);

  transform = glm::translate(transform, glm::vec3(_position.x, _position.y - 0.5, _position.z));
  transform = glm::rotate(transform, this->_rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, this->_rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, this->_rotation.z, glm::vec3(0, 0, 1));
  transform = glm::scale(transform, this->_scale);
  return (transform);
}

void		Egg::update(__attribute__((unused))gdl::Clock const &clock,
			    __attribute__((unused))gdl::Input &input)
{
}

void		Egg::draw(gdl::AShader &s, glm::mat4 const &t, double dT)
{
  this->_model->draw(s, t, dT);
}
