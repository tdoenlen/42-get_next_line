/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:27:44 by tdoenlen          #+#    #+#             */
/*   Updated: 2020/12/07 07:44:24 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static t_data	data;
	static int		last_fd = -1;
	int				ret;

	if (fd < 0)
		return (-1);
	if (last_fd != fd)
	{
		last_fd = fd;
		data.i = 0;
		data.n = 0;
	}
	if ((ret = fill_line(fd, &data, line)) != 1)
		last_fd = -1;
	return (ret);
}
