/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:29:07 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/18 14:16:10 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	parse_line(char **line_splited)
{
	int	errors;

	errors = 0;
	if (line_splited[0][0] == LIGHT)
		errors = check_light(line_splited);
	else if (line_splited[0][0] == AMBIENT)
		errors = check_ambient(line_splited);
	else if (line_splited[0][0] == CAMERA)
		errors = check_camera(line_splited);
	if (!errors)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	parser_1(int fd)
{
	char		*line;
	char		**line_splited;

	(void)fd;
	int fd_1 = open("../rt_files/many_obj.rt", O_RDONLY);
	line = ft_gnl(fd_1, FALSE);
	while (line)
	{
		line = ft_strtrim_free(line, " ");
		line_splited = ft_split(line, ' ');
		free(line);
		if (line_splited)
		{
			parse_line(line_splited);
			ft_free_matrix((void *)&line_splited);
		}
		line = ft_gnl(fd_1, FALSE);
	}
	return (EXIT_SUCCESS);
}
