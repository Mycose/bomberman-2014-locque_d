//
// sendData.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/menu
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Sat Jun  4 12:22:29 2011 nicolas laille
// Last update Sun Jun  5 12:41:30 2011 nicolas laille
//

#ifndef		__SENDATA_HH__
# define	__SENDATA_HH__

#include	"bomb_gl_engine.hh"
#include	"GameMenu.hh"

class		sendData
{
public :
  sendData();
  ~sendData();

  unsigned int	getSizeMap(void) const;
  unsigned int	getNbPlayer(void) const;
  bool		getTwoPlayer(void) const;
  std::string const&	getSaveName(void) const;  
  int		getScore(void) const;
  eModule	getModuleLoad(void) const;
  GameMenu::eMenuFrameId	getMenuLoad(void) const;
  std::string const&	getPlayerScore(void) const;

  void		setSizeMap(unsigned int);
  void		setNbPlayer(unsigned int);
  void		setTwoPlayer(bool);

  void		setSaveName(std::string const &);
  void		setScore(unsigned int);
  void		setLoad(eModule);
  void		setLoadMenu(GameMenu::eMenuFrameId);
  void		setPlayerScore(int);
  
  void		reset(void);

private :
  unsigned int	sizeMap;
  unsigned int	nbPlayer;
  bool		twoPlayer;
  std::string	saveName;
  unsigned int	score;
  std::string	player;
  eModule	load;
  GameMenu::eMenuFrameId	loadmenu;
};

#endif		/* __SENDATA_HH__ */
