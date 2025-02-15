/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                   SERVER   */
/* ************************************************************************** */
/*   • ./server                                                               */
/*   • Le serveur va donner son propre pid.                                   */
/* ************************************************************************** */
#include "ft_server.h"

// -------------------------------PROTOTYPE-----------------------------
int			main(void);
void		ft_sigaction(int signo, siginfo_t *info, void *context);
void		ft_print(pid_t pid, char **msg, int *len, int *i);
// ---------------------------------------------------------------------

int	main(void)
{
	struct sigaction	sig;

	ft_header_server(getpid());
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_sigaction;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}

void	ft_sigaction(int signo, siginfo_t *info, void *context)
{
	static int	i;
	static int	len;
	static char	*msg;

	(void)context;
	if (i <= 30)
		len = ft_length(signo, len);
	else if (i == 31)
		msg = ft_alloc(len);
	else if (i < len * 8 + 32)
		ft_fill(&msg, &i, signo);
	i++;
	if (i == len * 8 + 32)
		ft_print(info->si_pid, &msg, &len, &i);
	else
		kill(info->si_pid, SIGUSR2);
}

// bonus : kill() l.3
void	ft_print(pid_t pid, char **msg, int *len, int *i)
{
	write(1, *msg, ft_strlen(*msg));
	write(1, "\n", 1);
	kill(pid, SIGUSR1);
	free(*msg);
	*msg = NULL;
	*len = 0;
	*i = 0;
}
