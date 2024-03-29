/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/07/03 09:41:44 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_merge(t_token *node, t_token *next)
{
	char	*tmp;
	char	*new_str;

	tmp = NULL;
	new_str = NULL;
	new_str = ft_strjoin(node->str, next->str);
	tmp = node->str;
	node->str = ft_strdup(new_str);
	tmp = ft_freenull(tmp);
	new_str = ft_freenull(new_str);
}

void	ft_clean_list(t_token **list)
{
	t_token	*sup;
	t_token	*ptr;

	if (!*list)
		return ;
	ptr = *list;
	while (ptr)
	{
		if (ptr->next && (ptr->next->type == ERROR || ptr->next->str[0] == 29))
		{
			sup = ptr->next;
			if (ptr->next->next)
				ptr->next = ptr->next->next;
			else if (!ptr->next->next)
				ptr->next = NULL;
			ft_free_token(sup);
		}
		else
			ptr = ptr->next;
	}
}

void	ft_swap(t_token *ptr1, t_token *ptr2)
{
	char	*str;
	int		swap;

	swap = ptr1->type;
	ptr1->type = ptr2->type;
	ptr2->type = swap;
	str = ptr1->str;
	ptr1->str = ptr2->str;
	ptr2->str = str;
}

void	ft_swap_node(t_pars *pars)
{
	t_token	*ptr1;
	t_token	*ptr2;

	ptr1 = pars->line;
	while (ptr1->next != NULL)
	{
		ptr2 = ptr1->next;
		while (ptr2 && ptr2->type != PIPE)
		{
			if (ptr1->type > ptr2->type && ptr1->type != PIPE \
				&& ptr2->type != PIPE)
				ft_swap(ptr1, ptr2);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

/*
Parsing Part II
1) Handle redirection tokens.
2) Handle args tokens.
3) Merge tokens.
4) Remove the ERROR type tokens.
5) Swap token to put everything 
	in order for the filler to put it in a char ***array.
*/
void	ft_builder(t_ms *ms)
{
	ft_redirection(ms);
	if (ms->pars->err_builder == false)
	{
		ft_args(ms);
		ft_clean_list(&ms->pars->line);
		ft_swap_node(ms->pars);
	}
}
