/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:23:27 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/21 12:30:25 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	sub_main(int argc, char **argv)
{
	t_scene	*scene;
	int		fd;

	if (errors(argc, argv, &fd))
		return (EXIT_FAILURE);
	scene = (t_scene *)malloc(sizeof(t_scene));
	if (parser_1(fd, scene))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (sub_main(argc, argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
