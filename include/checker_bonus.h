/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:56:53 by wshee             #+#    #+#             */
/*   Updated: 2025/01/14 18:33:57 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "../libft/libft.h"

void	free_error(t_stack **a, t_stack **b);
void	execute_instructions(t_stack **a, t_stack **b, char *instructions);

#endif
