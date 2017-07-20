/*
** lopez.c for lopez in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/algo/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Sun Apr  2 00:51:47 2017 jsx
** Last update Sun Apr  2 18:18:18 2017 jsx
*/

#include "lemipc.h"

static void			cycleHandler(t_player* player)
{
  player->cycle--;
  if (player->cycle == 0)
    {
      player->cycle = 1000;
      player->compute = &goBaronne;
    }
}

void		GOJUNGLEORJOELOPEZ(
				   t_game* game,
				   t_player* player)
{
  t_Pos		mid;
  t_Pos		c;

  c.x = c.y = 0;
  mid = getJoeTarget(game, player->pos, player->teamId + 48);
  mid.x = (game->NbPlayer > 1)? mid.x: MAP_X / 2;
  mid.y = (game->NbPlayer > 1)? mid.y: MAP_Y / 2;
  cycleHandler(player);
  game->map[player->pos.y * MAP_X + player->pos.x] = '0';
  tryGoTowardPos(&c, game, &mid, player);
  if (c.x == 0 && c.y == 0 && game->NbTeam > 1)
    tryAnywhere(&c, game, player);
  player->pos.x += c.x;
  player->pos.y += c.y;
  game->map[player->pos.y * MAP_X + player->pos.x] = player->teamId + 48;
}

t_Pos		getJoeTarget(t_game* game, t_Pos ppos, char teamId)
{
  t_Pos		target;
  int		i;
  double	minDist;
  double	dist;
  int		x;
  int		y;

  i = 0;
  minDist = MAP_X + MAP_Y;
  target.x = 0;
  target.y = 0;
  while (i < MAP_X * MAP_Y)
    {
      x = i % MAP_X;
      y = i / MAP_X;
      if (game->map[i] != '0' && game->map[i] != teamId &&
	  (dist = getDist(ppos, x, y)) < minDist)
	{
	  minDist = dist;
	  target.x = x;
	  target.y = y;
	}
      i++;
    }
  return (target);
}
