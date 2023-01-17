/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:41:05 by jurenaul          #+#    #+#             */
/*   Updated: 2022/12/18 12:44:38 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	runCmd(char *cmd, char **env)
{
	char **paths;
	char **args;
	int	i;

	i = 0;
	args = ft_split(cmd, ' ');
	if (ft_strchr(args[0], '/') != NULL)
		execve(args[0], args, env);
	else
	{
		paths = getBin(args[0], env);
		while (paths[i])
			execve(paths[i++], args, env);
	}
	error_exit("runCmd : command not found\n");
}

void	split_process(char *cmd, char **env, int fdin)
{
	int		pipeFd[2];
	pid_t	pid;

	pipe(pipeFd);
	if (pipe(pipeFd) < 0)
		error_exit("\nsplit_process : pipe() failed\n");
	pid = fork();
	if (pid == -1)
		error_exit("split_process : fork() failed\n");
	if (pid)
	{
		close(pipeFd[1]);
		dup2(pipeFd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipeFd[0]);
		dup2(pipeFd[1], STDOUT);
		if (fdin == STDIN)
			exit(1);
		else
			runCmd(cmd, env);
	}
}

int	main(int ac, char **av, char **envp)
{
	if (ac >= 5)
	{
		int	fd[2];
		
		fd[0] = openFile(av[1], INFILE); 
		dup2(fd[0], STDIN);
		if (ac == 5)
		{
			
			fd[1] = openFile(av[4], OUTFILE);
			dup2(fd[1], STDOUT); 
			split_process(av[2], envp, fd[0]);
			runCmd(av[3], envp);
		}
		else 
		{
			int i;

			i = 0;
			fd[1] = openFile(av[ac - 1], OUTFILE);
			dup2(fd[1], STDOUT);
			split_process(av[2], envp, fd[0]);
			while (i < ac - 2)
				split_process(av[2], envp, fd[0]);
			runCmd(av[i], envp);
		}
	}
	else 
		error_exit("\nUsage: ./pipex file1 cmd1 cmd2 file2\n");
	return (1);
}