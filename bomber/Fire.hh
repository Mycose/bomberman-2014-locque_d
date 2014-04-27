//
// Fire.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Thu May 12 15:47:29 2011 nicolas laille
// Last update Sat Jun  4 15:31:28 2011 nicolas laille
//

#ifndef		__FIRE_HH__
# define	__FIRE_HH__

#include	"Map.hh"
#include	"ABlock.hh"
#include	"bomb_gl_drawableobjs.hh"

class		ABomberman;

class		Fire : public ABlock
{
public :
  Fire(ABomberman& bomber, int defX, int defY, int x = 0, int y = 0);
  Fire(const Fire&);
  virtual ~Fire(void);

  void		setOrig(int, int, int, Map&);
  void		explose(int puiss, Map& map);
  void		deleteFire(Map& map);
  void		setFire(Map& map);

  virtual void	operator()(ACharacter&, Map&);
  virtual void	operator()(ABomberman&, Map&);

  Fire&		operator=(const Fire&);

  virtual ABlock*	copy(int, int, Map&) const;
  virtual std::string	Serialize(const std::string& name);
  virtual void		Deserialize(const std::string& doc);

private :
  ABomberman&	bomber;
  int		origX;
  int		origY;
  int		maxX;
  int		maxY;
  int		defX;
  int		defY;
  int		puiss;
};

#endif		/* ! __FIRE_HH__ */
