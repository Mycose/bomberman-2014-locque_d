//
// bomb_gl2d_scoresframe.cpp for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/bomberman-2014-locque_d/engine/objects2D/menuframes
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Fri Jun  3 12:31:32 2011 pierre le
// Last update Sun Jun  5 12:50:33 2011 nicolas laille
//

#include	<stdexcept>
#include	<iostream>

#include	"GameMenu.hh"
#include	"MenuFrame.hh"
#include	"StrTexture.hh"
#include	"sendData.hh"

#include	"bomb_gl2d_btnback.hh"
#include	"bomb_gl2d_scoresframe.hh"
#include	"bomb_gl2d_picturebox.hh"


GlGraphics::MenuScoresFrame::MenuScoresFrame(const Vector3f &position)
  : MenuFrame(position), score()
{
}


GlGraphics::MenuScoresFrame::~MenuScoresFrame() {}


void		GlGraphics::MenuScoresFrame::initialize(void)
{
  // Frame background
  addMenuItemToList(new GlGraphics::PictureBox(GlGraphics::Vector3f(this->_position.x,
								    this->_position.y),
					       GlGraphics::Vector3f(576, 512),
					       gdl::Image::load("./textures/frame_background.png")));

  // Title
  addMenuItemToList(new GlGraphics::PictureBox(GlGraphics::Vector3f(this->_position.x + 32,
								    this->_position.y + 16),
					       GlGraphics::Vector3f(512, 64),
					       gdl::Image::load("./textures/highscores_flat.png")));

  // Highscores display
  addMenuItemToList(new GlGraphics::PictureBox(GlGraphics::Vector3f(this->_position.x + 32,
								    this->_position.y + 90),
					       GlGraphics::Vector3f(512, 384),
					       gdl::Image::load("./textures/text_box_flat.png")));

  // Labels of text for highscores display
  for (size_t i = 0; i < 5; ++i)
    {
      _textList[i] = new GlGraphics::StrTexture(GlGraphics::Vector3f(this->_position.x + 75,
								     this->_position.y + 150 + 58 * i),
						(!this->score.isEnd() ? this->score.getNextScore() : "NO SCORE"),
						32.0f, 16.0f);
      addMenuItemToList(_textList[i]);
    }

  // Back button
  addMenuItemToList(new GlGraphics::BackBtn(GlGraphics::Vector3f(this->_position.x + 32 + 464,
								 this->_position.y + 490),
					    GameMenu::FRAME_MAIN));
}

void		GlGraphics::MenuScoresFrame::load(sendData& data)
{
  std::cout << "Meilleur score de la partie par " << data.getPlayerScore() << std::endl;
  std::cout << "Avec un score de : " << data.getScore() << std::endl;
  this->score.addScore(data.getPlayerScore(), data.getScore());
  this->score.reset();
  for (size_t i = 0; i < 5 && !this->score.isEnd(); ++i)
    this->setTextLine(i, this->score.getNextScore());
}

void		GlGraphics::MenuScoresFrame::setTextLine(size_t line,
							 const std::string &str)
{
  if (line > 6)
    throw std::runtime_error("Internal: no such highscore line.");
  this->_textList[line]->setText(str);
}


void		GlGraphics::MenuScoresFrame::unload(sendData &) {}


bool		GlGraphics::MenuScoresFrame::isEnd(void) const
{
  return (false);
}
