/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_str_to_wordtab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 20:27:04 by wescande          #+#    #+#             */
/*   Updated: 2016/12/26 20:30:23 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Mise a la norme par wescande
** mlx_int_str_to_wordtab.c for MinilibX in
**
** Made by Charlie Root
** Login   <ol@epitech.net>
**
** Started on  Wed Sep 13 11:36:09 2000 Charlie Root
** Last update Fri Dec 14 11:02:09 2001 Charlie Root
*/

#include "mlx_int.h"

int		mlx_int_str_str(char *str, char *find, int len)
{
	int		len_f;
	int		pos;
	char	*s;
	char	*f;

	len_f = strlen(find);
	if (len_f > len)
		return (-1);
	pos = 0;
	while (*(str + len_f - 1))
	{
		s = str;
		f = find;
		while (*(f++) == *(s++))
			if (!*f)
				return (pos);
		++str;
		++pos;
	}
	return (-1);
}

int		mlx_int_str_str_cote(char *str, char *find, int len)
{
	int		len_f;
	int		pos;
	char	*s;
	char	*f;
	int		cote;

	if ((len_f = strlen(find)) > len)
		return (-1);
	cote = 0;
	pos = 0;
	while (*(str + len_f - 1))
	{
		cote = *str == '"' ? 1 - cote : cote;
		if (!cote)
		{
			s = str;
			f = find;
			while (*(f++) == *(s++))
				if (!*f)
					return (pos);
		}
		++str;
		++pos;
	}
	return (-1);
}

char	**mlx_int_str_to_wordtab(char *str)
{
	char	**tab;
	int		pos;
	int		nb_word;
	int		len;

	len = strlen(str);
	nb_word = 0;
	pos = 0;
	while (pos < len)
	{
		while (*(str + pos) == ' ' || *(str + pos) == '\t')
			++pos;
		if (*(str + pos))
			++nb_word;
		while (*(str + pos) && *(str + pos) != ' ' && *(str + pos) != '\t')
			++pos;
	}
	if (!(tab = malloc((1 + nb_word) * sizeof(*tab))))
		return ((char **)0);
	nb_word = 0;
	pos = 0;
	while (pos < len)
	{
		while (*(str + pos) == ' ' || *(str + pos) == '\t')
		{
			*(str + pos) = 0;
			++pos;
		}
		if (*(str + pos))
		{
			tab[nb_word] = str + pos;
			++nb_word;
		}
		while (*(str + pos) && *(str + pos) != ' ' && *(str + pos) != '\t')
			++pos;
	}
	tab[nb_word] = 0;
	return (tab);
}
