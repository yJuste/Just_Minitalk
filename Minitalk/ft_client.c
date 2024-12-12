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
#include "ft_client.h"

int	main(int argc, char **argv)
{
	pid_t		pid;

	if (argc < 3)
	{
		write(1, "Invalid pid or message.\n", 24);
		return (1);
	}
	if (argc > 3)
	{
		write(1, "Too many arguments.\n", 20);
		return (2);
	}
	ft_header_client();
	return (0);
}
