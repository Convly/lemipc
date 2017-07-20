/*
** sam.c for sam.c in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/algo/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Sat Apr  1 21:22:49 2017 jsx
** Last update Sun Apr  2 02:16:38 2017 herbau_a herbau_a
*/

#include "lemipc.h"

void		GOTOPORFLAMESAM(
				t_ipcCore* core,
				t_game* game,
				t_player* player)
{
  t_msg		msg;
  t_Pos		mid;
  t_Pos		ref;
  t_Pos		c;

  c.x = c.y = 0;
  msg = core->recive_msgq(core, 80);
  ref = getTeamBarycenter(game, player->teamId + 48);
  if (game->NbTeam <= 4 &&
      ref.x == msg.posX && ref.y == msg.posY)
    {
      player->compute = &goLopez;
      return ;
    }
  mid.x = (game->NbPlayer > 1)? msg.posX: MAP_X / 2;
  mid.y = (game->NbPlayer > 1)? msg.posY: MAP_Y / 2;
  game->map[player->pos.y * MAP_X + player->pos.x] = '0';
  tryGoTowardPos(&c, game, &mid, player);
  if (c.x == 0 && c.y == 0 && game->NbTeam > 1)
    tryAnywhere(&c, game, player);
  player->pos.x += c.x;
  player->pos.y += c.y;
  game->map[player->pos.y * MAP_X + player->pos.x] = player->teamId + 48;
}
