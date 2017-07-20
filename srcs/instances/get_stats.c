/*
** player.c for player in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/instances/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Wed Mar 29 14:48:42 2017 jsx
** Last update Sun Apr  2 23:11:44 2017 jsx
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "lemipc.h"

void		default_setttings()
{
  printf("Fail while reading the settings, exiting..\n");
  exit(84);
}

t_settings	get_glob(size_t len, FILE *fd, t_settings ret)
{
  char*		line;
  int		tmp0;
  int		tmp1;
  int		tmp2;
  int		i;
  int		j;

  line = NULL;
  j = i = -1;
  if (getline(&line, &len, fd) == -1)
    default_setttings();
  while (++j < 7 && line[j] != '\0');
  if (j != 7)
    default_setttings();
  tmp0 = atoi(line);
  tmp1 = atoi(line + 3);
  tmp2 = atoi(line + 6);
  while (++i < 9)
    {
      ret.proba[i][0] = tmp0;
      ret.proba[i][1] = tmp0 + tmp1;
      ret.proba[i][2] = tmp0 + tmp1 + tmp2;
    }
  return (ret);
}

t_settings	get_each(size_t len, FILE *fd, t_settings ret)
{
  char*		line;
  int		tmp;
  int		i;
  int		j;

  line = NULL;
  j = i = -1;
  while (++i < 9)
    {
      if ((getline(&line, &len, fd)) == -1)
        default_setttings();
      while (++j < 7 && line[j] != '\0');
      if (j < 7)
	{
	  printf("%d\n", j);
	  default_setttings();
	}
      tmp = atoi(line);
      ret.proba[i][0] = tmp;
      tmp = atoi(line + 3);
      ret.proba[i][1] = ret.proba[i][0] + tmp;
      tmp = atoi(line + 6);
      ret.proba[i][1] = ret.proba[i][1] + tmp;
    }
  return (ret);
}

t_settings	get_stats()
{
  t_settings	ret;
  FILE*		fd;
  size_t	len;
  char*		line;

  len = 0;
  line = NULL;
  if ((fd = fopen("settings.txt", "r")) == NULL)
    default_setttings();
  if (getline(&line, &len, fd) == -1)
    default_setttings();
  if (line[0] != '1')
    ret = get_glob(len, fd, ret);
  else
    ret = get_each(len, fd, ret);
  return (ret);
}
