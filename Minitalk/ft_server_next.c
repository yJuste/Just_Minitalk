/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_server.h"

// ---------------------------PROTOTYPE---------------------------
int			ft_length(int signo, int len, pid_t pid);
char		*ft_alloc(int len);
void		ft_fill(char **msg, int *i, int signo, pid_t pid);
void		ft_header_server(pid_t pid);
void		ft_print_pid(pid_t pid);
// ---------------------------------------------------------------

int	ft_length(int signo, int len, pid_t pid)
{
	len = len >> 1;
	if (signo == SIGUSR2)
		len |= 1 << 30;
	kill(pid, SIGUSR2);
	return (len);
}

char	*ft_alloc(int len)
{
	char		*msg;

	msg = ft_calloc(len + 1, sizeof(char));
	if (!msg)
	{
		write(1, "Error, allocation failed.\n", 26);
		exit(1);
	}
	msg[len] = '\0';
	return (msg);
}

void	ft_fill(char **msg, int *i, int signo, pid_t pid)
{
	int		j;
	int		k;

	j = (*i - 32) / 8;
	k = (*i - 32) % 8;
	if (signo == SIGUSR2)
		(*msg)[j] |= (1 << (7 - k));
	kill(pid, SIGUSR2);
}

//	---------- HEADER ----------

void	ft_header_server(pid_t pid)
{
	write(1, "\033[0;32m . --------------------=== \033[0m\033[5;42;92m M", 50);
	write(1, "INITALK \033[0m\033[0;32m ===-------------------- . \033[0m", 50);
	write(1, "\n", 1);
	write(1, "\033[0;32m{\033[0m\033[1;92m   ____    ____   _           ", 49);
	write(1, "  _   _          __   __        \033[0m\033[0;32m}\033[0m\n", 49);
	write(1, "\033[0;32m{\033[0m\033[1;92m  |_   \\  /   _| (_)          ", 49);
	write(1, " (_) / |_       [  | [  |  _    \033[0m\033[0;32m}\033[0m\n", 49);
	write(1, "\033[0;32m{\033[0m\033[1;92m    |   \\/   |   __   _ .--.  ", 49);
	write(1, " __ `| |-',--.   | |  | | / ]   \033[0m\033[0;32m}\033[0m\n", 49);
	write(1, "\033[0;32m{\033[0m\033[1;92m    | |\\  /| |  [  | [ `.-. | ", 49);
	write(1, "[  | | | `'_\\ :  | |  | '' <    \033[0m\033[0;32m}\033[0m", 48);
	write(1, "\n", 1);
	write(1, "\033[0;32m{\033[0m\033[1;92m   _| |_\\/_| |_  | |  | | | | ", 49);
	write(1, " | | | |,// | |, | |  | |`\\ \\   \033[0m\033[0;32m}\033[0m", 48);
	write(1, "\n", 1);
	write(1, "\033[0;32m{\033[0m\033[1;92m  |_____||_____|[___][___||__][", 50);
	write(1, "___]\\__/\\'-;__/[___][__|  \\_]  \033[0m\033[0;32m}\033[0m", 47);
	write(1, "\n", 1);
	write(1, "\033[0;32m{\033[0m\033[1;92m                              ", 49);
	write(1, "                                \033[0m\033[0;32m}\033[0m\n", 49);
	write(1, "\033[0;32m . --- \033[0m\033[1;92mSERVER\033[0m", 35);
	write(1, "\033[0;32m ---------------------------------- \033[0m", 47);
	write(1, "\033[1;92mby Juste\033[0m\033[0;32m --- . \033[0m\n", 38);
	ft_print_pid(pid);
}

void	ft_print_pid(pid_t pid)
{
	int		i;

	i = 11;
	write(1, "\033[0;32m{\033[0m\033[2;32m      ", 25);
	write(1, "-> Your PID: \033[0m\033[1;92m\033[0m\033[0;42;97m ", 39);
	ft_putnbr(pid);
	i -= ft_intlen(pid);
	write(1, " \033[0m", 5);
	while (--i > 0)
		write(1, " ", 1);
	write(1, "                               \033[0;32m}\033[0m\n", 44);
	write(1, "\033[0;32m . --------------------------", 36);
	write(1, "-------------------------------- . \033[0m\n", 40);
	write(1, "\n", 1);
}
