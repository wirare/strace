/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:26:31 by ellanglo          #+#    #+#             */
/*   Updated: 2025/09/01 20:37:25 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_strace.h>
#include <stdio.h>
#include <string.h>

void tracer()
{
	int status;
	waitpid(child_pid, &status, 0);

	ptrace(PTRACE_SETOPTIONS, child_pid, 0, PTRACE_O_TRACEEXEC);

	struct user_regs_struct regs;
	int entering = 1;
	int address_format = 0;
	u64 syscall_nb;

	while (1) 
	{
		ptrace(PTRACE_SYSCALL, child_pid, 0, 0);
		waitpid(child_pid, &status, 0);

		if (WIFEXITED(status)) break;
		if (WIFSTOPPED(status)) 
		{
			if ((status >> 16) == PTRACE_EVENT_EXEC)
				continue;

			ptrace(PTRACE_GETREGS, child_pid, 0, &regs);

			if (entering)
			{
				address_format = 0;
				if (is_address(regs.orig_rax))
					address_format = 1;
				syscall_nb = regs.orig_rax;
				printf("%s(", resolve_x64_syscall_num(regs.orig_rax));
				entering = 0;
			}

			else
			{
				long long ret = regs.rax;
				t_syscall_info call = get_syscall_info(syscall_nb);

				print(call.args.arg0, regs.rdi);
				printf(", ");
				print(call.args.arg1, regs.rsi);
				printf(", ");
				print(call.args.arg2, regs.rdx);
				printf(")");
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
	if (regs.orig_rax == SYS_exit_group)
		printf(" = ?\n");
	get_syscall_info(SYS_write);
}
