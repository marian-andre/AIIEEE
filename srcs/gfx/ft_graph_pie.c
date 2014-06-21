/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:02:26 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/21 17:33:53 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "libft.h"

void		ft_graph_pie(t_game *game, char *line)
{
	char		**tab;
	SDL_Rect	s;
	SDL_Rect	d;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("ft_strsplit failed in ft_graph_pie");
	s.x = 0;
	s.y = 0;
	s.h = MAP_SIZE_H;
	s.w = MAP_SIZE_W;
	d.x = ft_atoi(tab[1]) * MAP_SIZE_W;
	d.y = ft_atoi(tab[1]) * MAP_SIZE_H;
	SDL_RenderCopy(game->renderer, game->textures[13], &s, &d);
	SDL_RenderPresent(game->renderer);
}
