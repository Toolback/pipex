/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:41:01 by jurenaul          #+#    #+#             */
/*   Updated: 2022/12/18 12:30:50 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	openFile(char *fileName, int type)
{
	if (type == INFILE)
	{
		if (access(fileName, F_OK))
		{
			error_exit("openFile : File or Directory not found");
			return (STDIN);
		}
		return (open(fileName, O_RDONLY));
	}
	else 
	{
		return (open(fileName, O_CREAT | O_WRONLY | O_TRUNC, 
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
	}
}

char	**splitting_paths(char *envp[])
{
	int		it;
	char	**paths;

	it = 0;
	while (envp[it])
	{
		if (!ft_strncmp(envp[it], "PATH=", 5))
		{
			paths = ft_split(envp[it] + 5, ':');
			return (paths);
		}
		it++;
	}
	return (NULL);
}

char	**getBin(char *cmd, char **env)
{
	char **path;
	char **bin;
	char *tmp;
	int i;

	i = 0;
	path = splitting_paths(env);
	bin = (char**)malloc(sizeof(char*) * ft_strarrlen(path));
	while (path[i])
	{
		if (path[i][ft_strlen(path[i]) - 1] != '/')
		{
			tmp = ft_strjoin(path[i], "/");
			path[i] = tmp;
		}
		bin[i] = ft_strjoin(path[i], cmd);
		i++;
	}

	return (bin);
}

// Fonction pour afficher une erreur et quitter le programme
void error_exit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}