/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:58:22 by dlu               #+#    #+#             */
/*   Updated: 2023/06/09 10:08:58 by dlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Free all the allocated map data. */
void	ft_free_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->lines[++i])
		free(map->lines[i]);
	free(map->lines);
	i = -1;
	while (map->lines_cpy[++i])
		free(map->lines_cpy[i]);
	free(map->lines_cpy);
}

/* Print given message to stderr, free data and exit with failure status. */
void	ft_perror_exit(char *msg, t_game *game)
{
	ft_putendl_fd(ERR_MSG, STDERR);
	ft_putendl_fd(msg, STDERR);
	if (game)
	{
		ft_free_map(game->map);
		free(game->map);
	}
	exit(EXIT_FAILURE);
}
