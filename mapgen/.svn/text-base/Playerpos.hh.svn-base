//
// Playerpos.hh for  in /home/locque_d//rendu/proj/Bomberman/bomberman-2014-locque_d/mapgen
//
// Made by damien locque
// Login   <locque_d@epitech.net>
//
// Started on  Thu May 12 15:15:27 2011 damien locque
// Last update Tue May 24 12:19:37 2011 nicolas laille
//

#ifndef _PLAYERPOS_HH_
#define _PLAYERPOS_HH_

#include	<vector>

class		Playerpos
{
public :
  Playerpos();
  ~Playerpos();
  void		addposition(int, int);
  int		size(void) const;
  std::pair<int, int> operator[](int);
private:
  std::vector<std::pair<int, int> > _perso_start;
  Playerpos(const Playerpos &);
  Playerpos& operator=(const Playerpos &);
};

#endif /* !_PLAYERPOS_HH_ */
