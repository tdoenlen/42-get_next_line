/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:42:55 by tdoenlen          #+#    #+#             */
/*   Updated: 2020/12/07 11:15:55 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int				del_data(int fd, t_data **first, int ret)
{
	t_data *ptr;
	t_data *next;

	if (ret == 1)
		return (1);
	ptr = *first;
	if ((*first)->fd == fd)
	{
		*first = ptr->next;
		free(ptr);
		return (ret);
	}
	while (((t_data *)ptr->next)->fd != fd)
		ptr = ptr->next;
	next = ptr->next;
	ptr->next = next->next;
	free(next);
	return (ret);
}

unsigned long	allocation_size(t_data *data)
{
	unsigned long	size;
	int				i;

	size = 1;
	i = data->i;
	while (data->buf[i] != '\n' && i < data->n)
	{
		i++;
		size++;
	}
	return (size);
}

int				extend_str(char **str, t_data *data, unsigned long size)
{
	char			*new;
	unsigned long	i;

	if (!data->n)
		return (0);
	i = 0;
	if (!(new = malloc(size + allocation_size(data))))
		return (1);
	while (i < size)
	{
		new[i] = (*str)[i];
		i++;
	}
	free(*str);
	*str = new;
	return (0);
}

int				end(char *ret, unsigned long ret_i, char **line, t_data *data)
{
	ret[ret_i] = 0;
	*line = ret;
	if (data->i++ == data->n)
		return (0);
	return (1);
}

int				fill_line(int fd, t_data *data, t_data **first, char **line)
{
	unsigned long	ret_i;
	char			*ret;

	ret_i = 0;
	ret = 0;
	while (1)
	{
		if (!ret && !(ret = malloc(allocation_size(data))))
			return (del_data(fd, first, -1));
		if (data->i == data->n && !(data->i = 0))
			if ((data->n = read(fd, data->buf, BUFFER_SIZE)) == -1
					|| extend_str(&ret, data, ret_i))
			{
				free(ret);
				return (del_data(fd, first, -1));
			}
		while (data->buf[data->i] != '\n' && data->i < data->n)
			ret[ret_i++] = data->buf[data->i++];
		if (data->buf[data->i] == '\n'
				|| (data->i == data->n && data->n < BUFFER_SIZE))
			return (del_data(fd, first, end(ret, ret_i, line, data)));
	}
}
