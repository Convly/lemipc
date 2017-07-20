/*
** routes.c for routes in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/algo/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Sat Apr  1 21:09:28 2017 jsx
** Last update Sun Apr  2 17:25:23 2017 jsx
*/

#include "lemipc.h"

void	goSam(t_ipcCore* core, t_game* game, t_player* player)
{
  GOTOPORFLAMESAM(core, game, player);
  calcAndSendNewDestinationSam(core, game, player->teamId + 48);
}

void	goMartinez(t_ipcCore* core, t_game* game, t_player* player)
{
  GOMIDREPORTTHIBAULTMARTINEZAPE(core, game, player);
  calcAndSendNewDestinationMartinez(core, game);
}

void	goAllamel(t_ipcCore* core, t_game* game, t_player* player)
{
  (void)core;
  GOBOTORGETFRIENDZONEDALLAMEL(game, player);
}

void	goLopez(t_ipcCore* core, t_game* game, t_player* player)
{
  (void)core;
  GOJUNGLEORJOELOPEZ(game, player);
}

void	goBaronne(t_ipcCore* core, t_game* game, t_player* player)
{
  (void)core;
  SUPORAFKBARONNE(game, player);
}
