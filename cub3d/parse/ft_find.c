/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:37:30 by binam             #+#    #+#             */
/*   Updated: 2023/07/15 23:37:36 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_have_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j] && data->map[j][0] != '1')
		j++;
	if (data->map[j] == 0)
	{
		printf("Map Error!\n");
		ft_clear(data);
	}
}

static int	ft_find2(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N' || data->map[i][j] == 'W'
			|| data->map[i][j] == 'E' || data->map[i][j] == 'S')
		return (2);
	if (data->map[i][j] == 'F' || data->map[i][j] == 'C'
			|| data->map[i][j] == '\n')
		return (2);
	return (0);
}

void	ft_find(t_data *data, int i)
{
	int	j;

	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_find2(data, i, j) == 2)
				break ;
			if (data->map[i][j] == ' ' || data->map[i][j] == '1'
				|| data->map[i][j] == '0')
			{
				while ((data->map[i][j] != '1' || data->map[i][j] != '0')
					&& data->map[i][j])
				{
					if (data->map[i][j] == '1' || data->map[i][j] == '0')
					{
						data->first_line = i;
						return ;
					}
					j++;
				}
			}
		}
	}
}
