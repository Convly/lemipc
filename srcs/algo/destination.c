/*
** destination.c for destination in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/algo/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Fri Mar 31 22:39:39 2017 jsx
** Last update Sun Apr  2 02:10:51 2017 herbau_a herbau_a
*/

#include "lemipc.h"

t_Pos		getGenBarycenter(t_game* game)
{
  t_Pos		res;
  int		k;
  int		i;

  i = res.x = res.y = k = 0;
  while (i < MAP_Y * MAP_X)
    {
      if (game->map[i] != '0')
	{
	  res.x += i / MAP_X;
	  res.y += i % MAP_X;
	  k++;
	}
      i++;
    }
  res.x /= k;
  res.y /= k;
  return (res);
}

t_Pos		getTeamBarycenter(t_game* game, char teamId)
{
  t_Pos		res;
  int		k;
  int		i;

  i = res.x = res.y = k = 0;
  while (i < MAP_Y * MAP_X)
    {
      if (game->map[i] == teamId)
	{
	  res.x += i / MAP_X;
	  res.y += i % MAP_X;
	  k++;
	}
      i++;
    }
  res.x /= k;
  res.y /= k;
  return (res);
}

void		calcAndSendNewDestinationMartinez(t_ipcCore* core,
						  t_game* game)
{
  t_Pos		barycenter;

  barycenter = getGenBarycenter(game);
  core->add_msgq(core, barycenter.x, barycenter.y, 81);
}

void		calcAndSendNewDestinationSam(
					     t_ipcCore* core,
					     t_game* game,
					     char teamId)
{
  t_Pos		barycenter;

  barycenter = getTeamBarycenter(game, teamId);
  core->add_msgq(core, barycenter.x, barycenter.y, 80);
}
