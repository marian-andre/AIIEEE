/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 13:57:23 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/10 19:42:26 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include "SDL.h"

# define SCREEN_WIDTH 1600
# define SCREEN_HEIGHT 1200

typedef struct		s_action
{
	int				left;
	int				right;
	int				up;
	int				down;
	int				enter;
	int				erase;
	int				pause;
}					t_action;

typedef struct		s_game
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	t_action		*action;
}					t_game;

void				ft_graphic_error(char *msg);
void				init(t_game *game, char *title);
void				cleanup(t_game *game);
void				draw(t_game *game);
void				delay(unsigned int frameLimit);

#endif
