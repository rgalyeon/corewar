/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:01:32 by rgalyeon          #+#    #+#             */
/*   Updated: 2020/07/29 20:13:41 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

/*
** Function tries to open/read file and save fd. Terminates if error occurred.
** @param file - file with champion (.cor file)
*/

static inline void	open_and_validate_file(t_champ_file *file)
{
	const int	fd = open(file->filename, 'r');
	int 		magic_header;

	if (fd == -1)
		error_handler("Cannot open .cor file"); //todo add printf
	if (read(fd, &magic_header, MAGIC_HEADER_SIZE) == -1)
		error_handler("Cannot read .cor file"); //todo add printf
	if (reverse_bytes(magic_header) != COREWAR_EXEC_MAGIC)
		error_handler("Magic header not found in .cor file");
	file->fd = fd;
}

static void			parse_champ_file(t_champ_file *file, t_player *player)
{
	uint	champ_exec_code_size;
	int 	buf;

	open_and_validate_file(file);
	if (read(file->fd, player->name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		error_handler("File has to small code");
	player->name[PROG_NAME_LENGTH] = 0;
	read(file->fd, &buf, 4);
	if (read(file->fd, &champ_exec_code_size, 4) == -1)
		error_handler("Error reading champion code size");
//	printf("code size = %d\n", champ_exec_code_size);
	champ_exec_code_size = reverse_bytes(champ_exec_code_size);
	if (champ_exec_code_size > CHAMP_MAX_SIZE)
		error_handler("File has too large code");
	file->code_size = champ_exec_code_size;
	if (read(file->fd, player->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		error_handler("File has to small code");
	read(file->fd, &buf, 4);
}

static inline void	init_arena(t_area *arena, t_champ_file *files)
{
	register int	i;
	t_champ_file 	curr_file;
	char 			*champ_pos;
	int 			n_bytes;

	i = 0;
	while (i < arena->n_players)
	{
		curr_file = files[i];
		champ_pos = arena->map + arena->players[i].start_pos;
//		n_bytes = read(files[i].fd, arena->map, files[i].code_size + 1);
		n_bytes = read(curr_file.fd, champ_pos, curr_file.code_size + 1);
//		printf("%d\n", n_bytes);
		if (n_bytes != files[i].code_size)
			error_handler("Code size is wrong");
		close(curr_file.fd);
		i += 1;
	}
}

static inline void 	introduce_players(t_area *arena, t_champ_file *files)
{
	register int	i;
	t_champ_file	curr_file;
	t_player		curr_player;

	i = 0;
	ft_putendl("Introducing contestants...");
	while (i < arena->n_players)
	{
		curr_file = files[i];
		curr_player = arena->players[i];
		printf("* Player %d, weighing %d bytes, "
		 "\"%s\" (\"%s\") !\n", curr_player.player_number, curr_file.code_size,
		 							curr_player.name, curr_player.comment); //todo printf
		i += 1;
	}
}

void				init_players(t_area *arena, t_champ_file *files)
{
	register uint	i;
	const uint		n_players = arena->n_players;

	i = 0;
	while (i < n_players)
	{
		arena->players[i].player_number = files[i].number;
		arena->players[i].start_pos = i * MEM_SIZE / n_players;
		parse_champ_file(&files[i], &arena->players[i]);
		i += 1;
	}
	init_arena(arena, files);
	introduce_players(arena, files);
}
