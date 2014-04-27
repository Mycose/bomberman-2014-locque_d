//
// LoadGame.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman-2014-locque_d/module
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Thu Jun  2 14:54:04 2011 nicolas laille
// Last update Sun Jun  5 16:05:01 2011 nicolas laille
//

#include	<cstdlib>
#include	<dirent.h>

#include	<algorithm>

#include	"LoadGame.hh"

LoadGame::LoadGame(void)
  : _files(0), _save(""), _end(false)
{
  this->readDir("./Savegames");
  this->_pos = this->_files.begin();
}

LoadGame::~LoadGame(void)
{
}

std::string const&	LoadGame::getNextSave()
{
  if (this->_pos != this->_files.end())
    {
      this->tmp = *(this->_pos);
      this->_pos++;
    }
  return (this->tmp);
}

bool		LoadGame::End(void) const
{
  return ((this->_pos == this->_files.end()));
}

bool		LoadGame::isEnd(void) const
{
  return (this->_end);
}

std::string const &	LoadGame::getSave(void) const
{
  return (this->_save);
}

void		LoadGame::readDir(std::string const & directory)
{
  DIR*		pDIR;
  struct dirent*entry;
  std::string	tmp;

  this->_files.clear();
  if ((pDIR = opendir(directory.c_str())) != NULL)
    {
      while ((entry = readdir(pDIR)) != NULL)
	{
	  tmp = entry->d_name;
	  if (tmp[0] != '.' && tmp.find("Bomberman-") == 0)
	    this->_files.push_back(tmp);
	}
      closedir(pDIR);
    }
  this->_files.sort();
  this->_files.reverse();
}


void		LoadGame::buttonCall(const std::string & savename)
{
  this->_save = std::string("Savegames/") + savename;
  this->_end = true;
}
