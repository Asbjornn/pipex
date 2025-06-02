/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcauchy <gcauchy@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:10:39 by gcauchy           #+#    #+#             */
/*   Updated: 2025/06/01 12:34:31 by gcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	// int		f1;
	// int		f2;
	// pid_t	pid;
	// int		end[2];
	// char	buffer[6];
	// if(argc != 3)
	// 	return (printf("error, pas assez ou trop d'argument\n"), 0);

	// f1 = open(argv[1], O_RDONLY);
	// f2 = open(argv[2], O_WRONLY);

	// pipe(end);
	// pid = fork();
	// if(pid == 0)
	// {
	// 	dup2(f1, STDIN_FILENO);
	// 	dup2(end[1], STDOUT_FILENO);
	// 	close(end[0]);
	// 	close(f1);
	// 	close(f2);
	// 	read(0, buffer, 5);
	// 	buffer[5] = '\0';
	// 	printf("%s", buffer);
	// 	close(end[1]);
	// }
	// else
	// {
    //     // wait(NULL);
	// 	dup2(f2, STDOUT_FILENO);
	// 	dup2(end[0], STDIN_FILENO);	
	// 	close(end[1]);
	// 	close(f1);
	// 	close(f2);
	// 	read(end[0], buffer, 5);
	// 	printf("%s", buffer);
	// 	close(end[0]);
	// }

	char	*argv[3] = {"ls", "-l", NULL};
	execve("/bin/ls", argv, NULL);
	printf("test test test test\n");

	
	return (0);
}
