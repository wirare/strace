/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wirare <wirare@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:33:27 by wirare            #+#    #+#             */
/*   Updated: 2025/09/01 21:36:28 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_strace.h>
#include <stdio.h>

pid_t	child_pid = 0;

int main(int ac, char** av, char **envp)
{
    if (ac < 2) 
	{
        fprintf(stderr, "Usage: %s <program>\n", av[0]);
        return 1;
    }

    child_pid = fork();

	if (child_pid == 0) 
		tracee(av, envp);
	else 
		tracer();

    return 0;
}
