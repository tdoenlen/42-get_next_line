/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:54:08 by tdoenlen          #+#    #+#             */
/*   Updated: 2020/12/05 13:41:41 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_data
{
	char	buf[BUFFER_SIZE + 1];
	int		i;
	int		n;
}				t_data;

int				get_next_line(int fd, char **line);
int				fill_line(int fd, t_data *data, char **line);

#endif
