#include "../include/pipex.h"

void	DoItPlz(char *bin, char *arg, char **env, int test)
{
	// parse env
	char	**path;
	char	**cmd;

	(void) (bin);

	path = splitting_paths(env);
	cmd = get_cmd(arg);
	// cmd[1] = NULL;
	ft_printf("\nRes in DoItPlz -> [%s] cmd, before was [%s], and path is [%s]\n", cmd[2], arg, path[5]);
	if (test == 1)
	{
  char      *newargv[] = {"-la", NULL };
//   char      *newenviron[] = { NULL };
//     char		 *argv[] = {"/bin/ls"};

		execve("usr/sbin/ls", newargv, NULL);
			ft_printf("passed 1");

	}
	else
	{
  char      *newargv[] = { "-w", NULL };
//   char      *newenviron[] = { NULL };
//   char		 *argv[] = {"/bin/wc"};


		execve("usr/sbin/wc", newargv, NULL);
		ft_printf("passed 2");
	}
	error_exit("\nFailed executing command\n");

}

void    child(int* fd, int* pipefd, char** av, char** envp)
{
	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] == -1)
		error_exit("\nError opening file1\n");
		// Rediriger l'entrée standard vers le descripteur de fichier du fichier file1
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error_exit("\nError redirecting stdin\n");
	// Rediriger la sortie standard vers le descripteur de fichier du pipe
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		error_exit("\nError redirecting stdout\n");
	// Fermer les descripteurs de fichier et le tube
	close(fd[0]);
	close(fd[1]);
	close(pipefd[0]);
	close(pipefd[1]);
	DoItPlz(av[1], av[2], envp, 1);
	
}

void    parent(int* fd, int* pipefd, char** av, char** envp)
{
	fd[1] = open(av[4], O_WRONLY | O_CREAT, 0644); // (?)
	if (fd[1] == -1)
		error_exit("\nError opening file2\n");
	// Fermer les descripteurs de fichier et le tube
	close(fd[0]);
	close(fd[1]);
	close(pipefd[0]);
	close(pipefd[1]);
	DoItPlz(av[1], av[3], envp, 2);
}

int main(int ac, char** av, char** envp)
{
	int fd[2];
	int pipefd[2];
	pid_t pid;
	int status;

	if (ac != 5)
		error_exit("\nUsage: ./pipex file1 cmd1 cmd2 file2\n");
	if (pipe(pipefd) < 0)
		error_exit("\nPipe() failed\n");
	
	pid = fork();
	if (pid == -1)
		error_exit("\nFork() failed\n");
	if (pid == 0)
	   child(fd, pipefd, av, envp);
	else
	{
		// waitpid(0, &status, 0);
		parent(fd, pipefd, av, envp);
	}
	waitpid(pid, &status, 0);	
	// Attendre la fin de l'exécution des commandes

	// Fermer les descripteurs de fichier et le tube
	close(fd[0]);
	close(fd[1]);
	close(pipefd[0]);
	close(pipefd[1]);

	return EXIT_SUCCESS;
}