/*
** baronne.c for baronne in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/algo/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Sun Apr  2 17:24:15 2017 jsx
** Last update Sun Apr  2 18:18:20 2017 jsx
*/

#include "lemipc.h"

static void			cycleHandler(t_player* player)
{
  player->cycle--;
  if (player->cycle == 0)
    {
      player->cycle = 500;
      player->compute = &goLopez;
    }
}

void            SUPORAFKBARONNE(t_game* game, t_player* player)
{
  t_Pos         mid;
  t_Pos         c;

  c.x = c.y = 0;
  mid = getTeamBarycenter(game, player->teamId + 48);
  cycleHandler(player);
  if (game->NbTeam <= 4)
    {
      player->compute = &goLopez;
      return ;
    }
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
