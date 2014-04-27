//
// bomb_blocktypes.hh for Bomberman in /home/le_b//projects/tek2/cpp/bomberman/workshop/engine
//
// Made by pierre le
// Login   <le_b@epitech.net>
//
// Started on  Wed May  4 13:54:05 2011 pierre le
// Last update Mon May 30 16:22:47 2011 pierre le
//

#ifndef		__BOMB_BLOCKTYPES_HH__
# define	__BOMB_BLOCKTYPES_HH__

// BLOCK_SIZE defines the size of a square unit in pixels.
const int	BLOCK_SIZE = 256.0f;

enum		eBlockType
  {
    B_OTHER,
    B_GROUND,
    B_BREAKABLE_WALL,
    B_SOLID_WALL,
    B_BOMB,
    B_CHARACTER,
    B_FIRE,
    B_BONUS_BOMB,
    B_BONUS_POWERUP,
    B_BONUS_SPEED
  };


#endif		// !__BOMB_BLOCKTYPES_HH__
