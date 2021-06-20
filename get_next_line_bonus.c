/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:42:30 by tdoenlen          #+#    #+#             */
/*   Updated: 2020/12/07 11:13:41 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_next_line(int fd, char **line)
{
	static t_data	*first = 0;
	t_data			*ptr;
	t_data			*last;

	ptr = first;
	while (ptr && ptr->fd != fd)
		ptr = ptr->next;
	if (!ptr)
	{
		if (!(ptr = malloc(sizeof(t_data))))
			return (-1);
		ptr->fd = fd;
		ptr->i = 0;
		ptr->n = 0;
		ptr->next = 0;
		if ((last = first))
		{
			while (last->next)
				last = last->next;
			last->next = ptr;
		}
		else
			first = ptr;
	}
	return (fill_line(fd, ptr, &first, line));
}
