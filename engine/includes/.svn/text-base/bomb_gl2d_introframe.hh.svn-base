//
// bomb_gl2d_introframe.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D/menuframes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Sat Jun  4 15:37:44 2011 pierre le
// Last update Sun Jun  5 15:55:44 2011 pierre le
//

#ifndef		__BOMB_GL2D_INTROFRAME_HH__
# define	__BOMB_GL2D_INTROFRAME_HH__

# include	<vector>

# include	"bomb_gl2d_picturebox.hh"
# include	"MenuFrame.hh"

class		sendData;

namespace	GlGraphics
{
  class		MenuIntroFrame : public MenuFrame
  {
  public:
    explicit MenuIntroFrame(const GlGraphics::Vector3f&);
    virtual ~MenuIntroFrame(void);

    virtual void	initialize(void);
    virtual void	load(sendData&);
    virtual void	unload(sendData &);
    virtual bool	isEnd(void) const;

    virtual void	OnFrameUpdate(const gdl::GameClock &,
				      gdl::Input &);
    virtual void	OnFrameDraw();

    static const float	nextFrame = 6.0f;
    static const float	frameWidth = 1280.0f;

  private:
    // Sliding image static properties
    std::vector<PictureBox *>	_pictures;
    size_t			_currentSlide;

    // Sliding image dynamic properties
    float		_timeBeforeNext;

    // Transition system
    bool		_isSliding;
    void		framesSlide(void);
  };
}


#endif		// !__BOMB_GL2D_INTROFRAME_HH__
