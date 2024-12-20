/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:12:04 by wshee             #+#    #+#             */
/*   Updated: 2024/12/20 21:02:29 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../../ft_printf/include/ft_printf.h"

typedef struct s_stack
{
	int			number;
	int			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	init_stack(t_stack **stack, char **argv)

#endif
