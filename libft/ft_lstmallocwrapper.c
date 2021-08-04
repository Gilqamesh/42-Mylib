/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocwrapper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:34:21 by edavid            #+#    #+#             */
/*   Updated: 2021/08/04 20:38:06 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// Malloc instead it also adds the address into 'lst'
// Use ft_lstmallocfree to free all the saved addresses
void	*ft_lstmallocwrapper(t_list **lst, size_t size)
{
	void	*new;

	if (!lst)
		return (NULL);
	new = malloc(size);
	if (!new)
		return (NULL);
	ft_lstadd_front(lst, new);
	return (new);
}
