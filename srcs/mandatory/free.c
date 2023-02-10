/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:44:05 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/24 13:02:41 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(char *error)
{
	write(2, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

int	ft_error_desc(char *error, char *type, t_pipex *ppx)
{
	int	i;

	i = 0;
	write(2, type, ft_strlen(type));
	write(2, error, ft_strlen(error));
	if (ft_strcmp(error, ERR_COMMAND) == 0)
	{
		while (ppx->cmd_and_options[i])
		{
			free(ppx->cmd_and_options[i]);
			i++;
		}
		free(ppx->cmd_and_options);
	}
	exit(EXIT_FAILURE);
}

void	close_pipes(t_pipex *ppx)
{
	int	i;

	i = 0;
	while (i < (ppx->nb_pipes))
	{
		close(ppx->pipefd[i]);
		i++;
	}
}

void	ft_free(t_pipex *ppx)
{
	int	i;

	i = 0;
	close(ppx->infile);
	close(ppx->outfile);
	if (ppx->here_doc == 1)
		unlink("here_doc");
	i = 0;
	while (ppx->all_paths[i])
	{
		free(ppx->all_paths[i]);
		i++;
	}
	free(ppx->all_paths);
	free(ppx->pipefd);
}

void	ft_free_main(t_pipex *ppx)
{
	int	i;

	i = 0;
	close(ppx->infile);
	close(ppx->outfile);
	if (ppx->here_doc == 1)
		unlink("here_doc");
	free(ppx->pipefd);
}
