//
// BomberLoad.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Sat Jun  4 14:03:12 2011 nicolas laille
// Last update Sun Jun  5 11:37:46 2011 nicolas laille
//

#ifndef		__BOMBERLOAD_HH__
# define	__BOMBERLOAD_HH__

#include	<list>

#include	"bomb_gl_object.hh"
#include	"IBomberModule.hh"

class		sendData;

class		BomberLoad : public IBomberModule
{
public :
  BomberLoad(void);
  virtual ~BomberLoad(void);
  virtual void	initialize(sendData&);
  virtual void	load(void);
  virtual void	update(const gdl::GameClock &,
			       gdl::Input &);
  virtual void	draw(void);
  virtual void	unload(sendData&);
  virtual bool	isEnd(void) const;
  virtual bool	isOver(void) const;
  virtual eBomberModule	nextModule(void);
private :
  std::list<GlGraphics::GlObject *>	_objsList;
  bool		_end;
};

#endif		/* __BOMBERLOAD_HH__ */
