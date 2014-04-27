//
// bomb_gl2d_mainframe.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 11:24:37 2011 pierre le
// Last update Sun Jun  5 13:59:59 2011 pierre le
//

#ifndef		__BOMB_GL2D_MAINFRAME_HH__
# define	__BOMB_GL2D_MAINFRAME_HH__

# include	"MenuFrame.hh"

class		sendData;


namespace	GlGraphics
{
  class		MenuMainFrame : public MenuFrame
  {
  public:
    explicit MenuMainFrame(const Vector3f &position = Vector3f(0.0f, 0.0f));
    virtual ~MenuMainFrame(void);

    virtual void	initialize(void);
    virtual void	load(sendData&);
    virtual void	unload(sendData &);
    virtual bool	isEnd(void) const;

    void		setQuit(void);

  private :
    bool		_end;
  };
}


#endif		// !__BOMB_GL2D_MAINFRAME_HH__
