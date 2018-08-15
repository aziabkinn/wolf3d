/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:23:03 by aziabkin          #+#    #+#             */
/*   Updated: 2018/08/08 19:10:32 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	hints(t_structs *s, int c)
{
	mlx_string_put(s->wind->mlx, s->wind->window, 10 + c,\
		10 + c, 0x4d0403 * !c, "Move: W A S D or < ^ v >");
	mlx_string_put(s->wind->mlx, s->wind->window, 10 + c, 35 + c,\
		0x4d0403 * !c, "Rotate: Q E or NUM1 NUM2 or MOUSE WHEEL");
	mlx_string_put(s->wind->mlx, s->wind->window, 10 + c, 60 + c,\
		0x4d0403 * !c, "Move speed: SPACE");
	mlx_string_put(s->wind->mlx, s->wind->window, 10 + c, 85 + c,\
		0x4d0403 * !c, "Change of textures: ENTER");
	mlx_string_put(s->wind->mlx, s->wind->window, 10 + c, 110 + c,\
		0x4d0403 * !c, "Close window: [esc] or RED cross");
}

void	program(t_structs *strs)
{
	realization(strs);
	check_pos(strs->w);
	load_textures(strs);
	system("afplay music/burst.mp3 &");
	system("afplay music/wind.mp3 &");
	raycasting(strs);
	mlx_put_image_to_window(strs->wind->mlx, strs->wind->window,
												strs->wind->image, 0, 0);
	hints(strs, 2);
	hints(strs, 0);
	signal(SIGINT, stop_music);
	mlx_hook(strs->wind->window, 2, 0, on, strs);
	mlx_hook(strs->wind->window, 3, 0, off, strs);
	mlx_hook(strs->wind->window, 17, 0, exit_x, strs);
	mlx_mouse_hook(strs->wind->window, mouse, strs);
	mlx_loop_hook(strs->wind->mlx, hadle_input_key, strs);
	mlx_loop(strs->wind->mlx);
}

void	stop_music(int sign)
{
	signal(sign, SIG_IGN);
	system("killall -9 afplay");
	exit(0);
}

void	read_and_window(t_structs *strs, int fd)
{
	read_map(strs->w, fd);
	if (!valid_walls(strs->w))
		error_exit(5);
	strs->wind = NULL;
	strs->wind = new_window();
	create_window(&strs->wind);
	strs->wind->image = mlx_new_image(strs->wind->mlx, S_W, S_H);
	strs->wind->adress = (int *)mlx_get_data_addr(strs->wind->image,\
				&strs->wind->endian, &strs->wind->size_line, &strs->wind->bpp);
	mlx_put_image_to_window(strs->wind->mlx, strs->wind->window,\
				strs->wind->image, 0, 0);
}

int		main(int argc, char **argv)
{
	t_structs		*strs;
	int				check_f;
	int				fd;

	if (argc != 2)
		error_exit(3);
	if (!(strs = (t_structs *)malloc(sizeof(t_structs))))
		return (0);
	if (!(strs->w = (t_wolf *)malloc(sizeof(t_wolf))))
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error_exit(2);
	if (ft_strstr(argv[1], "/dev/"))
		error_exit(3);
	check_f = validator_file(fd, strs->w);
	if (check_f != 1)
	{
		close(fd);
		error_exit(1);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	read_and_window(strs, fd);
	program(strs);
	return (0);
}
