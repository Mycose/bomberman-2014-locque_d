//
// LoadGame.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/module
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Thu Jun  2 14:52:13 2011 nicolas laille
// Last update Sun Jun  5 12:45:29 2011 nicolas laille
//

#ifndef		__LOADGAME_HH__
# define	__LOADGAME_HH__

#include	<list>
#include	<string>

class		LoadGame
{
public :
  LoadGame(void);
  ~LoadGame(void);

  std::string const&	getNextSave();
  bool			End(void) const;
  bool			isEnd(void) const;

  void			buttonCall(const std::string &);
  std::string const &	getSave(void) const;

private :
  void			readDir(std::string const & directory);

  std::list<std::string>	_files;
  std::list<std::string>::iterator	_pos;
  std::string	tmp;

  std::string	_save;
  bool		_end;
};

#endif		/* __LOADGAME_HH__ */
