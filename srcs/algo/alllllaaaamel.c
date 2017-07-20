/*
** alllllaaaamel.c for alllllaaaamel in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/algo/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Sat Apr  1 23:19:12 2017 jsx
** Last update Sun Apr  2 02:08:58 2017 herbau_a herbau_a
*/

#include "lemipc.h"

void	GOBOTORGETFRIENDZONEDALLAMEL(t_game* game, t_player* player)
{
  t_Pos	mid;
  t_Pos	c;

  c.x = c.y = 0;
  mid = calcNewHidingPlaceForAllamel(game);
  mid.x = (game->NbPlayer > 1)? mid.x: MAP_X / 2;
  mid.y = (game->NbPlayer > 1)? mid.y: MAP_Y / 2;
  game->map[player->pos.y * MAP_X + player->pos.x] = '0';
  tryGoTowardPos(&c, game, &mid, player);
  if (c.x == 0 && c.y == 0 && game->NbTeam > 1)
    tryAnywhere(&c, game, player);
  player->pos.x += c.x;
  player->pos.y += c.y;
  game->map[player->pos.y * MAP_X + player->pos.x] = player->teamId + 48;
}

t_Pos	calcNewHidingPlaceForAllamel(t_game* game)
{
  t_Pos	barycenter;
  t_Pos	opposed;

  opposed.x = opposed.y = 0;
  barycenter = getGenBarycenter(game);
  opposed.x = (barycenter.x > MAP_X / 2)? 0: MAP_X - 1;
  opposed.y = (barycenter.y > MAP_Y / 2)? 0: MAP_Y - 1;
  return (opposed);
}
