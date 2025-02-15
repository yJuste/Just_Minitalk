/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_lib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_client.h"

// -------------------PROTOTYPE------------------
void		ft_send_signal(void);
void		ft_signal_handler(int signo);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
// ----------------------------------------------

int	g_signal = 0;

void	ft_usleep(void)
{
	int		try;

	try = 0;
	g_signal = 0;
	while (!g_signal)
	{
		try++;
		if (try >= 500)
			return ;
		usleep(1);
	}
}

// bonus : ft_signal_handler
void	ft_signal_handler(int signo)
{
	if (signo == SIGUSR1)
		write(1, "Message received\n", 17);
	else
		g_signal = 1;
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
