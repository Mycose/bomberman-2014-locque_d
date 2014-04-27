//
// Bombe.hh for  in /home/laille_n//projet/tek2/cpp/bomberman
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Fri Apr 29 13:52:26 2011 nicolas laille
// Last update Sat Jun  4 15:31:46 2011 nicolas laille
//

#ifndef		__BOMBE_HH__
# define	__BOMBE_HH__

#include	"Map.hh"
#include	"ABombe.hh"
#include	"ACharacter.hh"

class		ABomberman;

class		Bombe : public ABombe
{
public :
  Bombe(ABomberman&);
  Bombe(const Bombe&);
  virtual ~Bombe();

  virtual void	setPlant(Map&);
  virtual void	doPlant(int, int, int, Map&);
  virtual void	doExplose(Map&);
  virtual void	checkBombe(const gdl::GameClock&, Map&);
  virtual void	explosed(Map&);

  virtual int	explose(Map&);
  virtual BombeContainer*	container();

  virtual ABlock*	copy(int, int, Map&) const;
  virtual std::string	Serialize(const std::string& name);
  virtual void		Deserialize(const std::string& doc);

private :
  Bombe&	operator=(const Bombe&);
};

#endif		/* __BOMBE_HH__ */
