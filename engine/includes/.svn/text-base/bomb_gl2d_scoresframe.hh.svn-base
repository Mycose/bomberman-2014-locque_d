//
// bomb_gl2d_scoresframe.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/includes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 12:32:46 2011 pierre le
// Last update Sun Jun  5 14:05:28 2011 nicolas laille
//

#ifndef		__BOMB_GL2D_SCORESFRAME_HH__
# define	__BOMB_GL2D_SCORESFRAME_HH__

# include	"StrTexture.hh"
# include	"MenuFrame.hh"

# include	"HighScore.hh"

class		sendData;

namespace	GlGraphics
{
  class		MenuScoresFrame : public MenuFrame
  {
  public:
    explicit MenuScoresFrame(const Vector3f &position);
    virtual ~MenuScoresFrame(void);

    virtual void	initialize(void);
    virtual void	load(sendData&);
    virtual void	unload(sendData &);
    virtual bool	isEnd(void) const;

    void		setTextLine(size_t line,
				    const std::string &str);
  private:
    std::map<size_t, GlGraphics::StrTexture *>	_textList;
    HighScore	score;
  };
}


#endif		// !__BOMB_GL2D_SCORESFRAME_HH__
