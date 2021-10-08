/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_libft_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:58:24 by edavid            #+#    #+#             */
/*   Updated: 2021/09/28 17:02:10 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Install 'nullable_ptr' by passing it as an argument first time calling this
** function. Anytime the function called afterwards it will return the installed
** pointer.
*/
void	*ft_get_ptr(void *nullable_ptr)
{
	static bool	is_first_call = true;
	static void	*ptr;

	if (is_first_call == true)
	{
		is_first_call = false;
		ptr = nullable_ptr;
	}
	return (ptr);
}