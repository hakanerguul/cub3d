/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:35:06 by binam             #+#    #+#             */
/*   Updated: 2023/07/15 23:35:07 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	images_to_xpm(t_mlx *wind)
{
	int	h;
	int	w;

	wind->n_xpm = mlx_xpm_file_to_image(wind->mlx,
			wind->data->north_path, &w, &h);
	wind->s_xpm = mlx_xpm_file_to_image(wind->mlx,
			wind->data->south_path, &w, &h);
	wind->e_xpm = mlx_xpm_file_to_image(wind->mlx,
			wind->data->east_path, &w, &h);
	wind->w_xpm = mlx_xpm_file_to_image(wind->mlx,
			wind->data->west_path, &w, &h);
	if (!wind->n_xpm || !wind->s_xpm || !wind->w_xpm || !wind->e_xpm)
	{
		printf ("Error Loading Textures\n");
		exit(1);
	}
	wind->my_mlx.addr_n = mlx_get_data_addr(wind->n_xpm, &wind->my_mlx.bpp_n,
			&wind->my_mlx.l_len_n, &wind->my_mlx.endian_n);
	wind->my_mlx.addr_s = mlx_get_data_addr(wind->s_xpm, &wind->my_mlx.bpp_s,
			&wind->my_mlx.l_len_s, &wind->my_mlx.endian_s);
	wind->my_mlx.addr_w = mlx_get_data_addr(wind->w_xpm, &wind->my_mlx.bpp_w,
			&wind->my_mlx.l_len_w, &wind->my_mlx.endian_w);
	wind->my_mlx.addr_e = mlx_get_data_addr(wind->e_xpm, &wind->my_mlx.bpp_e,
			&wind->my_mlx.l_len_e, &wind->my_mlx.endian_e);
}
