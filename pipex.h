#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/inc/libft.h"
# include "ft_printf/ft_printf.h"

void	parent_process(char **argv, int *pipe_fd, char **env);
void	child_process(char **argv, int *pipe_fd, char **env);
char	*find_path(char *cmd, char **env);
void	execute_cmd(char *argv, char **env);
char	*check_env_path(char *cmd);
char	*concat_path(char *all_paths, char *cmd);
void	free_path(char **all_paths);
void	error_message(char *message);

#endif
