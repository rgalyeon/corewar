

#ifndef VIRTUAL_MACHINE_H
# define VIRTUAL_MACHINE_H
# include <stdbool.h>
# include "constants.h"

# define UNUSED (void)

/*
** Playground structure
*/

typedef struct	s_area
{
	char	*map;
}				t_area;

/*
** Carriage structure
*/

typedef struct	s_carriage
{
	unsigned int pc;
	int 		reg[REG_NUMBER];
	bool		carry;

}				t_carr;

#endif
