/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:12:25 by nobrien           #+#    #+#             */
/*   Updated: 2018/05/30 17:12:47 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WOLF3D_H
# define __WOLF3D_H

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include <fcntl.h>

# define WIDTH 1280
# define HEIGHT 720
# define WINDOW_NAME "RTv1"

/*
**keys
*/
# define W 13
# define A 0
# define S 1
# define D 2
# define Q 12
# define E 14
# define TAB 48
# define M 46
# define E 14
# define ESC 53
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_camera
{
	t_vector	pos;
	t_vector	dir;
}				t_camera;

typedef struct	s_image
{
	int			width;
	int			height;
	void		*image;
	char		*ptr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_world
{
	void		*mlx;
	void		*window;
	t_image		image;
	int			fd;
}				t_world;

/*
**hooks
*/
int			key_pressed_hook(int key, t_world *w);
int			hook_close(int key, t_world *w);

/*
**image
*/
void		init_image(t_world *w);
void		img_pixel_put(t_image *img, int x, int y, int color);
void		clear_image(t_image *image);

/*
**error
*/
void		usage(void);
void		error(char *str);

/*
**
*/
void		read_scene(t_world *w);

#endif
