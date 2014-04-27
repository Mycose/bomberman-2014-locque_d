//
// Bomberman.hh for  in /home/laille_n//projet/tek2/cpp/bomberman
// 
// Made by nicolas laille
// Login   <laille_n@epitech.net>
// 
// Started on  Fri Apr 29 15:02:27 2011 nicolas laille
// Last update Fri Jun  3 12:08:27 2011 nicolas laille
//

#ifndef		__BOMBERMAN_HH__
# define	__BOMBERMAN_HH__

#include	<Input.hpp>

#include	"Map.hh"
#include	"ABomberman.hh"

class		Bomberman : public ABomberman
{
public :
  Bomberman(int, int,
	    gdl::Keys::Key up = gdl::Keys::Up,
	    gdl::Keys::Key down = gdl::Keys::Down,
	    gdl::Keys::Key right = gdl::Keys::Right,
	    gdl::Keys::Key left = gdl::Keys::Left,
	    gdl::Keys::Key plant = gdl::Keys::RControl);
  virtual ~Bomberman(void);

  virtual int	update(gdl::Input&, Map& map);

  virtual std::string	Serialize(const std::string& name);
  virtual void		Deserialize(const std::string& doc);

  std::string	SerializeMap(const std::string& name);
  void		DeserializeMap(const std::string& doc, const std::string& name);
};

#endif		/* __BOMBERMAN_HH__ */
