/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_wait_first_expose.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 20:30:43 by wescande          #+#    #+#             */
/*   Updated: 2016/12/26 20:44:20 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Mise a la norme par wescande
** mlx_int_wait_first_expose.c for minilibx in
**
** Made by olivier crouzet
** Login   <ol@epita.fr>
**
** Started on  Tue Oct 17 09:26:45 2000 olivier crouzet
** Last update Fri Feb 23 17:27:10 2001 Charlie Root
*/

#include "mlx_int.h"

int	mlx_int_wait_first_expose(t_xvar *xvar, Window win)
{
	XEvent	ev;

	XWindowEvent(xvar->display, win, ExposureMask, &ev);
	XPutBackEvent(xvar->display, &ev);
}
