/*
** errors.c for errors in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Mon Mar 27 10:54:02 2017 jsx
** Last update Sun Apr  2 02:17:58 2017 herbau_a herbau_a
*/

#include "lemipc.h"

int		raiseError()
{
  if (errgo)
    {
      fprintf(stderr, "Fatal error: %s\n", errgo);
      free(errgo);
    }
  else
    fprintf(stderr, "Unknown error\n");
  return (-1);
}

int		setError(char* e)
{
  if (errgo != NULL)
    free(errgo);
  errgo = strdup(e);
  return (-1);
}

void		cleanErr()
{
  if (errgo)
    free(errgo);
}

int		err_nbArgs(int ac)
{
  size_t	argsSizeStr;
  char*		nbArgs;
  char*		err;

  argsSizeStr = getIntLen(ac);
  if ((err = malloc(sizeof(char) * (38 + argsSizeStr))) == NULL)
    return (setError(BAD_ALLOC));
  memset(err, 0, 38 + argsSizeStr);
  memcpy(err, "Excpected 2 arguments (or '-v'), got ", 37);
  if ((nbArgs = malloc(sizeof(char) * (argsSizeStr + 1))) == NULL)
    return (setError(BAD_ALLOC));
  sprintf(nbArgs, "%d", ac - 1);
  strcat(err, nbArgs);
  free(nbArgs);
  setError(err);
  free(err);
  return (-1);
}
