/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:36:00 by binam             #+#    #+#             */
/*   Updated: 2023/07/15 23:36:01 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*north_texture(t_mlx *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->where);
	if (mlx->projection_3d > WINDOW_HEIGHT)
		y = ((int)(round((i + (mlx->projection_3d - WINDOW_HEIGHT) / 2.0)
						* (1000.0 / mlx->projection_3d))) % 1000);
	else
		y = (int)round(i * (1000.0 / mlx->projection_3d)) % 1000;
	mlx->color = mlx->my_mlx.addr_n + (y * mlx->my_mlx.l_len_n + (x * 4));
	return (mlx->color);
}

char	*south_texture(t_mlx *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->where);
	if (mlx->projection_3d > WINDOW_HEIGHT)
		y = ((int)(round((i + (mlx->projection_3d - WINDOW_HEIGHT) / 2.0)
						* (1000.0 / mlx->projection_3d))) % 1000);
	else
		y = (int)round(i * (1000.0 / mlx->projection_3d)) % 1000;
	mlx->color = mlx->my_mlx.addr_s + (y * mlx->my_mlx.l_len_s + (x * 4));
	return (mlx->color);
}

char	*east_texture(t_mlx *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->where);
	if (mlx->projection_3d > WINDOW_HEIGHT)
		y = ((int)(round((i + (mlx->projection_3d - WINDOW_HEIGHT) / 2.0)
						* (1000.0 / mlx->projection_3d))) % 1000);
	else
		y = (int)round(i * (1000.0 / mlx->projection_3d)) % 1000;
	mlx->color = mlx->my_mlx.addr_e + (y * mlx->my_mlx.l_len_e + (x * 4));
	return (mlx->color);
}

char	*west_texture(t_mlx *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->where);
	if (mlx->projection_3d > WINDOW_HEIGHT)
		y = ((int)(round((i + (mlx->projection_3d - WINDOW_HEIGHT) / 2.0)
						* (1000.0 / mlx->projection_3d))) % 1000);
	else
		y = (int)round(i * (1000.0 / mlx->projection_3d)) % 1000;
	mlx->color = mlx->my_mlx.addr_w + (y * mlx->my_mlx.l_len_w + (x * 4));
	return (mlx->color);
}
