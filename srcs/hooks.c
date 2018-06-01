/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:07:53 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/30 15:09:06 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int			key_pressed_hook(int key, t_world *w)
{
	(void)w;
	if (key == ESC)
		exit(0);
	return (0);
}

int			hook_close(int key, t_world *w)
{
	(void)key;
	(void)w;
	exit(0);
	return (0);
}
