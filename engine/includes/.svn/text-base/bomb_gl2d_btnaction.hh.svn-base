//
// bomb_gl2d_btnaction.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Sat Jun  4 17:51:44 2011 pierre le
// Last update Sun Jun  5 11:13:43 2011 pierre le
//

#ifndef		__BOMB_GL2D_BTBACTION_HH__
# define	__BOMB_GL2D_BTNACTION_HH__

# include	"bomb_gl2d_buttonmenuitem.hh"


namespace	GlGraphics
{
  template	<class FrameAction>
  class		BtnAction : public GlButtonMenuItem
  {
  public:
    typedef void (FrameAction::*classFunc)(void);

    explicit BtnAction(const Vector3f &position,
		       const Vector3f &size,
		       classFunc funcToCall,
		       FrameAction &classToApply,
		       const gdl::Image &objImage,
		       const gdl::Image &objImageEntered);
    virtual ~BtnAction() {}

    virtual void	initialize(void);

    // Events for derived classes
    virtual void	OnItemUpdate(const gdl::GameClock &,
				     gdl::Input &);
    virtual void	OnMouseClick(void);
    virtual void	OnMouseEnter(void);
    virtual void	OnMouseLeave(void);

  protected:
    // Pointer to another class' member function
    classFunc		_funcToCall;
    FrameAction		&_classToApply;
  };
}


#endif		// !__BOMB_GL2D_BTNACTION_HH__
