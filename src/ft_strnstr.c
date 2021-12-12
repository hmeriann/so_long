/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:04:50 by hmeriann          #+#    #+#             */
/*   Updated: 2021/11/14 01:40:50 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strnstr(char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(haystack) < len)
		return ((char *)haystack);
	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (haystack[i] != '.')
		i++;
	i++;
	while (needle[j] != '\0' && haystack[i + j] != '\0')
	{
		if (haystack[i + j] != needle[j])
			return ((char *)haystack);
		j++;
	}
	return (NULL);
}
