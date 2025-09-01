/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wirare <wirare@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:35:10 by wirare            #+#    #+#             */
/*   Updated: 2025/09/01 16:39:05 by wirare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include <stdio.h>

typedef struct
{
	void	*ss_sp;
	int		ss_flags;
	size_t	ss_size;
}	sigaltstack_t;
