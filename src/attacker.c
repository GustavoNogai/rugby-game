// Standard headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

bool equal_direction(direction_t d1, direction_t d2){

  return (d1.i == d2.i) && (d1.j == d2.j);

}

direction_t random_direction(direction_t previous_direction){

  direction_t selected_direction = previous_direction;

  srand(time(NULL));

  while (equal_direction(selected_direction, previous_direction)){

    switch (rand() % 5){

      case 0:
        selected_direction = (direction_t) DIR_RIGHT;
        break;
  
      case 1:
        selected_direction = (direction_t) DIR_UP_RIGHT;
        break;  

      case 2:
        selected_direction = (direction_t) DIR_DOWN_RIGHT;
        break;  

      case 3:
        selected_direction = (direction_t) DIR_UP;
        break;  

      case 4:
        selected_direction = (direction_t) DIR_DOWN;
        break;  

      default:
        printf("Error on attacker function random_direction.\n");
        break;

    }
  }
  return selected_direction;
}

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {
      
  UNUSED(defender_spy);

  static position_t previous_position = INVALID_POSITION;
  static direction_t best_direction = (direction_t) DIR_RIGHT;

  if (equal_positions(attacker_position, previous_position)){

    best_direction = random_direction(best_direction);

  }

  else {
    
    srand(time(NULL));

    switch (rand() % 3){

    case 0:
      best_direction = (direction_t) DIR_RIGHT;
      break;
    
    case 1:
      best_direction = (direction_t) DIR_UP_RIGHT;
      break;

    case 2:
      best_direction = (direction_t) DIR_DOWN_RIGHT;
      break;

    default:
      printf("Error on attacker 3-way forward randomizer.\n");
      break;

    }
  }

  previous_position = attacker_position;
  return best_direction;
}

/*----------------------------------------------------------------------------*/
