/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:56:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/01 12:25:40 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	pipex(int f1, int f2, char **cmd1, char **cmd2, char **env)
{
	pid_t	pid;
	int		end[2];

	pipe(end);
	pid = fork();
	if (pid == 0)
		ft_child_process(f1, cmd1, env, end);
	else
		ft_parent_process(f2, cmd2, env, end);
}

static int	ft_check_args(int argc)
{
	if (argc > 5)
		return (-1);
	else
		return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		f1;
	int		f2;
	char	**env;
	char	**cmd1;
	char	**cmd2;

	for (int i = 0; envp[i]; i++)
	{
		ft_printf("envp n.%d %s\n", i, envp[i]);
	}
	
	env = NULL;
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_RDWR);
	if (!ft_check_args(argc))
		return (ft_printf("error input"), 0);
	// env = ft_split(envp, ':');
	cmd1 = ft_split(argv[2], ' ');
    cmd2 = ft_split(argv[3], ' ');
	pipex(f1, f2, cmd1, cmd2, env);
	return (0);
}


/*
==================== FONCTIONNEMENT DUP =================
dup2 redirige le stdout dans un autre
ici le stdout sera le fd et non la sortie "classique" du terminal

les fd par defaults sont 
0 stdin
1 stdout
2 stderr

int	fd;
fd = open("outfile.txt", O_WRONLY);
dup2(fd, STDOUT_FILENO);
close(fd);
ft_printf("bonjour");
return (0);
*/

/*
==================== FONCTIONNEMENT FORK =================
Le pid du child process est 0
Donc pid == 0 pour cibler le child
et   pid != 0 pour cibler le parent

pid_t pid;

pid = fork();
if (pid == 0)
{
	ft_printf("Je suis le child process, pid:%d\n", getpid());
	ft_printf("Le pid child:%d\n", pid);
}
else
{
	ft_printf("Je suis le parent process, pid:%d\n", getpid());
	ft_printf("Le pid parent :%d\n", pid);
}
return (0);
*/