#include "pipex.h"

void free_cmd(char **cmd) 
{
    for (int i = 0; cmd[i]; i++)
        free(cmd[i]);
    free(cmd);
}

char *find_path(char *cmd, char **env) 
{
    char **all_paths, *path;
    int i = 0;

    if (!env || !*env || cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
        return (access(cmd, F_OK) == 0 ? ft_strdup(cmd) : NULL);
    while (*env && ft_strnstr(*env, "PATH=", 5) == 0)
        env++;
    if (!*env) return (NULL);
    all_paths = ft_split(*env + 5, ':');
    while (all_paths[i]) 
    {
        path = ft_strjoin(all_paths[i], "/");
        char *full_path = ft_strjoin(path, cmd);
        free(path);
        if (access(full_path, F_OK) == 0) return (free_cmd(all_paths), full_path);
        free(full_path);
        i++;
    }
    free_cmd(all_paths);
    return (NULL);
}

void process(int fd_in, int fd_out, char *cmd, char **env) 
{
    if (dup2(fd_in, 0) == -1 || dup2(fd_out, 1) == -1)
        perror("dup2 failed");
    close(fd_in);
    close(fd_out);
    char **split_cmd = ft_split(cmd, ' ');
    char *path = find_path(split_cmd[0], env);
    if (!path) {
        free_cmd(split_cmd);
        perror("Command not found");
        exit(1);
    }
    execve(path, split_cmd, env);
    perror("execve failed");
    free_cmd(split_cmd);
    free(path);
}

int main(int argc, char **argv, char **env) 
{
    int pipe_fd[2], pid;

    if (argc != 5 || !env) {
        perror("Invalid arguments");
        exit(1);
    }
    if (pipe(pipe_fd) == -1) perror("pipe failed");
    
    if ((pid = fork()) == -1) perror("fork failed");
    
    if (pid == 0) { // Proceso hijo
        int fd_in = open(argv[1], O_RDONLY);
        if (fd_in == -1) perror("open failed");
        process(fd_in, pipe_fd[1], argv[2], env);
    } else { // Proceso padre
        int fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
        if (fd_out == -1) perror("open failed");
        close(pipe_fd[1]);
        process(pipe_fd[0], fd_out, argv[3], env);
        waitpid(pid, NULL, 0); // Esperar al hijo
    }
    return 0;
}