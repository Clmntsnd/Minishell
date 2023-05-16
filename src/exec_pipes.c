#include "../include/minishell.h"

void	ft_close_pipes(t_exec *exec)
{
	int	i;

	i = -1;
	while (++i < exec->pipes_nb)
	{
		close(exec->pipes[i][0]);
		close(exec->pipes[i][1]);
	}
}

int	ft_create_pipes(t_exec *exec)
{
	int	i;

	if (exec->cmd_nb <= 1)
		return (0);
	exec->pipes = ft_calloc(exec->pipes_nb, sizeof(int *));
	if (!exec->pipes)
		ft_err("Something went wrong during calloc", exec);
	i = -1;
	while (++i < exec->pipes_nb)
	{	
		exec->pipes[i] = ft_calloc(2, sizeof(int));
		if (!exec->pipes[i])
			ft_err("Something went wrong during pipe creation: ", exec);
	}
	i = -1;
	while (++i < exec->pipes_nb)
		if (pipe(exec->pipes[i]) == -1)
			ft_err("Something went wrong during pipe creation: ", exec);
	return (1);
}