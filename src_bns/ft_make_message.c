/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 03:37:22 by zu                #+#    #+#             */
/*   Updated: 2021/12/12 15:31:35 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*ft_make_message(t_vars *vars)
{
	char	*str;
	char	*tmp;

	tmp = ft_itoa(vars->step_count);
	str = ft_strjoin("STEPS COUNT IS ", tmp);
	free(tmp);
	return (str);
}
