
#ifndef MINISHELL_H
# define MINISHELL_H

# define READLINE_LIBRARY
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libs/libft/includes/libft.h"
# include "readline.h"
# include "parsing.h"

# define RED 	"\x1B[31m"
# define GRN 	"\x1B[32m"
# define BLU 	"\x1B[34m"
# define WHT 	"\x1B[37m"
# define YEL 	"\x1B[33m"
# define RESET	"\033[1;0m"

/* 		TODO - to modify | From Pipex (only here to see the main struct from pipex project)	*/
typedef struct s_data
{
	char	**envp;
	char	**cmd_paths;
	int		input;
	int		output;
	int		index;
	int		pipes_nb;
	int		cmd_nb;
	int		**pipes;
	pid_t	*pids;
}			t_data;

/* 		Initiate the main structure named 'data' 	*/


/* 		Creates the required pipes					*/


/* 		Creates pids and childs processes			*/


/*		Close all pipes, free and error fts			*/


#endif