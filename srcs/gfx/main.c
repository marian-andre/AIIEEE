/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 13:59:24 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/16 17:51:27 by rkorimba         ###   ########.fr       */
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

static int			ft_connect(char *addr, int port)
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

	if (argc != 3)
		ft_graphic_usage();
	singleton(&game);
	game.sock = ft_connect(argv[1], ft_atoi(argv[2]));
	init_map(&game);
	init_time(&game);
	init_sdl(&game);
	atexit(cleanup);
	signal(SIGINT, exit);
	nb_case = game.width * game.height;
	while (nb_case-- && get_next_line(game.sock, &line))
		init_case(&game, line);
	init_client(&game);
	while (42)
	{
		draw_render(&game);
		get_next_line(game.sock, &line);
		ft_check_msg(&game, line);
	}
	return (EXIT_SUCCESS);
}
