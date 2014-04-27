//
// main.cpp for  in /home/laille_n//projet/tek2/cpp/bomberman
//
// Made by nicolas laille
// Login   <laille_n@epitech.net>
//
// Started on  Mon May  2 11:29:14 2011 nicolas laille
// Last update Sun Jun  5 10:19:16 2011 nicolas laille
//

#include	<iostream>
#include	<cstdlib>

#include	"bomb_gl_engine.hh"

int		main()
{
  GlEngine	engine("Bomberman");
  
  engine.run();
  return (EXIT_SUCCESS);
}
