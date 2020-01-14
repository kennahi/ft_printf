/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:02:21 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/10 20:57:46 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

typedef struct		s_variables
{
	int		w;
	int		p;
	int		flag;
}					t_var;

int					ft_printf(const char *str, ...);
int					dispecifier(const char **str, va_list args, t_var *flog);
int					dadditional2(int i);
int					dizeroprecision(int i, t_var *flog);
void				diconditions(int i, t_var *flog);
void				uconditions(unsigned int i, t_var *flog);
void				sconditions(char *s, t_var *flog);
int					uspecifier(const char **str, va_list args, t_var *flog);
void				ft_itoa(int n);
void				ft_itoaa(unsigned int n);
void				ft_putchar(char c);
int					sspecifier(const char **str, va_list args, t_var *flog);
int					sadditional(char *s, t_var *flog);
int					sadditional2(char *s, t_var *flog);
int					swidth(t_var *flog);
int					cspecifier(const char **str, va_list args, t_var *flog);
int					xspecifier(const char **str, va_list args, t_var *flog);
char				*xconverter(unsigned int n, char x);
void				xadditional2(char *s, t_var *flog);
int					pspecifier(const char **str, va_list args, t_var *flog);
char				*pconverter(unsigned long int n);
void				ft_putstr(char *s);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_substr(char *s, unsigned int start, size_t len);
int					intlen(int n);
int					unintlen(unsigned int n);
int					ft_strlen(char *s);

#endif
