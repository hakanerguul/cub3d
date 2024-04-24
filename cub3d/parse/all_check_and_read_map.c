/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_check_and_read_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:36:15 by binam             #+#    #+#             */
/*   Updated: 2023/07/15 23:36:16 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_read_utils(t_data *data, t_index *index, int n_tex, char *line2)
{
	if (line2[0] != '\0' && line2[0] != '1' && line2[0] != '0'
		&& line2[0] != '2' && line2[0] != ' ')
		ft_check_text(data, line2, n_tex, index);
}

void	ft_read_map(t_data *data, char *cubfile, t_index *index, int n_tex)
{
	int		i;
	int		fd;
	char	*line;
	int		line_count;
	char	*line2;

	i = -1;
	fd = open(cubfile, O_RDONLY);
	line_count = ft_get_line_count(cubfile);
	data->map = malloc(sizeof(char *) * (line_count + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			data->map[++i] = ft_strdup(line);
			line2 = ft_strtrim(line, "\n");
			ft_read_utils(data, index, n_tex, line2);
			free(line);
			free(line2);
		}
		else
			break ;
	}
	data->map[i + 1] = 0;
}

int	ft_len(char **map)
{
	int	j;
	int	i;
	int	max;

	j = 0;
	while (map[j] && map[j][0] != '1')
		j++;
	max = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
			i++;
		if (i > max)
			max = i;
		j++;
	}
	return (max);
}

void	ft_addjust2(t_data *data)
{
	int	len;
	int	j;
	int	i;

	j = data->first_line;
	while (data->map[j])
	{
		if (data->map[j][0] == '\n')
		{
			i = 0;
			len = ft_len(data->map);
			data->map[j] = (char *)malloc(sizeof(len + 1));
			while (i <= len)
				data->map[j][i++] = '1';
			data->map[j][i] = '\0';
		}
		j++;
	}
}

void	ft_adjust(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = data->first_line;
	while (data->map[j])
	{
		i = -1;
		while (data->map[j][++i])
		{
			if (data->map[j][i] == ' ')
				data->map[j][i] = '1';
		}
		j++;
	}
	ft_addjust2(data);
}
