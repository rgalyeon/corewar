/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:01:20 by rgalyeon          #+#    #+#             */
/*   Updated: 2020/08/10 12:50:52 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void 	print_help(void)
{
	ft_putendl("HELP NEED TODO"); //todo add help message
	exit(0);
}

static inline void 		init_cycle_arr(t_vec **cycle_arr)
{
	register uint	i;

	i = 0;
	while (i < N_CYCLES)
	{
		if (!(cycle_arr[i] = ft_int_vec_init(VEC_SIZE)))
			error_handler("Init cycle array");
		i += 1;
	}
}

static inline t_area	*create_area(t_vec **cycle_arr)
{
	t_area *area;

	if (!(area = ft_memalloc(sizeof(t_area))))
		error_handler("Init area pointer (main.c)");
	if (!(area->map = ft_memalloc(sizeof(char) * MEM_SIZE)))
		error_handler("Init area (main.c)");
	init_cycle_arr(cycle_arr);
	area->cycle_arr = cycle_arr;
	area->cycle_to_die = CYCLE_TO_DIE;



	return (area);
}

static void init_carriages(t_area *arena)
{
	register int	i;
	t_carr			*carriage;

	i = 0;
	if (!(arena->carriages = ft_ptr_vec_init(128)))
		error_handler("Init carriages");
	while (i < arena->n_players)
	{
		if (!(carriage = ft_memalloc(sizeof(t_carr))))
			error_handler("Init_carriages: Allocate carriage error");
		carriage->reg[0] = ~arena->players[i].player_number;
		carriage->pc = arena->players[i].start_pos;
		carriage->cooldown = 1;
		carriage->n_lives = 0;
		carriage->number = arena->players[i].player_number;
		arena->n_processes += 1;
		if (!(ft_ptr_vec_push(&arena->carriages, carriage)))
			error_handler("Init_carriages: vec push error");
		if (!(ft_int_vec_push(
				&arena->cycle_arr[(arena->curr_index + carriage->cooldown) % N_CYCLES], carriage->number)))
			error_handler("Init_carriages: int vec push error");
		i += 1;
	}
}

int		main(int argc, char **argv)
{
	t_vec	*cycle_arr[N_CYCLES];
	t_area 	*area;

//	int fd = open("/home/rgalyeon/CLionProjects/corewar/resources/vm-champ-linux/champs/Car.cor", 'r');
//	int magic;
//	char name[PROG_NAME_LENGTH + 1];
//
//	printf("%zu\n", read(fd, &magic, 4));
//	printf("%d\n%u\n", COREWAR_EXEC_MAGIC, reverse_bytes(magic));
//	read(fd, name, PROG_NAME_LENGTH);
//	name[PROG_NAME_LENGTH] = 0;
//	printf("%s\n", name);
//	exit(1);
	if (argc == 1)
		print_help();
	area = create_area(cycle_arr);
	parse_arguments(area, argc - 1, argv + 1);
	init_carriages(area);
	return (0);
}
