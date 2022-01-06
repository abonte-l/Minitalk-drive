/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:02:37 by abonte-l          #+#    #+#             */
/*   Updated: 2022/01/02 18:15:44 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

/*
** errors types
*/
# define ERROR_ARG_SERV "[ERROR]\n./server needs ONLY 1 argument : exit\n"
# define ERROR_ARG_CLI "[ERROR]\n./client works with 3 arguments ONLY : exit\n"
# define ERROR_PID "[ERROR]\nincorrect server's PID (0 or lower) : exit\n"
# define ERROR_SIGNAL "[ERROR]\nsignal error : exit\n"

# define PID_SUCCESS "[SERVER LISTENING] PID successfully retrieve : "

# define ERROR -1
# define SUCCESS 0

/*
** utils.c functions
*/
int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
void	ft_putchar(char c);

#endif