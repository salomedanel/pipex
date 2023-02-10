/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:44:20 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/24 13:02:44 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_infile(t_pipex *ppx, char **argv)
{
	if (ppx->here_doc == 1)
		get_heredoc(ppx, argv);
	else
	{
		ppx->infile = open(argv[1], O_RDONLY);
		if (ppx->infile < 0)
			ft_error_desc(ERR_FILE, argv[1], ppx);
	}
}

void	open_outfile(t_pipex *ppx, char **argv, int argc)
{
	if (ppx->here_doc == 1)
	{
		ppx->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND,
				0000644);
		if (ppx->outfile < 0)
			ft_error_desc(ERR_FILE, argv[argc - 1], ppx);
	}
	else
	{
		ppx->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC,
				0000644);
		if (ppx->outfile < 0)
			ft_error_desc(ERR_FILE, argv[argc - 1], ppx);
	}
}

void	get_heredoc(t_pipex *ppx, char **argv)
{
	int		heredoc_fd;
	char	*buf;

	heredoc_fd = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (heredoc_fd < 0)
		ft_error(HD_ERR);
	while (1)
	{
		write(1, "here_doc> ", 10);
		buf = get_next_line(0, 0);
		if (!buf)
			exit(EXIT_FAILURE);
		if (!ft_strncmp(argv[2], buf, ft_strlen(argv[2])))
		{
			get_next_line(1, 1);
			free(buf);
			break ;
		}
		write(heredoc_fd, buf, ft_strlen(buf));
		free(buf);
	}
	close(heredoc_fd);
	open_heredocasinfile(ppx, argv);
}

void	open_heredocasinfile(t_pipex *ppx, char **argv)
{
	ppx->infile = open(argv[1], O_RDONLY);
	if (ppx->infile < 0)
	{
		unlink(argv[1]);
		ft_error(HD_ERR);
	}
}

void	close_files(t_pipex *ppx)
{
	close(ppx->infile);
	close(ppx->outfile);
	if (ppx->here_doc == 1)
		unlink("here_doc");
}
