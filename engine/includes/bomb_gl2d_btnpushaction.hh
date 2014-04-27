//
// bomb_gl2d_btnpushaction.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Sun Jun  5 13:48:17 2011 pierre le
// Last update Sun Jun  5 13:49:00 2011 pierre le
//

#ifndef		__BOMB_GL2D_BTNPUSHACTION_HH__
# define	__BOMB_GL2D_BTNPUSHACTION_HH__

# include	"LoadGame.hh"


namespace	GlGraphics
{
  template	<class SlotAction>
  class		PushActionBtn : public BtnAction<SlotAction>
  {
  public:
    typedef void (SlotAction::*slotFunc)(const std::string &);

    explicit PushActionBtn(const Vector3f &position,
			   const Vector3f &size,
			   const std::string &text,
			   slotFunc funcToCall,
			   SlotAction &classToApply,
			   const gdl::Image &objImage,
			   const gdl::Image &objImageEntered);
    virtual ~PushActionBtn() {}

    virtual void	initialize(void);

    // Events for derived classes
    virtual void	OnItemUpdate(const gdl::GameClock &,
				     gdl::Input &);
    virtual void	OnItemDraw(void);
    virtual void	OnMouseClick(void);
    virtual void	OnMouseEnter(void);
    virtual void	OnMouseLeave(void);

    void		setText(const std::string &);
    const std::string & getText(void) const;

  private:
    // Text label on button
    StrTexture		_text;
    slotFunc		_slotFuncToCall;
  };
}


#endif		// !__BOMB_GL2D_BTNPUSHACTION_HH__
