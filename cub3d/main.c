/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 04:02:59 by binam             #+#    #+#             */
/*   Updated: 2023/07/16 04:03:00 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_all_check_and_read_map(t_data *data, char *map)
{
	t_index	*index;
	int		n_tex;

	n_tex = 0;
	if (ft_check_cub(map))
	{
		free(data);
		printf("Extension Wrong!\n");
		exit(0);
	}
	index = ft_calloc(1, sizeof(t_index));
	ft_read_map(data, map, index, n_tex);
	ft_check_have_map(data);
	ft_find(data, -1);
	ft_check_wall(data, map);
	ft_check_map(data);
	ft_check_for_long(data);
	ft_check_once_to_map(data);
	ft_check_file(data);
	ft_adjust(data);
	free(index);
}

int	main(int ac, char **av)
{
	t_mlx	*wind;
	t_data	*data;

	if (ac != 2)
	{
		write(2, "Error\nWrong number of arguments\n", 32);
		return (EXIT_FAILURE);
	}
	wind = ft_calloc(sizeof(t_mlx), 1);
	data = ft_calloc(sizeof(t_data), 1);
	ft_all_check_and_read_map(data, av[1]);
	wind->data = data;
	wind->map = data->map;
	wind->mlx = mlx_init();
	wind->window = mlx_new_window(wind->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Cub3D");
	images_to_xpm(wind);
	get_player_position(wind);
	projecting_rays(wind);
	mlx_hook(wind->window, 2, 0, get_keys, wind);
	mlx_hook(wind->window, 17, 0, destroy_window, wind);
	mlx_loop(wind);
	return (EXIT_SUCCESS);
}
