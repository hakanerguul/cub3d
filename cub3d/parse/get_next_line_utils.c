/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:37:52 by binam             #+#    #+#             */
/*   Updated: 2023/07/15 23:37:53 by binam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_controller(char *str, const char c, t_list *y)
{
	int		i;

	i = -1;
	if (!*str)
	{
		y->x = (void *)0;
		return (str);
	}
	while (str[++i])
	{
		if (str[i] == c)
		{
			y->x = ft_cutter(str, c, i);
			i++;
			y->next = ft_lstnew();
			y->next->x = ft_strdup(&str[i]);
			free(str);
			return (y->x);
		}
	}
	return (y->x);
}

int	ft_chk(const char *a, int chker, int c)
{
	int	i;

	i = 0;
	if (chker == 0)
	{
		while (a && a[i] != 0)
			i++;
		return (i);
	}
	if (!a)
		return (1);
	else if (chker == 1)
	{
		i = -1;
		while (a[++i] != 0)
			if (a[i] == c)
				return (0);
		return (1);
	}
	return (0);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*all;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = 0;
	}
	all = malloc(sizeof(char) * (ft_chk(s1, 0, 0) + ft_chk(s2, 0, 0) + 1));
	while (s1[++i])
		all[i] = s1[i];
	while (s2 && s2[++j])
		all[i++] = s2[j];
	all[i] = '\0';
	free(s1);
	return (all);
}

char	*ft_strdup(const char *s1)
{
	char	*newrepo;
	int		i;

	i = -1;
	newrepo = malloc(sizeof(char) * (ft_chk(s1, 0, 0) + 1));
	if (!newrepo)
		return (0);
	while (s1 && s1[++i])
		newrepo[i] = s1[i];
	newrepo[i] = 0;
	return (newrepo);
}

char	*ft_cutter(char *str, char c, int i)
{
	char	*temp;
	int		j;

	j = 0;
	if (!str)
	{
		str = malloc(sizeof(char));
		str[0] = 0;
	}
	temp = malloc(sizeof(char) * i + 2);
	while (j != i)
	{
		temp[j] = str[j];
		j++;
	}
	temp[j++] = c;
	temp[j] = '\0';
	return (temp);
}
