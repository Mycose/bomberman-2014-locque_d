//
// bomb_gl_drawableobjs.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Wed May  4 10:26:23 2011 pierre le
// Last update Sun Jun  5 13:27:12 2011 nicolas laille
//

#ifndef		__BOMB_GL_DRAWABLEOBJS_HH__
# define	__BOMB_GL_DRAWABLEOBJS_HH__

# include	<Color.hpp>

# include	"Image.hpp"
# include	"AnimStates.hpp"

# include	"bomb_gl_inputman.hh"
# include	"bomb_gl_object.hh"


namespace	GlGraphics
{
  namespace	DrawableObj
  {
    class		StrongWall : public GlTexturedSquare
    {
    public:
      explicit StrongWall(const Vector3f &position);

      virtual void	initialize(void);
      virtual void	update(gdl::GameClock const &, gdl::Input &);
    };

    class		DestructWall : public GlTexturedSquare
    {
    public:
      explicit DestructWall(const Vector3f &position);

      virtual void	initialize(void);
      virtual void	update(gdl::GameClock const &, gdl::Input &);
    };

    class		FireBlock : public GlTexturedObj
    {
    public:
      explicit FireBlock(const Vector3f &position);

      virtual void	initialize(void);
      virtual void	update(gdl::GameClock const &, gdl::Input &);
      virtual void	draw(void);
    };

    class		Ground : public GlTexturedObj
    {
    public:
      explicit Ground(const Vector3f &size);

      virtual void	initialize(void);
      virtual void	update(gdl::GameClock const &, gdl::Input &);
      virtual void	draw(void);

    private:
      Vector3f	_size;
    };

    class		Character : public GlModelObj
    {
    public:
      explicit Character(const Vector3f &position);

      virtual void	initialize(void);
      virtual void	update(gdl::GameClock const &, gdl::Input &);
      virtual void	draw(void);

      virtual void	animate(const std::string &animName,
			gdl::Anim::AnimStates animState);

    private:
      gdl::Anim::AnimStates	_animState;
      bool			_moving;
    };

    class		Bomb : public GlModelObj
    {
    public:
      explicit Bomb(const Vector3f &position);

      virtual void	initialize(void);
      virtual void	update(gdl::GameClock const &, gdl::Input &);
      virtual void	draw(void);
    };
  }
}


#endif		// !__BOMB_GL_DRAWABLEOBJS_HH__
