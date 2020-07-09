#include "virtual_machine.h"

void error_handler(char *msg)
{
	if (errno)
		perror(msg);
	else
		ft_putendl_fd(msg, 2);
	exit(errno || 1);
}