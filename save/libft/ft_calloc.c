/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:58:33 by nflan             #+#    #+#             */
/*   Updated: 2021/11/30 10:38:05 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*tab;

	tab = malloc(nmemb * size);
	if (!tab)
		exit(EXIT_FAILURE);
	ft_bzero(tab, nmemb * size);
	return (tab);
}
