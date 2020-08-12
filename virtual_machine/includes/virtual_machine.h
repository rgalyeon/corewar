/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:01:43 by rgalyeon          #+#    #+#             */
/*   Updated: 2020/07/30 17:19:22 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VIRTUAL_MACHINE_H
# define VIRTUAL_MACHINE_H
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "constants.h"

# define UNUSED (void)

typedef unsigned int uint;

/*
**  Player structure
*/

typedef struct		s_player
{
	char	name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];
	uint	player_number;
	uint	start_pos;
}					t_player;

/*
**	File with champion (.cor file)
*/

typedef struct		s_champ_file
{
	char	*filename;
	int 	number;
	int 	fd;
	int 	code_size;
}					t_champ_file;

/*
** Carriage structure
*/

typedef struct	s_carriage
{
	uint			pc;
	int				reg[REG_NUMBER];
	bool			carry;
	uint 			number;
	int 			n_lives;
	uint 			cooldown;
}				t_carr;


/*
** Playground structure
*/

typedef struct	s_area
{
	char		*map;
	t_player	players[MAX_PLAYERS];
	t_vec 		**cycle_arr;
	t_vec		*carriages;

	int			cycle_to_die_delta;
	int			cycle_to_die;
	int			not_changed_checks;

	int			lives_in_round;

	int			cycle_to_dump;

	uint		n_players;
	uint		n_processes;
	uint 		curr_index;

	uint		next_process_index;

}				t_area;


void	error_handler(char *msg);
void 	parse_arguments(t_area *area, int argc, char **argv);
void	init_players(t_area *arena, t_champ_file *files);

/*
** Utils.c
*/

uint	reverse_bytes(uint n);


#endif
