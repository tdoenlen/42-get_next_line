/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdoenlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:42:10 by tdoenlen          #+#    #+#             */
/*   Updated: 2020/12/06 10:15:07 by tdoenlen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_data
{
	int		fd;
	char	buf[BUFFER_SIZE + 1];
	int		i;
	int		n;
	void	*next;
}				t_data;

int				get_next_line(int fd, char **line);
int				fill_line(int fd, t_data *data, t_data **first, char **line);

#endif
