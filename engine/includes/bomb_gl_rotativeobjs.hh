//
// bomb_gl_rotativeobjs.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Mon May 30 11:23:08 2011 pierre le
// Last update Fri Jun  3 10:17:44 2011 pierre le
//

#ifndef		__BOMB_GL_ROTATIVEOBJS_HH__
# define	__BOMB_GL_ROTATIVEOBJS_HH__

# include	"bomb_gl_object.hh"


namespace	GlGraphics
{
  // Mother class
  class		RotativeObj : public GlTexturedObj
  {
  public:
    explicit RotativeObj(const Vector3f &position,
			 eBlockType blockId);

    virtual void	initialize(void) = 0;
    virtual void	update(gdl::GameClock const &, gdl::Input &) = 0;
    virtual void	draw(void);

  protected:
    float	_rotAngle;
    eBlockType	_blockId;
  };


  namespace	DrawableObj
  {
    // Inherited classes
    class	BonusBomb : public RotativeObj
    {
    public:
      explicit BonusBomb(const Vector3f &position);
      virtual ~BonusBomb() {}

      virtual void	initialize(void);
      virtual void	update(gdl::GameClock const &, gdl::Input &);
    };

    class	BonusPowerup : public RotativeObj
    {
    public:
      explicit BonusPowerup(const Vector3f &position);
      virtual ~BonusPowerup() {}

      virtual void	initialize(void);
      virtual void	update(gdl::GameClock const &, gdl::Input &);
    };

    class	BonusSpeed : public RotativeObj
    {
    public:
      explicit BonusSpeed(const Vector3f &position);
      virtual ~BonusSpeed() {}

      virtual void	initialize(void);
      virtual void	update(gdl::GameClock const &, gdl::Input &);
    };
  }
}


#endif		// !__BOMB_GL_ROTATIVEOBJS_HH__
