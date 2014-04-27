//
// bomb_gl_object.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/tp
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Wed Apr 27 12:08:49 2011 pierre le
// Last update Sun Jun  5 13:24:57 2011 nicolas laille
//

#ifndef		__BOMB_GL_OBJECT_HH__
# define	__BOMB_GL_OBJECT_HH__

# include	<map>

# include	"GameClock.hpp"
# include	"Input.hpp"
# include	"Image.hpp"
# include	"Model.hpp"
# include	<Color.hpp>


# include	"bomb_gl_vector3f.hh"
# include	"bomb_gl_matrix.hh"

# include	"bomb_blocktypes.hh"


// class GlObject
// Defines a basic container for objects rendered through OpenGL.
//
// Caution: objects' positions, size, rotation and other attributes
//          are relative to the absolute coordinates.


namespace	GlGraphics
{
  class		GlObject
  {
  public:
    explicit GlObject(const Vector3f &position);
    virtual ~GlObject(){}

    virtual void		initialize(void) = 0;
    virtual void		update(const gdl::GameClock &,
				       gdl::Input &) = 0;
    virtual void		draw(void) = 0;

    void			setPosition(const Vector3f &position);
    void			setPosition(int, int);
    const Vector3f		getPosition(void) const;

    void			setRotation(float);
    float			getRotation(void) const;

    virtual void		setColor(const gdl::Color&);
  protected:
    Vector3f			_position;
    float			_rotation;
  };


  class		GlTexturedObj : public GlObject
  {
  public:
    explicit GlTexturedObj(const Vector3f &position);
    virtual ~GlTexturedObj(){}

    virtual void	initialize(void) = 0;
    virtual void	update(const gdl::GameClock &, gdl::Input &) = 0;
    virtual void	draw(void) = 0;

    // Textures storage management
    // Notice: return value of getTexture() with an unregistered blockId
    //         is undefined.
    static gdl::Image &	getTexture(eBlockType blockId);
    static void		putTexture(eBlockType blockId,
				   const gdl::Image &texture);

  private:
    static std::map<eBlockType, gdl::Image>	_texList;
  };

  // class GlTexturedSquare
  // Provides generic block drawing facilities for squarish textured objects.
  class		GlTexturedSquare : public GlTexturedObj
  {
  public:
    explicit GlTexturedSquare(const Vector3f &position,
			      eBlockType blockId);
    virtual ~GlTexturedSquare(){}

    virtual void	initialize(void) = 0;
    virtual void	update(const gdl::GameClock &, gdl::Input &) = 0;
    virtual void	draw(void);

  private:
    eBlockType		_blockId;
  };


  class		GlModelObj : public GlObject
  {
  public:
    explicit GlModelObj(const Vector3f &position);
    virtual ~GlModelObj(){}

    virtual void	initialize(void) = 0;
    virtual void	update(const gdl::GameClock &, gdl::Input &) = 0;
    virtual void	draw(void) = 0;

    // 3D Models storage management
    // Notice: return value of getModel() with an unregistered blockId is
    //         undefined.
    static gdl::Model &	getModel(eBlockType blockId);
    static void		putModel(eBlockType blockId,
				 const gdl::Model &model);
    virtual void	setColor(const gdl::Color&);

  protected:
    gdl::Model			_model;

  private:
    static std::map<eBlockType,
		    gdl::Model>	_modelList;
  };
}


#endif		// !__BOMB_GL_OBJECT_HH__
