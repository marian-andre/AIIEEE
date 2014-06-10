/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 13:59:24 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/10 19:38:57 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "graphic.h"

void				init(t_game *game, char *title)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_graphic_error("SDL initialization has failed.");
	/* creation de la fenetre */
	game->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
									SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	/* creation d'un rendu graphique */
	game->renderer = SDL_CreateRenderer(game->window, -1,
										SDL_RENDERER_PRESENTVSYNC);
	if (game->window == NULL || game->renderer == NULL)
		ft_graphic_error("screen mode initialization is impossible.");
	game->texture = NULL;
	/* cacher le curseur de la souris */
	//SDL_ShowCursor(SDL_DISABLE);
}

void				cleanup(t_game *game)
{
	if (game->texture != NULL)
	{
		SDL_DestroyTexture(game->texture);
		game->texture = NULL;
	}
	SDL_DestroyRenderer(game->renderer);
	game->renderer = NULL;
	SDL_DestroyWindow(game->window);
	game->window = NULL;
    SDL_Quit();
}

void				draw(t_game *game)
{
	SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
	SDL_RenderClear(game->renderer);
	SDL_RenderPresent(game->renderer);
	SDL_Delay(1);
}

void				delay(unsigned int frameLimit)
{
	unsigned int	ticks;

	ticks = SDL_GetTicks();

	if (frameLimit < ticks)
		return ;
	if (frameLimit > ticks + 16)
		SDL_Delay(16);
	else
	    SDL_Delay(frameLimit - ticks);
}

void				loadImage(t_game *game, char *path)
{
	/* Charge les images avec SDL Image dans une SDL_Surface */
	SDL_Surface		*img;

	img = SDL_LoadBMP(path);
	if (img != NULL)
	{
		/* Conversion de l'image en texture */
		game->texture = SDL_CreateTextureFromSurface(game->renderer, img);
		/* On se débarrasse du pointeur vers une surface */
		SDL_FreeSurface(img);
		img = NULL;
	}
	else
		ft_graphic_error("img can't be load.");
}

int loadResources(t_game *game)
{
	loadImage(game, "srcs/gfx/image/tileset.bmp");
	if (game->texture == NULL)
		ft_graphic_error("tileset.bmp loading has failed.");
	return (EXIT_SUCCESS);
}

int					main(int argc, char **argv)
{
	unsigned int	frameLimit;
	t_game			*game;
	SDL_Event		event;

	argc = argc + 0;
	argv = argv + 0;
	frameLimit = SDL_GetTicks() + 16;
	if ((game = (t_game*)malloc(sizeof(t_game))) == NULL)
		exit(EXIT_FAILURE);
	init(game, "Zappy");
	loadResources(game);
	while (42)
	{
		if (SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				break ;
		}
		SDL_RenderCopy(game->renderer, game->texture, NULL, NULL);
		SDL_RenderPresent(game->renderer);
		//draw(game);
		delay(frameLimit);
		frameLimit = SDL_GetTicks() + 16;
		sleep(6);
		break ;
	}
	cleanup(game);
	return (EXIT_SUCCESS);
}
