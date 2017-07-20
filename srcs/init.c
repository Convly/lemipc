/*
** init.c for init in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Wed Mar 29 17:11:07 2017 jsx
** Last update Sun Apr  2 16:26:46 2017 jsx
*/

#include "lemipc.h"

int			initFirstLap(t_ipcCore* core, int mode)
{
  t_game		send;
  int			i;
  int			j;

  i = -1;
  while (++i < MAP_Y)
    {
      j = -1;
      while (++j < MAP_X)
	send.map[i * MAP_X + j] = '0';
    }
  send.NbTeam = send.NbPlayer = send.started = 0;
  send.mapWidth = MAP_X;
  send.mapHeight = MAP_Y;
  send.needLemSmash = 1;
  send.mode = mode;
  core->add_msgq(core, MAP_X / 2, MAP_Y / 2, 81);
  core->add_msgq(core, MAP_X / 2, MAP_Y / 2, 80);
  core->write_shm(core, &send);
  return (0);
}

int			isNewTeam(t_game* game, int teamId)
{
  int			i;

  i = 0;
  while (i < MAP_Y * MAP_X)
    {
      if (game->map[i] - '0' == teamId)
	return (0);
      i++;
    }
  return (1);
}

int			getNbTeamOnMap(t_game* game)
{
  int			i;
  char			team;
  int			k;
  int			flag;

  k = 0;
  team = '0';
  while (++team <= '9')
    {
      flag = i = -1;
      while (++i < MAP_X * MAP_Y)
	{
	  if (game->map[i] == team)
	    flag = 1;
	}
      if (flag == 1)
	k++;
    }
  game->NbTeam = k;
  return ((k == 1 && game->started)? 1: 0);
}
