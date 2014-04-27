//
// HighScore.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/module
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Fri May 27 13:54:30 2011 nicolas laille
// Last update Sun Jun  5 16:07:54 2011 nicolas laille
//


# include	<fstream>
# include	<algorithm>
# include	<sstream>

# include	"HighScore.hh"

std::string	HighScore::file = "highscore.txt";
std::string	HighScore::MAGIC = "HS>";

HighScore::HighScore()
  : _scores(0), highfile(), end(false)
{
  this->highfile.open(file.c_str(), std::ios::out | std::ios::in);
  this->initScore();
  this->_pos = this->_scores.begin();
}

HighScore::~HighScore()
{
}

std::string const &	HighScore::getNextScore(void)
{
  std::stringstream	ss;

  if (this->_pos != this->_scores.end())
    {
      ss << std::string((*(this->_pos)).name);
      ss.width(15);
      ss << (*(this->_pos)).score;
      this->_pos++;
      this->tmp = ss.str();
    }
  return (this->tmp);
}

void		HighScore::reset(void)
{
  this->_pos = this->_scores.begin();  
}

bool		HighScore::mySort(const sHighScore& score1, const sHighScore& score2)
{
  return (score1.score > score2.score);
}

void		HighScore::addScore(std::string const & name, int scoreT)
{
  std::vector<sHighScore>::iterator	its;
  int		i;
  sHighScore	score;
  
  score.name[0] = name[0];
  score.name[1] = name[1];
  score.name[2] = name[2];
  score.name[3] = 0;
  score.score = scoreT;
  this->_scores.push_back(score);
  std::sort(this->_scores.begin(), this->_scores.end(), mySort);    
  this->highfile.seekp(0, std::ios_base::beg);
  this->initFile();
  for (its = this->_scores.begin(), i = 0; its != this->_scores.end() && i < 5; its++, i++)
    this->highfile.write(reinterpret_cast<char *>(&(*its)), sizeof((*its)));
  this->highfile.close();
}

void		HighScore::initCheck(sCheck& check)
{
  check.magic[0] = MAGIC[0];
  check.magic[1] = MAGIC[1];
  check.magic[2] = MAGIC[2];
  check.magic[3] = MAGIC[3];
  check.nbScore = (this->_scores.size() <= 5 ? this->_scores.size() : 5);
}

void		HighScore::initFile(void)
{
  sCheck	check;
  
  this->initCheck(check);
  this->highfile.write(reinterpret_cast<char *>(&check), sizeof(check));
}

bool		HighScore::checkFile(sCheck& check)
{
  if (!(std::string(check.magic) == MAGIC))
    {
      this->highfile.close();
      this->highfile.open(file.c_str(), std::ios::in | std::ios::out | std::ios::trunc);
      this->initFile();
      return (false);
    }
  return (true);
}

void		HighScore::initScore(void)
{
  sHighScore	score;
  sCheck	check;

  if (this->highfile.is_open() && this->highfile.good())
    {
      this->highfile.read(reinterpret_cast<char *>(&check), sizeof(check));
      if (!this->checkFile(check))
	return ;
    }
  else
    {
      this->checkFile(check);
      return ;
    }
  while (this->highfile.good() && check.nbScore > 0)
    {
      this->highfile.read(reinterpret_cast<char *>(&score), sizeof(score));
      this->_scores.push_back(score);
      check.nbScore--;
    }
}

bool		HighScore::isEnd(void)
{
  return (this->_pos == this->_scores.end());
}
