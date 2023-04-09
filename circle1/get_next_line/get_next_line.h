/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:51:40 by yomin             #+#    #+#             */
/*   Updated: 2022/06/05 20:30:36 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>

typedef struct s_lst
{
	char			data[BUFFER_SIZE];
	int				data_len;
	int				flag;
	struct s_lst	*next;
}	t_lst;

int		find_nl(const char *buf, int size);
int		reset_buf(char *buf, const char *src, int size);
t_lst	*clear_lst(t_lst *lst);
t_lst	*reset_lst(t_lst *lst);
t_lst	*make_new_lst(int fd);
char	*get_total_buf(t_lst *lst);
char	*cpy_string(t_lst *lst);
char	*get_next_line(int fd);

#endif
