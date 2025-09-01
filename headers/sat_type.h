/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sat_type.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:20:30 by ellanglo          #+#    #+#             */
/*   Updated: 2025/09/01 21:24:50 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

typedef enum
{
		SAT_VA_ARGS,
        SAT_INT,
        SAT_CHAR_PTR,
        SAT_CAP_USER_HEADER_T,
        SAT_CONST_CAP_USER_DATA_T,
        SAT_MQD_T,
        SAT_SIZE_T,
        SAT_OFF_T,
        SAT_KEY_T,
        SAT_UNSIGNED_INT,
        SAT_AIO_CONTEXT_T,
        SAT_QID_T,
        SAT_KEY_SERIAL_T,
        SAT_TIMER_T,
        SAT_UNSIGNED,
        SAT_GID_T,
        SAT_LONG,
        SAT_UID_T,
        SAT_CAP_USER_DATA_T,
        SAT_CLOCKID_T,
		SAT_UNSIGNED_LONG,
        SAT__S32,
        SAT_U64,
        SAT_U32,
        SAT_LOFF_T,
        SAT_PID_T,
        SAT_RWF_T,
        SAT_UMODE_T,
        SAT_UNSIGNED_CHAR_PTR,
		SAT_NO_ARG,
		SAT_ARGV,
		SAT_ENVP,
		SAT_PTR,
}	t_syscall_arg_type;
