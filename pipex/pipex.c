/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:56:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/02 16:21:29 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	pipex(int f1, int f2, char **argv, char *path)
{
	pid_t	pid;
	int		end[2];
	char	**cmd1;
	char	**cmd2;

	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	pipe(end);
	pid = fork();
	if (pid == 0)
		ft_child_process(f1, cmd1, path, end);
	else
		ft_parent_process(f2, cmd2, path, end);
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
	char	*path;

	if (!ft_check_args(argc))
		return (ft_printf("error input"), 0);
	path = ft_get_path(envp);
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[argc - 1], O_RDWR);
	pipex(f1, f2, argv, path);
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

/*
==================== FONCTIONNEMENT PIPE =================
creer un lien entre les deux end,
tout ce qui est donne a l'un, l'autre le recois aussi
on l'utilise pour rediriger les STDIN et STDOUT pour write et read en meme temps
et rediriger l'info pendant un fork
definir un tableau de int 'end[2]'
end[0] sera le read
end[1] sera le write

int end[2];

pipe(end);
...
*/

/*

==================== FONCTIONNEMENT EXECVE =================
permet d'executer une fonction dans une fonction
doit avoir :
un *char avec le path absolue de la commande a executer
un **char avec les arguments de la commande finie par NULL
un **char pour l'environnement finie pas NULL aussi
*/

/*
==================== FONCTIONNEMENT ACCESS =================
permet de verifier si on a acces a un path avec differement mode
R_OK = read ok
W_OK = write ok
X_OK = execute pl
renvoi -1 en cas d'erreur
renvoi 0 si c'est bon	
*/