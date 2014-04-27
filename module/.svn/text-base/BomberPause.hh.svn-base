//
// BomberPause.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/module
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Thu Jun  2 17:18:12 2011 nicolas laille
// Last update Sun Jun  5 15:13:41 2011 nicolas laille
//

#ifndef		__BOMBERPAUSE_HH__
# define	__BOMBERPAUSE_HH__

#include	<list>

#include	"IBomberModule.hh"
#include	"bomb_gl_object.hh"

class		sendData;

class		BomberPause : public IBomberModule
{
public :
  BomberPause(void);
  virtual ~BomberPause(void);
  virtual void	initialize(sendData&);
  virtual void	load(void);
  virtual void	update(const gdl::GameClock &, gdl::Input &);
  virtual void	draw(void);
  virtual void	unload(sendData&);

  virtual bool	isEnd(void) const;
  virtual bool	isOver(void) const;
  virtual eBomberModule	nextModule(void);

  // Setup triggers
  void		setEnd(void);
  void		setOver(void);

private :
  std::list<GlGraphics::GlObject *>	_objsList;
  bool		_end;
  bool		_over;
};

#endif		/* __BOMBERPAUSE_HH__ */
