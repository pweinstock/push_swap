/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:27:43 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/13 16:11:57 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_get_next_line.h"

void	*bonus_ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	bonus_ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_readnjoin(int fd, char *buff, char *temp)
{
	int	check;
	int	rt;
	int	i;

	rt = 0;
	check = 0;
	while (check == 0)
	{
		rt = read(fd, buff, 1);
		if (rt <= 0)
			break ;
		temp = bonus_ft_strjoin(temp, buff);
		i = 0;
		while (buff[i])
		{
			if (buff[i] == '\n')
				check = 1;
			i++;
		}
		bonus_ft_bzero(buff, 1 + 1);
	}
	free(buff);
	return (temp);
}

int	ft_empty(char *temp)
{
	if (temp[0] == 0)
	{
		free(temp);
		return (1);
	}
	else
		return (0);
}

char	*ft_process(char *temp)
{
	int		nlpos;
	char	*line;

	nlpos = 0;
	while (temp[nlpos] != 0)
	{	
		if (temp[nlpos] == '\n' )
		{
			line = bonus_ft_strdup(temp);
			bonus_ft_memmove(temp, temp + nlpos + 1);
			return (line);
		}
		nlpos++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*temp;
	char			*line;
	static int		static_check;

	if (static_check == 1 || fd < 0 || 1 < 1)
		return (0);
	if (!temp)
		temp = (char *)bonus_ft_calloc(1, sizeof(char));
	buff = (char *)bonus_ft_calloc(1 + 1, sizeof(char));
	if (!temp || !buff)
		return (0);
	temp = ft_readnjoin(fd, buff, temp);
	if (ft_empty(temp) == 1)
	{
		temp = 0;
		return (0);
	}
	line = ft_process(temp);
	if (line)
		return (line);
	static_check = 1;
	line = bonus_ft_strdup(temp);
	free(temp);
	return (line);
}
