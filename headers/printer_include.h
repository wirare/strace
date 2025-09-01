/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_include.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellanglo <ellanglo@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:18:35 by ellanglo          #+#    #+#             */
/*   Updated: 2025/09/01 21:32:26 by ellanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

typedef unsigned long long int u64;

#define DEFINE_PRINTER(type) [type] = type##_printer,
#define DECLARE_PRINTER(type) void type##_printer(u64 data __attribute__((unused)))

DECLARE_PRINTER(SAT_VA_ARGS);
DECLARE_PRINTER(SAT_INT);
DECLARE_PRINTER(SAT_CHAR_PTR);
DECLARE_PRINTER(SAT_CAP_USER_HEADER_T);
DECLARE_PRINTER(SAT_CONST_CAP_USER_DATA_T);
DECLARE_PRINTER(SAT_MQD_T);
DECLARE_PRINTER(SAT_SIZE_T);
DECLARE_PRINTER(SAT_OFF_T);
DECLARE_PRINTER(SAT_KEY_T);
DECLARE_PRINTER(SAT_UNSIGNED_INT);
DECLARE_PRINTER(SAT_AIO_CONTEXT_T);
DECLARE_PRINTER(SAT_QID_T);
DECLARE_PRINTER(SAT_KEY_SERIAL_T);
DECLARE_PRINTER(SAT_TIMER_T);
DECLARE_PRINTER(SAT_UNSIGNED);
DECLARE_PRINTER(SAT_GID_T);
DECLARE_PRINTER(SAT_LONG);
DECLARE_PRINTER(SAT_UID_T);
DECLARE_PRINTER(SAT_CAP_USER_DATA_T);
DECLARE_PRINTER(SAT_CLOCKID_T);
DECLARE_PRINTER(SAT_UNSIGNED_LONG);
DECLARE_PRINTER(SAT__S32);
DECLARE_PRINTER(SAT_U64);
DECLARE_PRINTER(SAT_U32);
DECLARE_PRINTER(SAT_LOFF_T);
DECLARE_PRINTER(SAT_PID_T);
DECLARE_PRINTER(SAT_RWF_T);
DECLARE_PRINTER(SAT_UNSIGNED_CHAR_PTR);
DECLARE_PRINTER(SAT_UMODE_T);
DECLARE_PRINTER(SAT_NO_ARG);
DECLARE_PRINTER(SAT_PTR);
DECLARE_PRINTER(SAT_ARGV);
DECLARE_PRINTER(SAT_ENVP);
