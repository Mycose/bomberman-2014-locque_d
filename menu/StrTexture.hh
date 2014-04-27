//
// StrTexture.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/menu
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Thu Jun  2 11:29:32 2011 pierre le
// Last update Fri Jun  3 16:48:15 2011 pierre le
//

#ifndef		__STRTEXTURE_HH__
# define	__STRTEXTURE_HH__

# include	<string>

# include	"Image.hpp"
# include	"bomb_gl_object.hh"


namespace	GlGraphics
{
  const float	RATIO_CHARSET = 1.0f / 16.0f;

  class		StrTexture : public GlObject
  {
  public:
    explicit StrTexture(Vector3f position,
			const std::string &str,
			float size = 16.0f,
			float shrink = 0.0f);
    virtual ~StrTexture(void);

    // Abstraction requirements
    virtual void	initialize(void);
    virtual void	update(const gdl::GameClock &,
			       gdl::Input &);
    virtual void	draw(void);

    // Text properties changers
    // Note: setPosition() and setRotation() are already supported by GlObject
    void		setText(const std::string &);
    void		setSize(float size);
    const std::string &	getText(void) const;

    // Common charset used for all StrTexture objects
    // MADE TO WORK WITH THE CHARSET PICTURE PROVIDED AT DESIGN-TIME
    static gdl::Image					_charset;
    static std::map<char, std::pair<float, float> >	_charMap;

  private:

    // Internal values
    std::string		_str;
    float		_size;
    float		_shrink;
  };
}


#endif		// !__STRTEXTURE_HH__
