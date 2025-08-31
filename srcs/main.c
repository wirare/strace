/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wirare <wirare@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:33:27 by wirare            #+#    #+#             */
/*   Updated: 2025/08/31 00:57:05 by wirare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define _GNU_SOURCE
#include <string.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/reg.h>     // for ORIG_RAX etc. (on x86_64)
#include <sys/user.h>    // for struct user_regs_struct
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>
#include <ft_strace.h>

int is_address(long long syscall_number)
{
	switch (syscall_number)
	{
		case (9) : return 1;
		case (12) : return 1;
		case (25) : return 1;
		case (30) : return 1;
		default : return 0;
	}
}

int main(int ac, char** av)
{
    if (ac < 2) 
	{
        fprintf(stderr, "Usage: %s <program>\n", av[0]);
        return 1;
    }

    pid_t pid = fork();

	if (pid == 0) 
	{
        ptrace(PTRACE_TRACEME, 0, 0, 0);
		raise(SIGSTOP);
        execl(av[1], av[1], NULL);
        perror("execl failed");
        exit(1);
    }
	else 
	{
        int status;
        waitpid(pid, &status, 0);

        ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACEEXEC);

        struct user_regs_struct regs;
        int entering = 1;
		int address_format = 0;

        while (1) 
		{
            ptrace(PTRACE_SYSCALL, pid, 0, 0);
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) break;
            if (WIFSTOPPED(status)) 
			{
				if ((status >> 16) == PTRACE_EVENT_EXEC)
					continue;

                ptrace(PTRACE_GETREGS, pid, 0, &regs);

                if (entering) {
					address_format = 0;
					if (is_address(regs.orig_rax))
						address_format = 1;
                    printf("%s()", resolve_x64_syscall_num(regs.orig_rax));
                    entering = 0;
                } else {
					long long ret = regs.rax;

					if (ret < 0 && ret >= -4095)
						printf(" = %lld %s (%s)\n", ret + 1, strerrorname_np(-ret) ,strerror(-ret));
					else if (address_format)
						printf(" = 0x%llx\n", regs.rax);
					else
						printf(" = %lld\n", regs.rax);
                    entering = 1;
                }
            }
        }
		if (regs.orig_rax == 231)
			printf(" = ?\n");
    }

    return 0;
}
