//
// MenuFrame.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/menu
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 10:08:17 2011 pierre le
// Last update Sun Jun  5 11:49:13 2011 nicolas laille
//

#ifndef		__MENUFRAME_HH__
# define	__MENUFRAME_HH__

# include	<Input.hpp>

# include	<list>

# include	"bomb_gl_vector3f.hh"
# include	"bomb_gl_object.hh"

class		sendData;


// class MenuFrame
// Container for menu frames, allowing storage of several menu items in
// a single instance.
// Please take note of these specificities:
//   - An inherited class of MenuFrame must add objects to the frame
//     through the addMenuItemToList() member function.
//   - All objects are automatically freed through a `delete' call in
//     destructor.

class		MenuFrame : public GlGraphics::GlObject
{
public:
  explicit MenuFrame(const GlGraphics::Vector3f &position);
  virtual ~MenuFrame(void);

  virtual void		initialize(void) = 0;
  virtual void		load(sendData&) = 0;
  virtual void		update(const gdl::GameClock &,
			       gdl::Input &);
  virtual void		draw(void);
  virtual void		unload(sendData &) = 0;

  // Meant to perform additionnal operations on update/draw
  virtual void		OnFrameUpdate(const gdl::GameClock &,
				      gdl::Input &);
  virtual void		OnFrameDraw();

  GlObject *		addMenuItemToList(GlObject *);

  virtual bool		isEnd(void) const = 0;

private:
  std::list<GlObject *>	_menuContents;
};


#endif		// !__MENUFRAME_HH__
