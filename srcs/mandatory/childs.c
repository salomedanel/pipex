/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:49:39 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/24 12:57:21 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// check si la cmd est executable en cherchant son path
char	*get_cmd_path(t_pipex *ppx, char *cmd)
{
	char	*slash;
	int		i;

	i = 0;
	ppx->all_paths = ft_split(ppx->path, ':');
	if (ppx->all_paths == NULL)
	{
		ft_free(ppx);
		ft_error_desc(ERR_COMMAND, cmd, ppx);
	}
	while (ppx->all_paths[i])
	{
		slash = ft_strjoin(ppx->all_paths[i], "/");
		ppx->path_cmd = ft_strjoin(slash, cmd);
		free(slash);
		if (access(ppx->path_cmd, F_OK | X_OK) == 0)
			return (ppx->path_cmd);
		free(ppx->path_cmd);
		i++;
	}
	ft_free(ppx);
	ft_error_desc(ERR_COMMAND, cmd, ppx);
	return (NULL);
}

// duplique les fd
void	ft_dup2(int read, int write)
{
	if (dup2(read, STDIN_FILENO) < 0)
		ft_error(ERR_DUP);
	if (dup2(write, STDOUT_FILENO) < 0)
		ft_error(ERR_DUP);
}

void	dup_childs(t_pipex *ppx, int read, int write)
{
	if (ppx->cmd_id == 0)
		ft_dup2(ppx->infile, ppx->pipefd[1]);
	else if (ppx->cmd_id == ppx->nb_cmd - 1)
		ft_dup2(ppx->pipefd[read], ppx->outfile);
	else
		ft_dup2(ppx->pipefd[read], ppx->pipefd[write]);
	close_pipes(ppx);
}

void	close_parents(t_pipex *ppx, int read, int write)
{
	if (ppx->cmd_id != 0)
		close(ppx->pipefd[read]);
	if (ppx->cmd_id != ppx->nb_cmd - 1)
		close(ppx->pipefd[write]);
}

void	childs(t_pipex *ppx, char **argv, char **env)
{
	int	read;
	int	write;

	read = (ppx->cmd_id * 2) - 2;
	write = (ppx->cmd_id * 2) + 1;
	ppx->pid[ppx->cmd_id] = fork();
	if (ppx->pid[ppx->cmd_id] == 0)
	{
		dup_childs(ppx, read, write);
		ppx->cmd_and_options = ft_split(argv[ppx->cmd_id + ppx->here_doc + 2],
				' ');
		ppx->path_cmd = get_cmd_path(ppx, ppx->cmd_and_options[0]);
		if (ppx->path_cmd == NULL)
		{
			ft_free(ppx);
			ft_error_desc(ERR_COMMAND, ppx->cmd_and_options[0], ppx);
		}
		if (execve(ppx->path_cmd, ppx->cmd_and_options, env) < 0)
			ft_free(ppx);
	}
	else if (ppx->pid[ppx->cmd_id] > 0)
		close_parents(ppx, read, write);
}
