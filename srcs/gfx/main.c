/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 13:59:24 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/21 14:40:41 by rkorimba         ###   ########.fr       */
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
	struct hostent		*host;

	sock = 0;
	if ((proto = getprotobyname("tcp")) == 0)
		ft_graphic_error("ERROR getprotobyname");
	if ((host = gethostbyname(addr)) == NULL)
		ft_graphic_error("ERROR gethostbyname");
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		ft_graphic_error("ERROR socket");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	ft_memcpy(&(sin.sin_addr.s_addr), host->h_addr, host->h_length);
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
	{
		ft_graph_bct(&game, line);
		free(line);
	}
	init_client(&game);
	while (get_next_line(game.sock, &line) > 0)
	{
//		ft_putendl(line);
		if (line != NULL)
			ft_check_msg(&game, line);
		draw_render(&game);
		free(line);
		line = NULL;
	}
	exit(EXIT_SUCCESS);
	return(EXIT_SUCCESS);
}

