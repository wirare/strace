/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wirare <wirare@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:02:23 by wirare            #+#    #+#             */
/*   Updated: 2025/08/31 02:37:23 by wirare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

typedef enum
{
        SAT_STRUCT_KEXEC_SEGMENT_PTR,
        SAT_INT,
        SAT_STRUCT_SIGALTSTACK_PTR,
        SAT_UNION_BPF_ATTR_PTR,
        SAT_STRUCT_USER_MSGHDR_PTR,
        SAT_CHAR_PTR,
        SAT_STRUCT__KERNEL_ITIMERSPEC_PTR,
        SAT_CAP_USER_HEADER_T,
        SAT_CONST_CAP_USER_DATA_T,
        SAT_STRUCT_IOCB_PTR,
        SAT_MQD_T,
        SAT_SIZE_T,
        SAT_OFF_T,
        SAT_STRUCT_PERF_EVENT_ATTR_PTR,
        SAT_SIGSET_T_PTR,
        SAT_STRUCT_OLD_UTSNAME_PTR,
        SAT_KEY_T,
        SAT_UNSIGNED_INT,
        SAT_INT_PTR,
        SAT_LOFF_T_PTR,
        SAT_UNSIGNED_INT_PTR,
        SAT_TIME_T_PTR,
        SAT_STRUCT_SCHED_PARAM_PTR,
        SAT_AIO_CONTEXT_T,
        SAT_OFF_T_PTR,
        SAT_QID_T,
        SAT_STRUCT__KERNEL_TIMESPEC_PTR,
        SAT_STRUCT__KERNEL_TIMEX_PTR,
        SAT_STRUCT_MQ_ATTR_PTR,
        SAT_STRUCT_RLIMIT64_PTR,
        SAT_STRUCT_STATFS_PTR,
        SAT_CONST_STRUCT__KERNEL_ITIMERSPEC_PTR,
        SAT_KEY_SERIAL_T,
        SAT_TIMER_T,
        SAT_STRUCT_RUSAGE_PTR,
        SAT_UNSIGNED,
        SAT_GID_T,
        SAT_CONST_STRUCT_SIGALTSTACK_PTR,
        SAT_STRUCT_EPOLL_EVENT_PTR,
        SAT_SIZE_T_PTR,
        SAT_STRUCT_GETCPU_CACHE_PTR,
        SAT_LONG,
        SAT_U32_PTR,
        SAT_STRUCT_FILE_HANDLE_PTR,
        SAT_STRUCT_RLIMIT_PTR,
        SAT_CONST_STRUCT_MQ_ATTR_PTR,
        SAT_STRUCT_MSQID_DS_PTR,
        SAT_STRUCT_IO_EVENT_PTR,
        SAT_STRUCT_SYSINFO_PTR,
        SAT_STRUCT_TIMEZONE_PTR,
        SAT_STRUCT_SOCKADDR_PTR,
        SAT_UID_T,
        SAT_CONST_STRUCT_RLIMIT64_PTR,
        SAT_CONST_VOID_PTR_PTR,
        SAT_CONST_VOID_PTR,
        SAT_CAP_USER_DATA_T,
        SAT_STRUCT_USTAT_PTR,
        SAT_STRUCT_ROBUST_LIST_HEAD_PTR,
        SAT_CONST_SIGSET_T_PTR,
        SAT_STRUCT_UTIMBUF_PTR,
        SAT_CONST_STRUCT_SIGEVENT_PTR,
        SAT_CLOCKID_T,
        SAT_TIMER_T_PTR_,
        SAT_CONST_STRUCT_IOVEC_PTR,
        SAT_STRUCT_ITIMERVAL_PTR,
        SAT_CONST_STRUCT__KERNEL_TIMESPEC_PTR,
        SAT_UNSIGNED_PTR,
        SAT_CONST_CHAR_PTR_,
        SAT_STRUCT_STATX_PTR,
        SAT_FD_SET_PTR,
        SAT_STRUCT_LINUX_DIRENT_PTR,
        SAT_CONST_INT_PTR,
        SAT_UNSIGNED_LONG,
        SAT_STRUCT_SIGEVENT_PTR,
        SAT__S32,
        SAT_STRUCT_STAT_PTR,
        SAT_GID_T_PTR,
        SAT_U64,
        SAT_SIGINFO_T_PTR,
        SAT_STRUCT_TMS_PTR,
        SAT_U32,
        SAT_STRUCT_SEMBUF_PTR,
        SAT_STRUCT_SHMID_DS_PTR,
        SAT_STRUCT_TIMEVAL_PTR,
        SAT_STRUCT__OLD_KERNEL_STAT_PTR,
        SAT_STRUCT_LINUX_DIRENT64_PTR,
        SAT_CONST_CHAR_PTR_CONST_PTR,
        SAT_STRUCT_SIGACTION_PTR,
        SAT_AIO_CONTEXT_T_PTR,
        SAT_LOFF_T,
        SAT_STRUCT_MSGBUF_PTR,
        SAT_STRUCT_POLLFD_PTR,
        SAT_CONST_CHAR_PTR,
        SAT_PID_T,
        SAT_STRUCT_MMSGHDR_PTR,
        SAT_RWF_T,
        SAT_UNSIGNED_CHAR_PTR_,
        SAT_STRUCT_SCHED_ATTR_PTR,
        SAT_CONST_UNSIGNED_LONG_PTR,
        SAT_CONST_STRUCT_SIGACTION_PTR,
        SAT_STRUCT_IOCB_PTR_PTR,
        SAT_UMODE_T,
        SAT_STRUCT_ROBUST_LIST_HEAD_PTR_PTR,
        SAT_UID_T_PTR,
        SAT_VOID_PTR,
        SAT_STRUCT_SIGINFO_PTR,
        SAT_UNSIGNED_LONG_PTR,
}	t_syscall_arg_type;

typedef struct 
{
	int syscall_number;
	char *syscall_name;
	t_syscall_arg_type	arg0;
	t_syscall_arg_type	arg1;
	t_syscall_arg_type	arg2;
	t_syscall_arg_type	arg3;
	t_syscall_arg_type	arg4;
	t_syscall_arg_type	arg5;
}	t_syscall_info;

char* resolve_x64_syscall_num(long long syscall_number);
