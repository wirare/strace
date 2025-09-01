/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printer_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:10:13 by ellanglo          #+#    #+#             */
/*   Updated: 2025/09/01 21:45:45 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printer_include.h"
#include <ft_strace.h>
#include <stdio.h>

char *read_child_string(pid_t pid, void *addr) 
{
	static char buffer[4096];
    struct iovec local_iov = {buffer, 4095};
    struct iovec remote_iov = {addr, 4095};
    
    ssize_t bytes = process_vm_readv(pid, &local_iov, 1, &remote_iov, 1, 0);
    if (bytes > 0) {
        buffer[bytes] = '\0';
        return buffer;
    }
    return NULL;
}

int is_address(u64 syscall_number)
{
	switch (syscall_number)
	{
		case (SYS_mmap) : return 1;
		case (SYS_brk) : return 1;
		case (SYS_mremap) : return 1;
		case (SYS_shmat) : return 1;
		default : return 0;
	}
}

void print(t_syscall_arg_type type, u64 data)
{
	static const pfn_printer printer_table[] = 
	{
		DEFINE_PRINTER(SAT_VA_ARGS)
		DEFINE_PRINTER(SAT_INT)
		DEFINE_PRINTER(SAT_CHAR_PTR)
		DEFINE_PRINTER(SAT_CAP_USER_HEADER_T)
		DEFINE_PRINTER(SAT_CONST_CAP_USER_DATA_T)
		DEFINE_PRINTER(SAT_MQD_T)
		DEFINE_PRINTER(SAT_SIZE_T)
		DEFINE_PRINTER(SAT_OFF_T)
		DEFINE_PRINTER(SAT_KEY_T)
		DEFINE_PRINTER(SAT_UNSIGNED_INT)
		DEFINE_PRINTER(SAT_AIO_CONTEXT_T)
		DEFINE_PRINTER(SAT_QID_T)
		DEFINE_PRINTER(SAT_KEY_SERIAL_T)
		DEFINE_PRINTER(SAT_TIMER_T)
		DEFINE_PRINTER(SAT_UNSIGNED)
		DEFINE_PRINTER(SAT_GID_T)
		DEFINE_PRINTER(SAT_LONG)
		DEFINE_PRINTER(SAT_UID_T)
		DEFINE_PRINTER(SAT_CAP_USER_DATA_T)
		DEFINE_PRINTER(SAT_CLOCKID_T)
		DEFINE_PRINTER(SAT_UNSIGNED_LONG)
		DEFINE_PRINTER(SAT__S32)
		DEFINE_PRINTER(SAT_U64)
		DEFINE_PRINTER(SAT_U32)
		DEFINE_PRINTER(SAT_LOFF_T)
		DEFINE_PRINTER(SAT_PID_T)
		DEFINE_PRINTER(SAT_RWF_T)
		DEFINE_PRINTER(SAT_UMODE_T)
		DEFINE_PRINTER(SAT_PTR)
		DEFINE_PRINTER(SAT_ARGV)
		DEFINE_PRINTER(SAT_ENVP)
		DEFINE_PRINTER(SAT_UNSIGNED_CHAR_PTR)
		DEFINE_PRINTER(SAT_NO_ARG)
	};

	printer_table[type](data);
	return ;
}

DECLARE_PRINTER(SAT_VA_ARGS)
{
	printf("{...}");
}

DECLARE_PRINTER(SAT_INT)
{
	printf("%d", (int)data);
}

DECLARE_PRINTER(SAT_CHAR_PTR)
{
	if ((char*)data)
		printf("\"%s\"", (char*)read_child_string(child_pid, (void*)data));
	else
		printf("NULL");
}

DECLARE_PRINTER(SAT_CAP_USER_HEADER_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_CONST_CAP_USER_DATA_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_MQD_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_SIZE_T)
{
	printf("%lu", (size_t)data);
}

DECLARE_PRINTER(SAT_OFF_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_KEY_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_UNSIGNED_INT)
{
	printf("%u", (unsigned int)data);
}

DECLARE_PRINTER(SAT_AIO_CONTEXT_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_QID_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_KEY_SERIAL_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_TIMER_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_UNSIGNED)
{
	printf("%u", (unsigned)data);
}

DECLARE_PRINTER(SAT_GID_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_LONG)
{
	printf("%ld", (long)data);
}

DECLARE_PRINTER(SAT_UID_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_CAP_USER_DATA_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_CLOCKID_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_UNSIGNED_LONG){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT__S32){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_U64)
{
	printf("%llu", (unsigned long long)data);
}

DECLARE_PRINTER(SAT_U32)
{
	printf("%lu", (unsigned long)data);
}

DECLARE_PRINTER(SAT_LOFF_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_PID_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_RWF_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_UNSIGNED_CHAR_PTR)
{
	printf("%p", (unsigned char*)data);
}

DECLARE_PRINTER(SAT_UMODE_T){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_NO_ARG)
{
	printf("");
}

DECLARE_PRINTER(SAT_PTR)
{
	printf("%p", (void*)data);
};

DECLARE_PRINTER(SAT_ARGV){printf("NOT IMPLEMENTED");}

DECLARE_PRINTER(SAT_ENVP){printf("NOT IMPLEMENTED");}
