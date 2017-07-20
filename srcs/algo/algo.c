/*
** algo.c for algo in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/algo/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Thu Mar 30 11:18:24 2017 jsx
** Last update Sun Apr  2 02:07:18 2017 herbau_a herbau_a
*/

#include "lemipc.h"

int		checkCase(int idx, char ops[], char t)
{
  int		k;

  k = 0;
  while (k < 8)
    {
      if (ops[k] != '0'
	  && ops[k] != t
	  && idx != k
	  && ops[idx] == ops[k])
	return (1);
      k++;
    }
  return (0);
}

int		isSurrounded(t_game* game, t_player* player)
{
  char		ops[8];
  t_Pos		p;
  int		idx;

  p = player->pos;
  ops[0] = (p.y > 0)? game->map[(p.y - 1) * MAP_X + p.x]: '0';
  ops[1] = (p.y < MAP_Y - 1)? game->map[(p.y + 1) * MAP_X + p.x]: '0';
  ops[2] = (p.x > 0)? game->map[p.y * MAP_X + (p.x - 1)]: '0';
  ops[3] = (p.x < MAP_X - 1)? game->map[p.y * MAP_X + (p.x + 1)]: '0';
  ops[4] = (p.y > 0 && p.x > 0)?
    game->map[(p.y - 1) * MAP_X + (p.x - 1)]: '0';
  ops[5] = (p.y < MAP_Y - 1 && p.x < MAP_X - 1)?
    game->map[(p.y + 1) * MAP_X + (p.x + 1)]: '0';
  ops[6] = (p.y > 0 && p.x < MAP_X - 1)?
    game->map[(p.y - 1) * MAP_X + (p.x + 1)]: '0';
  ops[7] = (p.x > 0 && p.y < MAP_Y - 1)?
    game->map[(p.y + 1) * MAP_X + (p.x - 1)]: '0';
  idx = -1;
  while (++idx < 8)
    {
      if (checkCase(idx, ops, player->teamId + 48))
	player->isAlive = 0;
    }
  return (player->isAlive);
}

void		tryGoTowardPos(t_Pos* dir, t_game* game,
			       t_Pos* mid, t_player* player)
{
  t_Pos		np;

  if (player->pos.x > mid->x)
    dir->x = -1;
  else if (player->pos.x < mid->x)
    dir->x = 1;
  if (player->pos.y > mid->y)
    dir->y = -1;
  else if (player->pos.y < mid->y)
    dir->y = 1;
  np.y = player->pos.y + dir->y;
  np.x = player->pos.x + dir->x;
  if (np.x < 0 || np.y < 0
      || np.y >= MAP_Y || np.x >= MAP_Y
      || game->map[np.y * MAP_X + np.x] != '0')
    {
      dir->x = 0;
      dir->y = 0;
    }
}

void		tryAnywhere(t_Pos* dir, t_game* game, t_player* player)
{
  int		x;
  int		y;
  t_Pos		np;

  x = player->pos.x;
  y = player->pos.y;
  if (y + 1 < MAP_Y - 1 && game->map[(y + 1) * MAP_X + (x + dir->x)] == '0')
    dir->y = 1;
  else if (y - 1 > 0 && game->map[(y - 1) * MAP_X + (x + dir->x)] == '0')
    dir->y = -1;
  if (x + 1 < MAP_X - 1 && game->map[(y + dir->y) * MAP_X + (x + 1)] == '0')
    dir->x = 1;
  else if (x - 1 > 0 && game->map[(y + dir->y) * MAP_X + (x - 1)] == '0')
    dir->x = -1;
  np.y = player->pos.y + dir->y;
  np.x = player->pos.x + dir->x;
  if (np.x < 0 || np.y < 0 || np.y >= MAP_Y || np.x >= MAP_Y
      || game->map[np.y * MAP_X + np.x] != '0')
    dir->x = dir->y = 0;
}

int		getDist(t_Pos pos, int x, int y)
{
  return (hypot(x - pos.x, y - pos.y));
}
