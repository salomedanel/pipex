/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:54:13 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/24 14:38:19 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	count_nb_args(int argc, char **argv, t_pipex *ppx)
{
	if (argc < 2)
		ft_error(ERR_ARG);
	if (ft_strncmp("here_doc", argv[1], 9) == 0)
	{
		ppx->here_doc = 1;
		return (6);
	}
	else
	{
		ppx->here_doc = 0;
		return (5);
	}
}

// permet de recuperer tous les paths qui contiennent des cmd
char	*get_path(char **env)
{
	while (ft_strncmp("PATH=", *env, 5) != 0)
		env++;
	return (*env + 5);
}

void	create_pipes(t_pipex *ppx)
{
	int	i;

	i = 0;
	while (i < ppx->nb_cmd - 1)
	{
		if (pipe(ppx->pipefd + 2 * i) < 0)
			ft_error(ERR_PIPE);
		i++;
	}
}

void	init_variable(t_pipex *ppx, char **env, int argc)
{
	ppx->path = get_path(env);
	ppx->nb_cmd = argc - 3 - ppx->here_doc;
	ppx->nb_pipes = (ppx->nb_cmd - 1) * 2;
	ppx->pipefd = malloc(sizeof(int) * ppx->nb_pipes);
	if (!ppx->pipefd)
	{
		close_files(ppx);
		ft_error(ERR_MALLOC);
	}
	ppx->cmd_id = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	ppx;

	if (!env || !*env)
		return (0);
	if (argc < count_nb_args(argc, argv, &ppx))
		ft_error(ERR_ARG);
	open_infile(&ppx, argv);
	open_outfile(&ppx, argv, argc);
	init_variable(&ppx, env, argc);
	create_pipes(&ppx);
	while (ppx.cmd_id < ppx.nb_cmd)
	{
		childs(&ppx, argv, env);
		ppx.cmd_id++;
	}
	waitpid(-1, NULL, 0);
	ft_free_main(&ppx);
	return (0);
}
