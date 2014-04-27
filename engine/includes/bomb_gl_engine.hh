//
// bomb_gl_engine.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/tp
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Wed Apr 27 12:13:31 2011 pierre le
// Last update Sun Jun  5 10:32:15 2011 nicolas laille
//

#ifndef		__BOMB_GL_ENGINE_HH__
# define	__BOMB_GL_ENGINE_HH__

# include	<list>
# include	<map>

# include	<Game.hpp>

# include	"IModule.hh"

class		GlEngine : public gdl::Game
{
public:
  // Ctor/dtor
  explicit GlEngine(const std::string &winTitle);
  ~GlEngine();

  // GDL-GL specific functions
  virtual void		initialize(void);
  virtual void		update(void);
  virtual void		draw(void);
  virtual void		unload(void);

  void			loadModule(eModule, sendData&);

  // Internal public properties
  static const size_t	_winX = 1280;
  static const size_t	_winY = 800;

private:
  void			addModule(eModule, IModule *);

  // Internal properties
  std::string			_winTitle;

  std::map<eModule, IModule*>	_modules;

  IModule*			current;
};

#endif		// !__BOMB_GL_ENGINE_HH__
