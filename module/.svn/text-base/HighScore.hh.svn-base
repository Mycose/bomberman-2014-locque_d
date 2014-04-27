//
// HighScore.hh for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/module
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Fri May 27 13:52:50 2011 nicolas laille
// Last update Sun Jun  5 12:16:45 2011 nicolas laille
//

#ifndef		__HIGHSCORE_HH__
# define	__HIGHSCORE_HH__

# include	<string>
# include	<vector>
# include	<fstream>

class		HighScore
{
public :
  static std::string	file;
  static std::string	MAGIC;

  HighScore();
  ~HighScore();
  
  bool		isEnd(void);
  std::string const &	getNextScore(void);
  void			addScore(std::string const & name, int scoreT);
  void		reset(void);
private :
  struct	sHighScore
  {
    char	name[4];
    int		score;
  };
  struct	sCheck
  {
    char	magic[4];
    int		nbScore;
  };

  void			initScore(void);
  void			initCheck(sCheck&);
  bool			checkFile(sCheck&);
  void			initFile(void);
  static bool		mySort(const sHighScore& score1, const sHighScore& score2);

  std::vector<sHighScore>	_scores;  
  std::vector<sHighScore>::iterator	_pos;
  std::fstream	highfile;
  bool		end;
  std::string		tmp;
};

#endif		/* __HIGHSCORE_HH__ */
