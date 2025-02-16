/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:08:24 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/19 20:29:27 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_canvas	*create_canvas(void *mlx, int width, int height)
{
	t_canvas	*canvas;

	canvas = (t_canvas *)malloc(sizeof(t_canvas));
	if (!canvas)
		return (NULL);
	canvas->image = mlx_new_image(mlx, width, height);
	if (!canvas->image)
		return (free(canvas), NULL);
	canvas->address = mlx_get_data_addr(
			canvas->image,
			&canvas->bits_per_pixel,
			&canvas->line_length,
			&canvas->endianness);
	if (!canvas->address)
	{
		mlx_destroy_image(mlx, canvas->image);
		free(canvas);
		return (NULL);
	}
	return (canvas);
}
