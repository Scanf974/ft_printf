/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 09:16:56 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/26 10:09:57 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define NONE	0
# define LEFT	1
# define ZERO	2
# define SIGNE	3
# define TAG	4

# define OCT	3
# define HEX	4

typedef unsigned long long int	t_ullong;

struct		s_flag
{
	char	left;
	char	zero;
	char	signe;
	char	blank;
	char	tag;
};

struct		s_over
{
	char	l_short;
	char	l_long;
	char	l_double;
	char	l_intmax_t;
	char	l_z;
};

typedef struct	s_format
{
	struct s_flag	*flag;
	struct s_over	*over_flag;
	int				width;
	int				precision;
	char			did_p;
	char			conversion;
}				t_format;

void			ft_putchar(char c);
void			ft_putstr(char *s);
int				ft_strlen(const char *s);
int				ft_strlen_per(const char *s);
char			*ft_itoa(int n);
char			*ft_strnew(unsigned int size);
char			*ft_long_itoa(long long int n);
char			*ft_unsigned_itoa(t_ullong n);
void			*ft_memalloc(unsigned int size);
void			ft_bzero(void *s, unsigned int n);
void			*ft_memset(void *s, int c, unsigned int n);
char			*ft_strdup(const char *s1);
char			*ft_strncpy(char *dst, const char *src, unsigned int n);
char			*ft_strncat(char *s1, const char *s2, unsigned int n);
int				ft_charcheck_in_str(char let, char *str);
int				ft_isdigit(int c);
long long int 	ft_atoi(const char *str);
int				ft_intlen(int n);
char			*ft_transfo_int(char *str, t_format *fg);
char			*ft_transfo_hexoct(char *str, t_format *fg);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoin_per(const char *s1, const char *s2);
char			*ft_strjoin_etoile(const char *s1, const char *s2);
char			*ft_strjoin_per_aux(const char *s1, const char *s2);
char			*ft_strjoin_per_aux2(const char *s1, const char *s2);
int				ft_pow(int base, int pow);
int				ft_strequ(char const *s1, char const *s2);
void			ft_initflags(t_format **fg);
int				ft_printf(const char *format, ...);
char			*ft_putarg(const char *f, va_list ap, t_format *fg);
int				ft_check_flags(const char *str, t_format **fg, va_list ap);
void			ft_putflags(char flg, t_format **fg);
char			*ft_binary(unsigned long long int nb, t_format *fg);
char			*ft_bin_to_hexoct(char *str, int conv, t_format *fg);
char			*ft_putwidth(char *str, int width, t_format *fg);
unsigned char	*ft_split_bytes(char *bin);

#endif
