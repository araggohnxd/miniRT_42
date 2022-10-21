/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:49:18 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/21 09:55:02 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*translate_matrix(t_tuple *point, t_tuple *translation)
{
	double	temp;
	t_tuple	*new_tuple;

	if (is_vector(point))
		return (point);
	temp = point->w;
	new_tuple = sum_tuple(point, translation);
	new_tuple->w = temp;
	return (new_tuple);
}
