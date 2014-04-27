//
// bomb_gl2d_picturebox.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Thu Jun  2 17:52:28 2011 pierre le
// Last update Sun Jun  5 14:21:32 2011 pierre le
//

#ifndef		__BOMB_GL2D_PICTUREBOX_HH__
# define	__BOMB_GL2D_PICTUREBOX_HH__

# include	"bomb_gl2d_menuitem.hh"


namespace	GlGraphics
{
  class		PictureBox : public GlMenuItem
  {
  public:
    explicit PictureBox(const Vector3f &position,
			const Vector3f &size,
			const gdl::Image &picture);
    virtual ~PictureBox() {}

    virtual void	initialize(void);

    // Events for derived classes
    virtual void	OnItemUpdate(const gdl::GameClock &,
				     gdl::Input &);
    virtual void	OnMouseClick(void);
    virtual void	OnMouseEnter(void);
    virtual void	OnMouseLeave(void);

    // Useful functions
    void		setPosition(float x, float y);
    void		setPosX(float x);
    void		setPosY(float y);

    const Vector3f &	getPosition(void) const;
    float		getPosX(void) const;
    float		getPosY(void) const;
  };
}


#endif		// !__BOMB_GL2D_PICTUREBOX_HH__
