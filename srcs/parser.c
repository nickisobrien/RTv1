/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:02:28 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/30 17:13:03 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void		read_scene(t_world *w)
{
	char *line;

	while (ft_get_next_line(w->fd, &line) > 0)
	{
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
}