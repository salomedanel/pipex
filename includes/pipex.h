/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:49:54 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/24 13:02:56 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERR_ARG "Invalid number of arguments.\n"
# define ERR_FILE ": no such file or directory\n"
# define ERR_COMMAND ": command not found\n"
# define HD_ERR "Here_doc error.\n"
# define ERR_MALLOC "Malloc error.\n"
# define ERR_PIPE "Pipe error.\n"
# define ERR_DUP "File descriptor duplication error.\n"
# define ERR_FORK "Fork error.\n"
# define ERR_TEST "Shlomite\n"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		here_doc;
	int		nb_cmd;
	int		nb_pipes;
	char	*path;
	char	**all_paths;
	char	*path_cmd;
	char	*cmd;
	char	**cmd_and_options;
	int		pipe_id;
	int		*pipefd;
	int		cmd_id;
	pid_t	pid[1024];

}			t_pipex;

// main
int			count_nb_args(int argc, char **argv, t_pipex *ppx);
char		*get_path(char **env);
void		create_pipes(t_pipex *ppx);
void		init_variable(t_pipex *ppx, char **env, int argc);
// files
void		get_heredoc(t_pipex *ppx, char **argv);
void		open_heredocasinfile(t_pipex *ppx, char **argv);
void		open_infile(t_pipex *ppx, char **argv);
void		open_outfile(t_pipex *ppx, char **argv, int argc);
void		close_files(t_pipex *ppx);
// childs
char		*get_cmd_path(t_pipex *ppx, char *cmd);
void		ft_dup2(int read, int write);
void		dup_childs(t_pipex *ppx, int read, int write);
void		close_parents(t_pipex *ppx, int read, int write);
void		childs(t_pipex *ppx, char **argv, char **env);
// free
int			ft_error(char *error);
int			ft_error_desc(char *error, char *type, t_pipex *ppx);
void		ft_free(t_pipex *ppx);
void		close_pipes(t_pipex *ppx);
void		ft_free_main(t_pipex *ppx);

#endif