/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 13:59:24 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/15 16:21:06 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "graphic.h"

void				draw(t_game *game)
{
	SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
	SDL_RenderClear(game->renderer);
	SDL_RenderPresent(game->renderer);
	SDL_Delay(1);
}

static int				ft_connect(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	sock = 0;
	if ((proto = getprotobyname("tcp")) == 0)
		ft_graphic_error("ERROR getprotobyname");
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		ft_graphic_error("ERROR socket");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr*)&sin, sizeof(sin)))
		ft_graphic_error("ERROR connect");
	return (sock);
}

int					main(int argc, char **argv)
{
	t_game			game;
	char			*line;
	int				nb_case;

	singleton(&game);
	game.sock = ft_connect(argv[1], ft_atoi(argv[2]));
	init_map(&game);
	init_time(&game);
	init_sdl(&game);
	atexit(cleanup);
	signal(SIGINT, exit);
	nb_case = game.width * game.height;
	while (nb_case-- && get_next_line(sock, &line))
		init_case(game, line);
	while (42)
	{
		display(game);
		get_next_line(sock, &line);
		ft_check_msg(game, line);
	}


/*
	while (42)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
				break ;


		SDL_RenderCopy(game->renderer, game->texture, NULL, NULL);
		SDL_RenderPresent(game->renderer);
		//draw(game);
	}
*/
	return (EXIT_SUCCESS);
}

