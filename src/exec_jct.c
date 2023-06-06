#include "../include/minishell.h"

void	ft_is_redirection(t_exec *exec, t_jct *jct)
{
	char 	***cmds_tab;
	int		i;
	int		j;

	if(!jct->tab)
		return ;
	cmds_tab = jct->tab;
	i = 0;
	printf("---		ft_is_redirection starts	---\n");
	i = 0;
	while (cmds_tab[i])
	{
		j = 0;
		if(cmds_tab[i][2])
		{
			exec->input_file_name = ft_strtrim(ft_strrchr(cmds_tab[i][2],'<'), "< ");
			exec->fl_redirin = 1;
			printf("exec->input_file_name : %s\n", exec->input_file_name);
			exec->input = open(exec->input_file_name, O_RDONLY);
		}
		if(cmds_tab[i][3])
		{
			exec->output_file_name = ft_strtrim(ft_strrchr(cmds_tab[i][3],'>'), "> ");
			exec->fl_redirout = 1;
			printf("exec->output_file_name : %s\n", exec->output_file_name);
			exec->output = open(exec->output_file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
		}
		i++;
	}
	// exec->fl_hdr = 1; // >>
	// exec->fl_hdl = 0; // <<
	// 	//TODO to modify the below
	// if (exec->fl_redirout == 1 && exec->fl_hdr == 1)
	// 	exec->output = open("out", O_RDWR | O_CREAT | O_APPEND, 0644);
	// else
	// 	exec->output = open("out", O_RDWR | O_CREAT | O_TRUNC, 0644);
	// 	//TODO to modify the above
	// exec->output = open("out", O_RDWR | O_CREAT | O_TRUNC, 0644);
	// //TODO remove the above
	printf("---		ft_is_redirection ends	---\n");
}

void	ft_make_pids_jct(t_exec *exec, t_jct *jct)
{
	int	i;
	
	exec->pids = ft_calloc(exec->cmd_nb, sizeof(pid_t *));
	if (!exec->path_var)
		return ;
	i = -1;
	while (++i < exec->cmd_nb)
	{
		exec->pids[i] = fork();
		if (exec->pids[i] == -1)
			perror("Something went wrong during pid process:");
		// printf("--- Enter in ft_chils_proc	---\n");
		if (exec->pids[i] == 0)
		{
			//this is the child process
			ft_dup_process(exec, i);
			ft_run_cmd_jct(exec, jct, i);
		}	
		//TODO put waitpid here, maybe ?
		// printf("--- Exit ft_chils_proc	---\n");
	}
	//TODO close all input and/or output here (including here_doc)
	if(exec->fl_redirin == 1)
		close(exec->input);
	if(exec->fl_redirout == 1)
		close(exec->output);
	ft_close_pipes(exec);
}

void	ft_run_cmd_jct(t_exec *exec, t_jct *jct, int r)
{
	char	*path;
	char	***cmds;

	cmds = jct->tab;
	// fprintf(stderr, "cmd[%d][0] = %s\n", r, cmds[r][0]);
	// fprintf(stderr, "cmd[%d][1] = %s\n", r, cmds[r][1]);
	// fprintf(stderr, "cmd[%d][2] = %s\n", r, cmds[r][2]);
	// fprintf(stderr, "cmd[%d][3] = %s\n", r, cmds[r][3]);
	path = ft_cmd_path(exec, cmds[r][0]);
	fprintf(stderr, "path = %s\n", path);
	if (!path)
		free(path);
	else if (execve(path, cmds[r], exec->envp) < 0)
		perror("Error ! Something went wrong while executing: ");
	//TODO ft_err exit if there is an error, so the below will never be executed	
}

// void	ft_exec_jct(t_exec *exec, t_jct *jct)
// {
// 	int	i;
// 	int status;
	
// 	ft_is_redirection(exec, jct);
// 	ft_create_pipes(exec);
// 	ft_make_pids_jct(exec, jct);
// 	i = -1;
// 	while (++i < exec->cmd_nb)
// 		waitpid(exec->pids[i], &status, 0);
// 	//TODO clarifier le 2nd arg de waitpid
// 	// ft_free_data(exec);
// }

void	ft_exec_jct(t_exec *exec, t_jct *jct)
{
	int	i;
	int status;
	
	ft_is_redirection(exec, jct);
	if (ft_create_pipes(exec) == 2)
		return ;
	ft_make_pids_jct(exec, jct);
	i = -1;
	while (++i < exec->cmd_nb)
		waitpid(exec->pids[i], &status, 0);
	//TODO clarifier le 2nd arg de waitpid
}