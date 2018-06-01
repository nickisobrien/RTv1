/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:39:04 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/30 17:08:45 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int		main(int argc, char **argv)
{
	t_world w;

	if (argc != 2)
		usage();	
	w.fd = open(argv[1], O_RDONLY);
	read_scene(&w);
	w.mlx = mlx_init();
	w.window = mlx_new_window(w.mlx, WIDTH, HEIGHT, WINDOW_NAME);
	mlx_hook(w.window, 2, 0, key_pressed_hook, &w);
	mlx_hook(w.window, 17, 0, hook_close, &w);
	mlx_loop(w.mlx);	
	return (0);
}
