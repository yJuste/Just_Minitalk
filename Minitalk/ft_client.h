/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_CLIENT_H
# define FT_CLIENT_H

// Standard Libraries

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

//	---------- MY CODE ----------

// ft_client.c

int		main(int argc, char **argv);
int		ft_client_next(pid_t pid, char **argv, int len, int delay);
void	ft_send_length(pid_t pid, int len, int delay);
void	ft_send_message(pid_t pid, char *msg, int delay);
void	ft_signal_handler(int signo);

// ft_client_lib.c

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

#endif
