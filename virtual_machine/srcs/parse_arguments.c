/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:01:28 by rgalyeon          #+#    #+#             */
/*   Updated: 2020/07/29 16:02:33 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static int		get_numeric_argument(char *num)
{
	register int	i;

	i = 0;
	while (num[i])
	{
		if (ft_isdigit(num[i]) == false)
			error_handler("Argument must be a positive integer");
		i++;
	}
	return (ft_atoi(num));
}

static inline void	check_filename(char *filename)
{
	uint filename_len;

	if (filename == NULL)
		error_handler("Filename does not exist");
	filename_len = (uint)ft_strlen(filename);
	if ((filename_len < 4) ||
						(ft_strcmp(filename + (filename_len - 4), ".cor")))
	{
		error_handler("Only .cor extension available");
	}



}

static inline uint parse_n_flag(char *flag_arg, t_champ_file *files,
														const uint n_players)
{
	int				player_num;
	register uint	j;

	if (flag_arg == NULL)
		error_handler("'-n' flag needs an argument");
	if ((player_num = get_numeric_argument(flag_arg)) <= 0)
		error_handler("N can be only positive number");
	j = 0;
	while (j < n_players)
	{
		if (files[j].number == player_num)
			error_handler("Several players have the same number");
		j += 1;
	}
	files[n_players].number = player_num;
	return (player_num);
}

static inline void set_player_number(t_champ_file *files, uint n_players)
{
	register uint	i;
	register uint	j;
	int 			player_number;

	i = -1;
	player_number = 1;
	while (++i < n_players)
	{
//		printf("%d\n", files[i].number);
		if (files[i].number > (int)n_players)
			error_handler("The player's number is larger "
				 				"than the number of players.");
		if (files[i].number == -1)
		{
			j = -1;
			while (++j < n_players)
			{
				if (player_number == files[j].number)
				{
					player_number += 1;
					j = -1;
				}
			}
			files[i].number = player_number++;
//			printf("Player number %d\n", player_number);
		}
	}
}

void 	parse_arguments(t_area *area, int argc, char **argv)
{
	register int	i;
	t_champ_file	files[MAX_PLAYERS];

	i = 0;
	while (i < argc)
	{
		if (area->n_players == MAX_PLAYERS)
			error_handler("Invalid number of players");
		files[area->n_players].number = -1;
		if (ft_strcmp(argv[i], "-n") == 0)
		{
			parse_n_flag(argv[i + 1], files, area->n_players);
			i += 2;
		}
		check_filename(argv[i]);
		files[area->n_players].filename = argv[i];
		area->n_players += 1;
		i += 1;
	}
	set_player_number(files, area->n_players);
	init_players(area, files);

//	int k = 0;
//	while (k < area->n_players)
//	{
//		printf("Player %s has number %d\n", files[k].filename, files[k].number);
//		k += 1;
//	}
}
