#include "../../include/minishell.h"

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

void	ft_exit_free(t_ms *ms, int flexit)
{
	clear_history();
	ft_free_all(ms);
	exit(flexit);
}