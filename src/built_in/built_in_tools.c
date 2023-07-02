#include "../../include/minishell.h"

int	ft_get_ac(char **cmd)
{
	int	j;

	j = 0;
	while (cmd[j])
	{
		if (DEBUG)
			printf("cmd[%d]: %s\n", j, cmd[j]);
		j++;
	}
	return (j);
}

bool	ft_1st_part_valid(t_ms *ms, char *cmd)
{
	int	j;

	j = -1;
	while (cmd[++j])
	{
		while (cmd[j] == '_')
			j++;
		if (cmd[j] == '$' || cmd[j] == '?' || cmd[j] == '_')
			j++;
		if ((!ft_isalpha(cmd[0]) && cmd[0] != '_' && cmd[0] != '=') 
			|| !ft_isalnum(cmd[j]))
		{
			printf("c[%d]: %c not a valid identifier\n", j, cmd[j]);
			ft_freenull(cmd);
			ms->flexit = EXIT_FAILURE;
			return (false);
		}
	}
	return(true);
}

char	*ft_trim_arg(char *cmd)
{
	char	**var;
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	tmp1 = NULL;
	tmp2 = NULL;
	tmp3 = NULL;
	var = ft_split(cmd, '=');
	printf("var[0] = %s\n", var[0]);
	if (var[1])
	{
		tmp1 = ft_strtrim(var[1], " ");
		printf("tmp1 = %s\n", tmp1);
		tmp2 = ft_strjoin(var[0], "=");
		tmp3 = ft_strjoin(tmp2, tmp1);
		tmp1 = ft_freenull(tmp1);
		tmp2 = ft_freenull(tmp2);
		printf("tmp3 = %s\n", tmp3);
		ft_free_tab_char(var);
		return (tmp3);
	}
	ft_free_tab_char(var);
	return (cmd);
}
