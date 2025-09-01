/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:17:22 by ellanglo          #+#    #+#             */
/*   Updated: 2025/09/01 20:26:16 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_strace.h>
#include <stdlib.h>
#include <stdio.h>

void tracee(char **av, char **envp)
{
	(void)envp;
	ptrace(PTRACE_TRACEME, 0, 0, 0);
	raise(SIGSTOP);
	execl(av[1], av[1], NULL);
	perror("execl failed");
	exit(1);
}
