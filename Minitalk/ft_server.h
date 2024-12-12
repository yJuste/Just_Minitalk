/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SERVER_H
# define FT_SERVER_H

// Standard Libraries

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

//	---------- MY CODE ----------

// ft_server.c

int			main(void);
void		ft_sigaction(int signo, siginfo_t *info, void *context);
void		ft_print(char **msg, int *len, int *i);

// ft_server_next.c

int			ft_length(int signo, int len);
char		*ft_alloc(int len);
void		ft_fill(char **msg, int *i, int signo);
void		ft_header_server(pid_t pid);
void		ft_print_pid(pid_t pid);

// ft_server_lib.c

void		*ft_calloc(size_t count, size_t size);
void		ft_putnbr(int n);
int			ft_intlen(long n);
size_t		ft_strlen(const char *s);

#endif
