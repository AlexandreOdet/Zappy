#pragma once

#include <list>
#include <Clock.hh>
#include <glm/gtc/type_precision.hpp>

namespace	gdl
{
  // Handle the inputs
  class Input
  {
  private:
    std::list<int>	_inputs;
    std::list<int>	_keyInputs;
    glm::ivec2		_mousePosition;
    glm::ivec2		_mouseDelta;
    glm::ivec2		_mouseWheelDelta;
    double		_time;

  public:
    Input() : _time(0) {};
    virtual ~Input();

    // Do not use this functions, they are called by the context to update the inputs
    void 				clearInputs();
    void 				addInput(int input);
    void 				addKeyInput(int input);
    void 				removeKeyInput(int input);
    void 				setMousePosition(glm::ivec2 const &pos, glm::ivec2 const &rel);
    void				setMouseWheel(glm::ivec2 const &delta);

    // Returns the mouse position
    glm::ivec2 const  	&getMousePosition();
    // Returns the mouse movement since the last update
    glm::ivec2 const  	&getMouseDelta();
    // Returns the mouse wheel movement since the last update
    glm::ivec2 const  	&getMouseWheel();

    // Returns true if the input passed as parameter has been detected
    bool 				getInput(int input, bool handled = false);
    // Returns true if the Key passed as parameter is currently pressed
    bool 				getKey(int input, bool handled = false);
    // Returns true if the key passed as parameter as been pressed during the last frame
    bool				getKeyDown(int input, bool handled = false);
    // Returns true if the key passed as parameter as been released during the last frame
    bool				getKeyUp(int input, bool handled = false);

    // Returns false if the key passed as parameter as been pressed the last 0.2s
    bool				getKeyPressed(int input, Clock const &c)
    {
      if (getKey(input) && _time > 0.5)
	{
	  _time = 0;
	  return true;
	}
      _time += c.getElapsed();
      return false;
    }

  };
}
