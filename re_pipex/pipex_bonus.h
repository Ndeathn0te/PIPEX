#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "libft/inc/libft.h"

// Funciones para la gestión de comandos
void    free_cmd(char **cmd);
  char    *get_path_bonus(char *cmd, char **env);
void    execute_cmd_bonus(char *argv, char **env);
void    process_bonus(char *cmd, int in_fd, int out_fd, char **env);

// Funciones para la gestión de here_doc
void    here_doc(char *delimiter, char **commands, int command_count);

// Funciones para ejecutar múltiples comandos
void    execute_multiple_commands(char **commands, int command_count, char **env);

// Función principal
int     main_bonus(int argc, char **argv, char **env);

#endif
