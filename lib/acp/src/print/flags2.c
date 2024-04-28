/*
** flags2.c for my_printf in /home/elise/delivery/PSU_2016_my_printf
**
** Made by Élise Philippe
** Login   <elise@epitech.net>
**
** Started on  Sat Nov 12 12:46:03 2016 Élise Philippe
** Last update Sun May 28 17:48:58 2017 Élise Philippe
*/

#include "acp_print.h"

int	long_flags(char **strptr, va_list params)
{
  int	sum;
  int	(*flag_option[15])(va_list);
  int	rank;

  flag_option[3] = my_putlong;
  flag_option[4] = flag_x_hexa_long;
  flag_option[5] = flag_X_hexa_long;
  flag_option[6] = flag_o_octal_long;
  flag_option[7] = flag_u_unsigned_long;
  flag_option[8] = flag_b_binary_long;
  rank = get_flag_rank(strptr, params);
  sum = 0;
  if (rank >= 3 && rank <= 8)
    sum += flag_option[rank](params);
  return (sum);
}

int	flag_u_unsigned_long(va_list prm)
{
  return (my_putlong_base(va_arg(prm, unsigned long), "0123456789"));
}

int	flag_x_hexa_long(va_list prm)
{
  return (my_putlong_base(va_arg(prm, unsigned long), "0123456789abcdef"));
}

int	flag_X_hexa_long(va_list prm)
{
  return (my_putlong_base(va_arg(prm, unsigned long), "0123456789abcdef"));
}

int	flag_o_octal_long(va_list prm)
{
  return (my_putlong_base(va_arg(prm, unsigned long), "0123456789ABCDEF"));
}
