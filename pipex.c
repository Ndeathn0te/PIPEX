#include "pipex.h"

void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}

char	*find_path(char *cmd, char **env)
{
	char	**all_paths;
	char	*path;
	int		i;

	if (!env || !*env || cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
		return (check_env_path(cmd));
	while (*env && ft_strnstr(*env, "PATH=", 5) == 0)
		env++;
	if (!*env)
		return (check_env_path(cmd));
	all_paths = ft_split(*env + 5, ':');
	i = -1;
	while (all_paths[++i])
	{
		path = concat_path(all_paths[i], cmd);
		if (path)
		{
			for (int j = 0; all_paths[j]; j++)
				free(all_paths[j]);
			free(all_paths);
			return (path);
		}
	}
	for (int j = 0; all_paths[j]; j++)
		free(all_paths[j]);
	free(all_paths);
	return (NULL);
}

void	execute_cmd(char *argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (env == NULL)
	{
		free_cmd(cmd);
		error_message("env is NULL");
	}
	path = find_path(cmd[0], env);
	if (path == NULL)
	{
		free_cmd(cmd);
		error_message("Command not found");
	}
	execve(path, cmd, env);
	free_cmd(cmd);
	free(path);
	error_message("execve failed");
}

void	parent_process(char **argv, int *pipe_fd, char **env)
{
	int	fd;

	if (env == NULL)
		error_message("env is NULL");
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error_message("open failed");
	dup2(fd, 1);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_cmd(argv[3], env);
	close(fd);
}

void	child_process(char **argv, int *pipe_fd, char **env)
{
	int	fd;

	if (env == NULL)
		error_message("env is NULL");
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		error_message("open failed");
	dup2(fd, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	execute_cmd(argv[2], env);
	close(fd);
}

void	initialize_pipe_and_fork(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
		error_message("pipe failed");
}

int	main(int argc, char **argv, char **env)
{
	int	pipe_fd[2];
	int	pid;

	if (argc != 5 || env == NULL)
		error_message("Wrong number of arguments or env is NULL");
	initialize_pipe_and_fork(pipe_fd);
	pid = fork();
	if (pid == -1)
		error_message("fork failed");
	if (pid == 0)
		child_process(argv, pipe_fd, env);
	else
		parent_process(argv, pipe_fd, env);
	return (0);
}
