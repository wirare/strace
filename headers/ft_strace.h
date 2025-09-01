/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wirare <wirare@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:02:23 by wirare            #+#    #+#             */
/*   Updated: 2025/09/01 20:38:57 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <sys/user.h>
#include <unistd.h>
#include <syscall.h>
#include <ft_strace.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <printer_include.h>
#include <sat_type.h>

#ifndef SYS_futex_waitv
# define SYS_futex_waitv 449
#endif

#ifndef SYS_set_mempolicy_home_node
# define SYS_set_mempolicy_home_node 450
#endif

#ifndef SYS_cachestat
# define SYS_cachestat 451
#endif

extern pid_t child_pid;

#define PRINT_SAFE_PTR(format, cast)									\
	if ((cast)data)														\
		printf("%s", (cast)read_child_string(child_pid, (void*)data));	\
	else																\
		printf("NULL");													\

typedef struct 
{
	t_syscall_arg_type	arg0;
	t_syscall_arg_type	arg1;
	t_syscall_arg_type	arg2;
	t_syscall_arg_type	arg3;
	t_syscall_arg_type	arg4;
	t_syscall_arg_type	arg5;
}	t_syscall_args;

typedef struct 
{
	u64 syscall_number;
	const char *syscall_name;
	t_syscall_args args;
}	t_syscall_info;

#define _CONCAT(_a, _b) _a##_b
#define CONCAT(a, b) _CONCAT(a, b)

#define MAKE_SYS_INFO_STRUCT(name, ...)													\
	(t_syscall_info)																	\
	{																					\
		.syscall_number = CONCAT(SYS_, name),											\
		.syscall_name = #name,															\
		.args =																			\
			(t_syscall_args)															\
			{																			\
				.arg0 = SAT_NO_ARG,														\
				.arg1 = SAT_NO_ARG,														\
				.arg2 = SAT_NO_ARG,														\
				.arg3 = SAT_NO_ARG,														\
				.arg4 = SAT_NO_ARG,														\
				.arg5 = SAT_NO_ARG,	__VA_ARGS__											\
			}																			\
	}

typedef void (*pfn_printer)(u64) ;

char* resolve_x64_syscall_num(long long syscall_number);
t_syscall_info get_syscall_info(u64 syscall_number);
void print(t_syscall_arg_type type, u64 data);
int get_num_arg(u64 syscall_number);
char *read_child_string(pid_t pid, void *addr);
void tracee(char **av, char **envp);
void tracer();
int is_address(u64 syscall_number);
