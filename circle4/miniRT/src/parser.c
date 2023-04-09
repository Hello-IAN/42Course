/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:13:04 by yomin             #+#    #+#             */
/*   Updated: 2023/02/16 21:13:06 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1_ptr = (const unsigned char *)s1;
	const unsigned char	*s2_ptr = (const unsigned char *)s2;

	while (n--)
	{
		if (*s1_ptr == 0 || *s2_ptr == 0)
			return (*s1_ptr - *s2_ptr);
		if (*s1_ptr != *s2_ptr)
			return (*s1_ptr - *s2_ptr);
		++s1_ptr;
		++s2_ptr;
	}
	return (0);
}

int	check_file_name(const char *argv)
{
	char	*ptr;

	ptr = ft_strrchr(argv, '.');
	if (!ptr)
		return (0);
	if (ft_strcmp(ptr, ".rt") == 0)
		return (1);
	return (0);
}

int	vaild_check(char *argv)
{
	if (!argv)
	{
		write(2, "Error\n", 6);
		return (write(2, "filename dose not exist\n", 24));
	}
	else if (!check_file_name(argv))
	{
		write(2, "Error\n", 6);
		return (write(2, "wrong File name format\n", 23));
	}
	return (0);
}

static void	check_type_inline(const char *line, t_vars *vars)
{
	if (ft_strncmp(line, "A", 1) == 0)
		set_ambient_light(line, vars);
	else if (ft_strncmp(line, "C", 1) == 0)
		set_cam(line, vars);
	else if (ft_strncmp(line, "L", 1) == 0)
		set_light(line, vars);
	else if (ft_strncmp(line, "sp", 2) == 0)
		set_sphere(line, vars);
	else if (ft_strncmp(line, "cy", 2) == 0)
		set_cylinder(line, vars);
	else if (ft_strncmp(line, "pl", 2) == 0)
		set_plane(line, vars);
	else if (ft_strncmp(line, "\n", 1) == 0)
		return ;
	else
		execute_err(1);
}

void	parse(const char *filename, t_vars *vars)
{
	const int	open_fd = open(filename, 0644, O_RDONLY);
	char		*line;

	if (open_fd == -1)
		execute_err(3);
	line = get_next_line(open_fd);
	while (line != NULL)
	{
		check_type_inline(line, vars);
		free(line);
		line = get_next_line(open_fd);
	}
	close(open_fd);
}
