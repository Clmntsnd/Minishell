#include "../../include/minishell.h"

void	ft_free_jct(t_jct *jct)
{
	if (jct)
	{
		if (jct->envp)
			ft_free_tab_char(jct->envp);
		if (jct->tab)
			ft_free_3tab(jct);
		if (jct->fds_in)
			free(jct->fds_in);
		if (jct->fds_out)
			free(jct->fds_out);
		free(jct);
	}
}

void	ft_free_pars(t_pars *pars)
{
	if (pars)
	{
		if (pars->input)
			ft_freenull(pars->input);
		if (pars->line)
			ft_free_lst(&pars->line);
		if (pars->path_var)
			ft_free_tab_char(pars->path_var);
		ft_freenull(pars);
	}
}

void	ft_free_lst(t_token **lst)
{
	t_token	*ptr;
	t_token	*tmp;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		tmp = ptr->next;
		ft_freenull(ptr->str);
		free(ptr);
		ptr = tmp;
	}
	*lst = NULL;
}

void	ft_free_token(t_token *token)
{
	if (token)
	{
		if (token->str)
		{
			free(token->str);
			token->str = NULL;
		}
		free(token);
	}
}

void	ft_exit(t_exec *exec)
{
	int	exit_status;

	exit_status = g_exit_status;
	printf("%d\n", exit_status);
	clear_history();
	ft_free_all(exec->jct, 0, exec);
	exit (exit_status);
}
