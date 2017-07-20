/*
** utilsString.c for utilsstring in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Mon Mar 27 13:18:32 2017 jsx
** Last update Sun Apr  2 02:28:30 2017 herbau_a herbau_a
*/

#include "lemipc.h"

int	getIntLen(int nb)
{
  int	r;

  r = 1;
  while ((nb /= 10) >= 9)
    r += 1;
  return (r);
}
