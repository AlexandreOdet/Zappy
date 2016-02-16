#include "HUD.hh"
#include "Texture.hh"


HUD::HUD()
{
  this->_obj = this->addPlan(0.25, 2, glm::vec3(0, -0.9, 0), "HUD");
  this->_num.push_back(this->addPlan(0.04, 0.04, glm::vec3(-0.85, -0.9, -1), "0"));
  this->_num.push_back(this->addPlan(0.04, 0.04, glm::vec3(-0.70, -0.9, -1), "0"));
  this->_num.push_back(this->addPlan(0.04, 0.04, glm::vec3(-0.53, -0.9, -1), "0"));
  this->_num.push_back(this->addPlan(0.04, 0.04, glm::vec3(-0.36, -0.9, -1), "0"));
  this->_num.push_back(this->addPlan(0.04, 0.04, glm::vec3(-0.20, -0.9, -1), "0"));
  this->_num.push_back(this->addPlan(0.04, 0.04, glm::vec3(-0.03, -0.9, -1), "0"));
  this->_num.push_back(this->addPlan(0.04, 0.04, glm::vec3(0.13, -0.9, -1), "0"));

  this->_num.push_back(this->addPlan(0.04, 0.1, glm::vec3(0.48, -0.92, -1), "lvl:"));
  this->_num.push_back(this->addPlan(0.04, 0.04, glm::vec3(0.57, -0.92, -1), "1"));

  this->_num.push_back(this->addPlan(0.1, 0.4, glm::vec3(-0.8, 0.95, -1), "time:"));
  this->_num.push_back(this->addPlan(0.1, 0.1, glm::vec3(-0.5, 0.95, -1), "1"));

  this->_draw = false;
  this->_p = false;

  this->r = new Ressource();
}

HUD::~HUD()
{
}

void	HUD::addTeam(std::string const &t)
{
  static float	y = 0.8;
  std::string	tmp("team: " + t);

  texture::TextTotexture(tmp);
  _team.push_back(this->addPlan(0.1, 0.4, glm::vec3(-0.8, y, -1), tmp));
  y -= 0.1;
}

void	HUD::updatetime(int t)
{
  _num[10]->changeTexture(std::to_string(t));
}

void	HUD::setDraw(bool const lol)
{
  this->_draw = lol;
}

void	HUD::update(__attribute__((unused))gdl::Clock const &c, __attribute__((unused))gdl::Input const &i, Case const *cas)
{
  this->_draw = true;
  this->_p = false;
  Ressource *tmp = cas->getRessource();

  _num[0]->changeTexture(std::to_string(tmp->getFood()));
  _num[1]->changeTexture(std::to_string(tmp->getLin()));
  _num[2]->changeTexture(std::to_string(tmp->getDer()));
  _num[3]->changeTexture(std::to_string(tmp->getSib()));
  _num[4]->changeTexture(std::to_string(tmp->getMen()));
  _num[5]->changeTexture(std::to_string(tmp->getPhi()));
  _num[6]->changeTexture(std::to_string(tmp->getThy()));
}

void	HUD::update(__attribute__((unused))gdl::Clock const &c, __attribute__((unused))gdl::Input const &i, Vivi const *v)
{
  this->_p = true;
  this->_draw = true;
  Ressource *tmp = v->getRessource();

  _num[0]->changeTexture(std::to_string(tmp->getFood()));
  _num[1]->changeTexture(std::to_string(tmp->getLin()));
  _num[2]->changeTexture(std::to_string(tmp->getDer()));
  _num[3]->changeTexture(std::to_string(tmp->getSib()));
  _num[4]->changeTexture(std::to_string(tmp->getMen()));
  _num[5]->changeTexture(std::to_string(tmp->getPhi()));
  _num[6]->changeTexture(std::to_string(tmp->getThy()));
  _num[8]->changeTexture(std::to_string(v->getLvl()));
}

void	HUD::update()
{
  this->_p = false;
  this->_draw = false;
}

void	HUD::draw(gdl::AShader &s, gdl::Clock  &c)
{
  _num[9]->draw(s, c);
  _num[10]->draw(s, c);
  if (this->_team.size() > 0)
    for (int i = 0; i < static_cast<int>(_team.size()); i++)
      _team[i]->draw(s, c);
  if (this->_draw == true)
    {
      this->_obj->draw(s, c);
      int i = 0;
      while (i < 7)
	{
	  this->_num[i]->draw(s, c);
	  i++;
	}
      if (this->_p == true)
	{
	  _num[7]->draw(s, c);
	  _num[8]->draw(s, c);
	}
    }
}

Plan    *HUD::addPlan(float x, float y,  glm::vec3 const &v, std::string const &name) const
{
  Plan  *tmp = new Plan(x, y, v, name);

  tmp->rotate(glm::vec3(0, 0, -1), 90);
  tmp->rotate(glm::vec3(0, 1, 0), 90);
  return tmp;
}
