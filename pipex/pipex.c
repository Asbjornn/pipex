/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:56:30 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/09 20:18:00 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                            FREE FUNCTION                                 */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                               PIPEX FUNCTION                             */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void	pipex(char **argv, char *envp[])
{
	pid_t	pid1;
	pid_t	pid2;
	int		end[2];
	int		status;

	pipe(end);
	pid1 = fork();
	if (pid1 == -1)
		exit (-1);
	if (pid1 == 0)
		first_child_process(argv, end, envp);
	pid2 = fork();
	if (pid2 == -1)
		exit (-1);
	if (pid2 == 0)
		second_child_process(argv, end, envp);
	close(end[0]);
	close(end[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                  MAIN                                    */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
		return (ft_printf("format: ./pipex infile cmd1 cmd2 outfile\n"), 0);
	pipex(argv, envp);
	return (0);
}

/*
==================== FONCTIONNEMENT DUP =================
dup2 redirige le stdout, stdin et stderr dans un autre
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
l'utilisation de cette commande annule les commandes qui vont suivre
*/

/*
==================== FONCTIONNEMENT ACCESS =================
permet de verifier si on a acces a un path avec differement mode
R_OK = read ok
W_OK = write ok
X_OK = execute ok

renvoi -1 en cas d'erreur
renvoi 0 si c'est bon	
*/