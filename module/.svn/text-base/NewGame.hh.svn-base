//
// NewGame.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/module
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Sat Jun  4 15:51:47 2011 nicolas laille
// Last update Sat Jun  4 19:42:59 2011 nicolas laille
//

#ifndef		__NEWGAME_HH__
# define	__NEWGAME_HH__

#include	<string>

#include	"bomb_gl2d_textboxitem.hh"

class		sendData;

class		NewGame
{
public :
  NewGame(void);
  ~NewGame(void);
  
  void		incMapSize(void);
  void		decMapSize(void);
  void		incNbPlayer(void);
  void		decNbPlayer(void);
  void		setVersus(void);
  void		launch(void);
  void		getData(sendData&);
  bool		isEnd(void) const;

  std::string const &	getMapSize(void);
  std::string const &	getNbPlayer(void);
  std::string const &	getVersus(void);

  void		setTextMap(GlGraphics::TextBoxItem*);
  void		setTextPlayer(GlGraphics::TextBoxItem*);
  void		setTextVersus(GlGraphics::TextBoxItem*);
private :
  size_t	_sizeMap;
  size_t	_nbPlayer;
  bool		_versus;
  std::string	_tmp;
  bool		_end;

  GlGraphics::TextBoxItem*	_textMap;
  GlGraphics::TextBoxItem*	_textPlayer;
  GlGraphics::TextBoxItem*	_textVersus;
};

#endif		/* __NEWGAME_HH__ */
