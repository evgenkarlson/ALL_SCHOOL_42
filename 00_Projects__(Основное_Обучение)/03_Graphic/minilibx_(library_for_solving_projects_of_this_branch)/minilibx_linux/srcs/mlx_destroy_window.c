/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 20:11:00 by wescande          #+#    #+#             */
/*   Updated: 2016/12/26 20:11:55 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Mise a la norme par wescande
** mlx_destroy_window.c for MinilibX in
**
** Made by Charlie Root
** Login   <ol@epitech.net>
**
** Started on  Tue Mar 12 10:25:15 2002 Charlie Root
** Last update Tue May 15 16:46:08 2007 Olivier Crouzet
*/

#include "mlx_int.h"

int	mlx_destroy_window(t_xvar *xvar, t_win_list *win)
{
	t_win_list	*w;
	t_win_list	*prev;
	t_win_list	first;

	first.next = xvar->win_list;
	prev = &first;
	w = prev->next;
	while (w)
	{
		if (w == win)
			prev->next = w->next;
		else
			prev = w;
		w = w->next;
	}
	xvar->win_list = first.next;
	XDestroyWindow(xvar->display, win->window);
	XFreeGC(xvar->display, win->gc);
	free(win);
	if (xvar->do_flush)
		XFlush(xvar->display);
}
