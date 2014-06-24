/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_resources.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 10:01:05 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/24 10:36:48 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void		ft_show_case(SDL_Rect *src, SDL_Rect *dst, t_game *g)
{
    src->x = 0;
    src->y = 0;
    src->h = 360;
    src->w = 240;
    dst->x = g->width * MAP_SIZE_W;
    dst->y = 0;
    dst->h = 360;
    dst->w = 240;
	SDL_RenderCopy(g->renderer, g->textures[22], src, dst);
}

void		ft_show_resources(SDL_Rect *src, SDL_Rect *dst, t_game *g)
{
//SDL_Rect pos;
//SDL_Event event;

	ft_show_case(src, dst, g);
/*	while (1)
	{
		SDL_PollEvent(&event);
		if (event.type != SDL_QUIT)
		{
			if (event.type == SDL_MOUSEBUTTONUP)
			{
				pos.x = event.button.x;
				pos.y = event.button.y;
				break;
			}
		}
		}*/
}
