/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:55:29 by edavid            #+#    #+#             */
/*   Updated: 2021/09/10 18:01:04 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Allocates and returns a new element t_obj_lst *result;
** result->key = ft_strdup(key);
** result->value = ft_strdup(value);
** The variable 'next' is initialized to NULL.
*/
t_obj_lst	*ft_objlst_new(char *key, char *value)
{
	t_obj_lst	*new;

	new = ft_calloc(1, sizeof(*new));
	if (key)
		new->key = ft_strdup(key);
	if (value)
		new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}
