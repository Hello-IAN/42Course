/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:13:22 by yomin             #+#    #+#             */
/*   Updated: 2023/02/23 16:15:53 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

/* check err case,
get param int
1 is invalid value
2 is failed allocate 
3 is failed open*/
void	execute_err(int n)
{
	write(2, "Error\n", 6);
	if (n == 1)
		write(2, "invalid value detected\n", 23);
	else if (n == 2)
		write(2, "failed to allocate memory\n", 26);
	else if (n == 3)
		write(2, "cannot found file or file is empty\n", 35);
	exit(0);
}

/* function 3
check a validation about splited info
if each value cnt is over than 3, exit
*/
static char	**split_by_options(char *str)
{
	int		i;
	char	**return_string;

	if (!str)
		execute_err(1);
	return_string = ft_split(str, ',');
	if (!return_string)
		execute_err(1);
	i = 0;
	while (return_string[i])
		++i;
	if (i > 3)
		execute_err(1);
	return (return_string);
}

/* 
t_options object will has string splited by comma,
if fail to allocate or origin string is empty
return NULL.
otherwise, success to calling splited by comma func,
return t_options and also
free a temp string value.*/
t_options	*get_options(const char *str)
{
	int			i;
	char		**temp;
	t_options	*options;

	options = malloc(sizeof(t_options));
	if (!options)
		return (NULL);
	ft_memset(options, 0, sizeof(t_options));
	temp = ft_split(str, ' ');
	if (!temp)
	{
		free(options);
		return (NULL);
	}
	i = 0;
	options->option_cnt = i;
	while (temp[++i] && i < 6)
		options->option[i - 1] = split_by_options(temp[i]);
	if (i != 0)
		options->option_cnt = i - 1;
	while (0 <= --i)
		free(temp[i]);
	free(temp);
	return (options);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*s1_ptr = (const unsigned char *)s1;
	const unsigned char	*s2_ptr = (const unsigned char *)s2;

	while (*s1_ptr && *s2_ptr)
	{
		if (*s1_ptr != *s2_ptr)
			return (*s1_ptr - *s2_ptr);
		++s1_ptr;
		++s2_ptr;
	}
	return (*s1_ptr - *s2_ptr);
}
