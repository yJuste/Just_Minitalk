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
/*                                                                   CLIENT   */
/* ************************************************************************** */
/*   • ./client [ PID ] [ Message ]                                           */
/*      -> PID : donné par le serveur.                                        */
/* ************************************************************************** */
#include "ft_client.h"

// ---------------------PROTOTYPE---------------------
int			main(int argc, char **argv);
int			ft_client_next(char **argv);
void		ft_send_length(pid_t pid, int len);
void		ft_send_message(pid_t pid, char *msg);
// ---------------------------------------------------

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

// Don't start an another app like Youtube or something like this
// 'cause it disrupts the signals.
int	ft_client_next(char **argv)
{
	pid_t		pid;
	int			len;

	pid = ft_atoi(argv[1]);
	if (pid == 0 || kill(pid, 0))
		return (write(1, "Invalid pid.\n", 13), 3);
	len = ft_strlen(argv[2]);
	signal(SIGUSR1, ft_signal_handler);
	signal(SIGUSR2, ft_signal_handler);
	ft_send_length(pid, len);
	ft_send_message(pid, argv[2]);
	return (0);
}

void	ft_send_length(pid_t pid, int len)
{
	int		i;

	i = 0;
	while (i <= 31)
	{
		if (len & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		ft_usleep();
		len = len >> 1;
		i++;
	}
}

void	ft_send_message(pid_t pid, char *msg)
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
			if (msg[i] & (1 << j))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			ft_usleep();
			j--;
		}
		i++;
	}
}
