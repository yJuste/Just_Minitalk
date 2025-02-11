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

// --------------------------PROTOTYPE---------------------------
int			main(int argc, char **argv);
int			ft_client_next(char **argv);
void		ft_send_length(pid_t pid, int len, int delay);
void		ft_send_message(pid_t pid, char *msg, int delay);
void		ft_signal_handler(int signo);
// --------------------------------------------------------------

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

// bonus : signal() l.18 | pause() l.21
// Delays is way long with 42's pcs, in my Mac it's :
//	..->15, len>10000->35, len>25000->60, len>50000->100
// Don't start an other app like Youtube or something like this
// 'cause it disrupts the signals.
int	ft_client_next(char **argv)
{
	pid_t		pid;
	int			len;
	int			delay;

	pid = ft_atoi(argv[1]);
	if (pid == 0 || kill(pid, 0))
		return (write(1, "Invalid pid.\n", 13), 3);
	len = ft_strlen(argv[2]);
	delay = 15;
	signal(SIGUSR1, ft_signal_handler);
	ft_send_length(pid, len, delay);
	ft_send_message(pid, argv[2], delay);
	pause();
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
	signal(SIGUSR2, ft_signal_handler);
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
			pause();
			j--;
		}
		i++;
	}
}

// bonus : ft_signal_handler
void	ft_signal_handler(int signo)
{
	if (signo == SIGUSR1)
		write(1, "Message received\n", 17);
}
