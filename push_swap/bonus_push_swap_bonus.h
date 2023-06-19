/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_push_swap_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:57:27 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/17 00:12:28 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_PUSH_SWAP_BONUS_H
# define A_PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "push_swap.h"

size_t	ft_strlen_gnl(const char *str);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char *static_buffer, char *temp);
char	*ft_firstline(char *string);
char	*ft_secondline(char *string);
char	*get_line_and_next_one(int fd, char *static_buffer);
char	*get_next_line(int fd);

#endif