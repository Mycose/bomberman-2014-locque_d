//
// Endgame.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/module
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Sat Jun  4 17:14:42 2011 nicolas laille
// Last update Sat Jun  4 18:06:33 2011 nicolas laille
//

#ifndef		__ENDGAME_HH__
# define	__ENDGAME_HH__

#include	"bomb_gl_object.hh"
#include	"bomb_gl_camera.hh"

class		EndGame
{
public :
  EndGame(std::string name);
  ~EndGame(void);

  void		initialize(void);
  void		update(const gdl::GameClock &,
		       gdl::Input &);
  void		draw(GlGraphics::GlViewField);
  void		unload(void);
private :
  GlGraphics::GlObject*	picture;
};

#endif		/* __ENDGAME_HH__*/
