//
// bomb_gl_inputman.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri May 13 12:44:22 2011 pierre le
// Last update Mon May 16 12:41:04 2011 nicolas laille
//

#ifndef		__BOMB_GL_INPUTMAN_HH__
# define	__BOMB_GL_INPUTMAN_HH__

# include	"Input.hpp"

namespace	GlGraphics
{
  typedef gdl::Keys::Key	glKey;

  enum		eInputKey
    {
      K_NONE,
      K_UP,
      K_DOWN,
      K_LEFT,
      K_RIGHT,
      K_DROP
    };

  class		GlInputs
  {
  public:
    GlInputs(void);

    eInputKey		getKeys(void) const;
    void		setupKeys(glKey keyUp,
				  glKey keyDown,
				  glKey keyLeft,
				  glKey keyRight,
				  glKey keyDrop);

    void		bindEngine(gdl::Input *);

  private:
    gdl::Input		*_input;

    gdl::Keys::Key	_keyUp;
    gdl::Keys::Key	_keyDown;
    gdl::Keys::Key	_keyLeft;
    gdl::Keys::Key	_keyRight;
    gdl::Keys::Key	_keyDrop;
  };
}


#endif		// !__BOMB_GL_INPUTMAN_HH__
