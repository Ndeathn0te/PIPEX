#include "pipex.h"

void	error_message(char *message)
{
	perror(message);
	exit(1);
}

void	free_path(char **all_paths)
{
	int	i;

	i = 0;
	while (all_paths[i])
	{
		free(all_paths[i]);
		i++;
	}
	free(all_paths);
}

char	*check_env_path(char *cmd)
{
	if (access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

char	*concat_path(char *all_paths, char *cmd)
{
	char	*path;
	char	*part_path;

	part_path = ft_strjoin(all_paths, "/");
	path = ft_strjoin(part_path, cmd);
	free(part_path);
	if (access(path, F_OK) == 0)
		return (path);
	free(path);
	return (NULL);
}
