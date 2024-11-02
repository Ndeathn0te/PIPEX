#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h> 
# include "libft/inc/libft.h"

void    execute_cmd(char *argv, char **env);
void    free_cmd(char **cmd);
char    *find_path(char *cmd, char **env);
void    process(int fd_in, int fd_out, char *cmd, char **env);
int     main(int argc, char **argv, char **env);

#endif