/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   -> Use : a.out <pid> <message>                                  CLIENT   */
/* ************************************************************************** */

#include "ft_client.h"

// -----------------------PROTOTYPE----------------------
int		main(int argc, char **argv);
int		ft_client_next(char **argv);
void	ft_send_length(pid_t pid, int len, int delay);
void	ft_send_message(pid_t pid, char *msg, int delay);
void	ft_header_client(void);
// ------------------------------------------------------

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (write(2, "Too few arguments.\n", 19), 1);
	if (argc > 3)
		return (write(2, "Too many arguments.\n", 20), 2);
	if (argc == 3)
	{
		if (ft_client_next(argv) == 3)
			return (3);
	}
	return (0);
}

int	ft_client_next(char **argv)
{
	pid_t		pid;
	int			len;
	int			delay;

	pid = ft_atoi(argv[1]);
	if (pid == 0 || kill(pid, 0))
		return (write(2, "Invalid pid.\n", 13), 3);
	ft_header_client();
	len = ft_strlen(argv[2]);
	delay = 25;
	if (len > 1000)
		delay = 35;
	if (len > 25000)
		delay = 60;
	if (len > 50000)
		delay = 100;
	ft_send_length(pid, len, delay);
	ft_send_message(pid, argv[2], delay);
	return (0);
}

void	ft_send_length(pid_t pid, int len, int delay)
{
	int		i;

	i = 0;
	while (i <= 31)
	{
		if (len & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		usleep(delay);
		i++;
	}
}

void	ft_send_message(pid_t pid, char *msg, int delay)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (msg[i])
	{
		j = 7;
		while (j >= 0)
		{
			usleep(delay);
			if (msg[i] & (1 << j))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			j--;
		}
		i++;
	}
}

//	---------- HEADER ----------

void	ft_header_client(void)
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
	write(1, "\033[0;32m . --- \033[0m\033[1;92mCLIENT\033[0m", 35);
	write(1, "\033[0;32m ---------------------------------- \033[0m", 47);
	write(1, "\033[1;92mby Juste\033[0m\033[0;32m --- . \033[0m\n", 38);
}
