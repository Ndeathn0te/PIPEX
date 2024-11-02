#include "pipex_bonus.h"

void    free_cmd(char **cmd)
{
    for (int i = 0; cmd[i]; i++)
        free(cmd[i]);
    free(cmd);
}

char    *get_path_bonus(char *cmd, char **env)
{
    char    **all_paths, *path, *tmp;
    int     i = -1;

    if (!env || !*env || cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
        return (access(cmd, F_OK) == 0 ? ft_strdup(cmd) : NULL);

    while (*env && ft_strnstr(*env, "PATH=", 5) == 0)
        env++;
    if (!*env)
        return (NULL);

    all_paths = ft_split(*env + 5, ':');
    while (all_paths[++i])
    {
        tmp = ft_strjoin(all_paths[i], "/");
        path = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(path, F_OK) == 0)
            return (free_cmd(all_paths), path);
        free(path);
    }
    free_cmd(all_paths);
    return (NULL);
}

void    execute_cmd_bonus(char *argv, char **env)
{
    char    **cmd = ft_split(argv, ' ');
    char    *path = get_path_bonus(cmd[0], env);

    if (!path)
    {
        free_cmd(cmd);
        perror("Command not found");
        exit(1);
    }
    execve(path, cmd, env);
    free_cmd(cmd);
    free(path);
    perror("execve failed");
    exit(1);
}

void    process_bonus(char *cmd, int in_fd, int out_fd, char **env)
{
    if (dup2(in_fd, 0) == -1 || dup2(out_fd, 1) == -1)
    {
        perror("dup2 failed");
        exit(1);
    }
    close(in_fd);
    close(out_fd);
    execute_cmd_bonus(cmd, env);
}

void    here_doc(char *delimiter, char **commands, int command_count)
{
    int pipe_fd[2];
    pid_t pid;
    char *line;

    if (pipe(pipe_fd) == -1)
        perror("pipe failed");

    pid = fork();
    if (pid == -1)
        perror("fork failed");

    if (pid == 0) // Proceso hijo
    {
        close(pipe_fd[0]); // Cerrar la lectura en el hijo
        while (1)
        {
            line = get_next_line(0); // Lee de la entrada estándar
            if (!line || strcmp(line, delimiter) == 0)
                break;
            write(pipe_fd[1], line, strlen(line));
            free(line);
        }
        close(pipe_fd[1]); // Cerrar la escritura
        exit(0);
    }
    else // Proceso padre
    {
        wait(NULL); // Esperar a que el hijo termine
        for (int i = 0; i < command_count; i++)
        {
            if (i > 0)
                pipe(pipe_fd); // Crear tubería para el siguiente comando
            process_bonus(commands[i], pipe_fd[0], pipe_fd[1], env);
        }
    }
}

void    execute_multiple_commands(char **commands, int command_count, char **env)
{
    int pipe_fd[2];

    for (int i = 0; i < command_count - 1; i++) // Crear pipes para cada comando
    {
        if (pipe(pipe_fd) == -1)
            perror("pipe failed");

        pid_t pid = fork();
        if (pid == -1)
            perror("fork failed");

        if (pid == 0) // Proceso hijo
        {
            dup2(pipe_fd[1], 1); // Redirigir salida estándar
            close(pipe_fd[0]); // Cerrar la lectura
            execute_cmd_bonus(commands[i], env);
            exit(1);
        }
        else // Proceso padre
        {
            dup2(pipe_fd[0], 0); // Redirigir entrada estándar
            close(pipe_fd[1]); // Cerrar la escritura
            wait(NULL); // Esperar a que el hijo termine
        }
    }

    // Ejecutar el último comando
    execute_cmd_bonus(commands[command_count - 1], env);
}

int main_bonus(int argc, char **argv, char **env)
{
    if (argc < 5)
    {
        fprintf(stderr, "Usage: ./pipex_bonus here_doc LIMITADOR comando1 comando2 ... archivo\n");
        return (1);
    }

    if (strcmp(argv[1], "here_doc") == 0)
    {
        here_doc(argv[2], &argv[3], argc - 4);
    }
    else
    {
        execute_multiple_commands(&argv[1], argc - 2, env);
    }

    return (0);
}
