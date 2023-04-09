/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:04:18 by yomin             #+#    #+#             */
/*   Updated: 2022/06/08 18:54:08 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

typedef struct s_head
{
	int				fd_n;
	struct s_head	*next_head;
	struct s_lst	*bridge;
}	t_head;

int		find_nl(const char *buf, int size);
int		reset_buf(char *buf, const char *src, int size);
t_lst	*clear_lst(t_lst *lst);
t_lst	*reset_lst(t_lst *lst);
t_lst	*make_new_lst(int fd);
char	*get_total_buf(t_lst *lst);
char	*cpy_string(t_lst *lst);
char	*edit_lst(t_lst **lst, int fd);
char	*get_next_line(int fd);
t_head	*make_head(int fd);

#endif
