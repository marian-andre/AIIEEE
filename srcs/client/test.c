/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:17:27 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/06 20:07:44 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

static int				create_server()
{
	struct protoent		*proto;
	struct sockaddr_in	sin;
	int					sock;

	if ((proto = getprotobyname("tcp")) == 0)
		ft_error("ERROR : getprobyname");
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		ft_error("ERROR : socket");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(4242);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr*)&sin, sizeof(sin)) == -1)
		ft_error("ERROR : bind");
	if (listen(sock, 1) == -1)
		ft_error("ERROR : listen");
	return (sock);
}

int						main()
{
	int					sock;
	int					cs;
	char				line[256];
	unsigned int		cslen;
	struct sockaddr_in	*csin;

	bzero(line, 256);
	sock = create_server();
	printf("ok\n");
	if ((cs = accept(sock, (struct sockaddr*)&csin, &cslen)) == -1)
		ft_error("ERROR : accept");
	write(cs, "BIENVENUE\n", 10);
	read(cs, &line, 255);
	printf("%s", line);
	write(cs, "0\n", 10);
	write(cs, "50 13\n", 10);
	close(sock);
	return (EXIT_SUCCESS);
}
