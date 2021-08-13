/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_next_line.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:28:15 by pweinsto          #+#    #+#             */
/*   Updated: 2021/08/13 16:12:27 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_GET_NEXT_LINE_H
# define BONUS_GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	bonus_ft_strlen(const char *str);
char	*bonus_ft_strjoin(char *s1, char *s2);
char	*bonus_ft_strdup(const char *s1);
void	bonus_ft_bzero(void *s, size_t n);
int		bonus_ft_memmove(char *dst, char *src);
void	*bonus_ft_calloc(size_t count, size_t size);
char	*ft_readnjoin(int fd, char *buff, char *temp);
char	*ft_process(char *temp);
int		ft_empty(char *temp);

#endif