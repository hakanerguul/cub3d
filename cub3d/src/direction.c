/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:34:58 by binam             #+#    #+#             */
/*   Updated: 2023/07/15 23:34:59 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	check_north_west(double w_y, double w_x, t_mlx *wind)
{
	if ((int)(w_y + 1) % 64 == 0 && wind->map[(int)(w_y / 64.0)
			+ 1][(int)(w_x / 64.0)] == '0')
	{
		wind->where = w_x;
		return ('N');
	}
	else
	{
		wind->where = w_y;
		return ('W');
	}
}

char	check_north_east(double w_y, double w_x, t_mlx *wind)
{
	if ((int)(w_y + 1) % 64 == 0 && wind->map[(int)((w_y / 64.0)
			+ 1)][(int)(w_x / 64.0)] == '0')
	{
		wind->where = w_x;
		return ('N');
	}
	else
	{
		wind->where = w_y;
		return ('E');
	}
}

char	check_south_east(double w_y, double w_x, t_mlx *wind)
{
	if ((int)(w_y) % 64 == 0 && wind->map[(int)((w_y / 64.0)
			- 1)][(int)(w_x / 64.0)] == '0')
	{
		wind->where = w_x;
		return ('S');
	}
	else
	{
		wind->where = w_y;
		return ('E');
	}
}

char	check_south_west(double w_y, double w_x, t_mlx *wind)
{
	if ((int)(w_y) % 64 == 0 && wind->map[(int)((w_y / 64.0)
			- 1)][(int)(w_x / 64.0)] == '0')
	{
		wind->where = w_x;
		return ('S');
	}
	else
	{
		wind->where = w_y;
		return ('W');
	}
}

char	set_directions(double w_y, double w_x, t_mlx *wind)
{
	if (wind->y_player > w_y && wind->x_player > w_x)
		return (check_north_west(w_y, w_x, wind));
	else if (wind->y_player > w_y && wind->x_player < w_x)
		return (check_north_east(w_y, w_x, wind));
	else if (wind->y_player <= w_y && wind->x_player <= w_x)
		return (check_south_east(w_y, w_x, wind));
	else if (wind->y_player <= w_y && wind->x_player >= w_x)
		return (check_south_west(w_y, w_x, wind));
	return (0);
}
