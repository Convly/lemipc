/*
** parser.c for parser in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Mon Mar 27 10:53:54 2017 jsx
** Last update Sun Apr  2 02:21:08 2017 herbau_a herbau_a
*/

#include "lemipc.h"

int	parser(int ac, char** av)
{
  (void)av;
  if (ac < 3 || ac > 4 || (ac == 4 && strcmp(av[3], "-v")))
    return (err_nbArgs(ac));
  if (strlen(av[2]) != 1)
    return (-1);
  if (av[2][0] < '1' || av[2][0] > '9')
    return (-1);
  return (0);
}
