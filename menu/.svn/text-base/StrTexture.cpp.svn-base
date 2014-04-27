//
// StrTexture.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/menu
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Thu Jun  2 11:39:51 2011 pierre le
// Last update Fri Jun  3 18:42:32 2011 pierre le
//

#include	<GL/gl.h>

#include	"bomb_gl_rendercontext.hh"
#include	"bomb_gl_alphablending.hh"

#include	"StrTexture.hh"


std::map<char, std::pair<float, float> >	GlGraphics::StrTexture::_charMap;
gdl::Image					GlGraphics::StrTexture::_charset;

GlGraphics::StrTexture::StrTexture(Vector3f position,
				   const std::string &str,
				   float size,
				   float shrink)
  : GlObject(position), _str(str), _size(size), _shrink(shrink)
{
  _position.y = -_position.y;
}


GlGraphics::StrTexture::~StrTexture(void)
{
}


void		GlGraphics::StrTexture::initialize(void) {}


void		GlGraphics::StrTexture::update(const gdl::GameClock &,
					       gdl::Input &) {}


void		GlGraphics::StrTexture::draw(void)
{
  this->_charset.bind();
  size_t		i = 0;
  GlAlphaBlending	alphablending;

  while (i < this->_str.size())
    {
      GlRenderContext	context(GL_QUADS);

      std::pair<float, float>	res = this->_charMap[this->_str[i]];

      glTexCoord2f(res.first, res.second);
      glVertex2f(this->_position.x + i * this->_size -
		 i * this->_shrink,
		 this->_position.y);

      glTexCoord2f(res.first, res.second + RATIO_CHARSET);
      glVertex2f(this->_position.x + i * this->_size -
		 i * this->_shrink,
		 this->_position.y + this->_size);

      glTexCoord2f(res.first + RATIO_CHARSET, res.second + RATIO_CHARSET);
      glVertex2f(this->_position.x + i * this->_size +
		 this->_size - i * this->_shrink,
		 this->_position.y + this->_size);

      glTexCoord2f(res.first + RATIO_CHARSET, res.second);
      glVertex2f(this->_position.x + i * this->_size +
		 this->_size - i * this->_shrink,
		 this->_position.y);

      i++;
    }
}


void		GlGraphics::StrTexture::setText(const std::string &str)
{
  this->_str = str;
}


void		GlGraphics::StrTexture::setSize(float size)
{
  this->_size = size;
}


const std::string &	GlGraphics::StrTexture::getText(void) const
{
  return (this->_str);
}
