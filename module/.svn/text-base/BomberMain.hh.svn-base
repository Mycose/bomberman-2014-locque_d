//
// BomberMain.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/module
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Thu Jun  2 17:04:37 2011 nicolas laille
// Last update Sun Jun  5 09:26:50 2011 nicolas laille
//

#ifndef		__BOMBERMAIN_HH__
# define	__BOMBERMAIN_HH__

#include	<map>

#include	"IBomberModule.hh"
#include	"IModule.hh"
#include	"sendData.hh"

class		BomberMain : public IModule
{
public :
  BomberMain();
  virtual ~BomberMain(void);
  virtual void	initialize(sendData&);
  virtual void	update(const gdl::GameClock &, gdl::Input &);
  virtual void	draw(void);
  virtual void	unload(sendData&);

  virtual bool	isEnd(void);
  virtual IModule*	copy(void) const;
private :
  void		loadModule(eBomberModule module);
  void		addModule(eBomberModule num, IBomberModule *module);

  IBomberModule*	_current;
  std::map<eBomberModule, IBomberModule*>	_modules;
};

#endif		/* __BOMBERMAIN_HH__ */
