/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 15:34:08 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/16 16:59:25 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "graphic.h"
#include "libft.h"

t_game				*singleton(t_game *game)
{
	static t_game	*g = NULL;

	if (game)
		g = game;
	return (g);
}

void				cleanup(void)
{
	t_game		*game;
	int			i;

	game = singleton(NULL);
	ft_strdel2(&game->team);
	i = -1;
	while (++i < game->height)
		free(game->map[i]);
	free(game->map);
	i = -1;
	while (game->textures[++i])
		SDL_DestroyTexture(game->textures[i]);
	free(game->textures);
	SDL_DestroyRenderer(game->renderer);
	SDL_DestroyWindow(game->window);
	SDL_Quit();
}

SDL_Texture			*load_image(t_game *game, char *path, int rgb)
{
	SDL_Surface		*img;
	SDL_Texture		*texture;
	Uint32			color;

	img = SDL_LoadBMP(path);
	if (rgb != -1)
		color = SDL_MapRGB(img->format, rgb, rgb >> 8, rgb >> 16);
	if (img != NULL)
	{
		if (rgb != -1)
			SDL_SetColorKey(img, SDL_TRUE, color);
		texture = SDL_CreateTextureFromSurface(game->renderer, img);
		SDL_FreeSurface(img);
		return (texture);
	}
	else
		ft_graphic_error("img can't be load.");
	return (NULL);
}

void				display(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			ft_putnbr(game->map[i][j].food);
			ft_putchar(' ');
			ft_putnbr(game->map[i][j].linemate);
			ft_putchar(' ');
			ft_putnbr(game->map[i][j].deraumere);
			ft_putchar(' ');
			ft_putnbr(game->map[i][j].sibur);
			ft_putchar(' ');
			ft_putnbr(game->map[i][j].mendiane);
			ft_putchar(' ');
			ft_putnbr(game->map[i][j].phiras);
			ft_putchar(' ');
			ft_putnbr(game->map[i][j].thystame);
			ft_putchar(' ');
			ft_putchar('\n');
		}
		ft_putchar('\n');
	}
}
