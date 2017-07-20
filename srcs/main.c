/*
** main.c for main in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Mon Mar 27 10:54:10 2017 jsx
** Last update Sun Apr  2 18:05:59 2017 jsx
*/

#include "lemipc.h"

char*		errgo = NULL;

int		main(int argc, char** argv)
{
  t_ipcCore	core;
  t_player*	player;
  struct timeval        t1;

  gettimeofday(&t1, NULL);
  srand(t1.tv_usec * t1.tv_sec);
  if (parser(argc, argv))
    return (raiseError());
  core = init_ipcCore(argv[1]);
  if (core.current_status == 7)
    initFirstLap(&core, ((argc > 3)? 1: 0));
  else if (core.current_status != 0)
    return (raiseError());
  core.sem_sub(&core);
  player = createNewPlayer(&core, atoi(argv[2]));
  core.sem_add(&core);
  if (player == NULL)
    return (raiseError());
  player->run(player, &core);
  free(player);
  return (0);
}

void		clean(t_game* game, t_player* player)
{
  game->map[player->pos.y * MAP_X + player->pos.x] = '0';
  game->NbPlayer -= 1;
  if (!(game->NbPlayer))
    printf("\n\nTeam %d win\n", player->teamId);
  if (player->lemSmash)
    game->needLemSmash = 1;
  getNbTeamOnMap(game);
}

void		fclean(t_ipcCore* core)
{
  core->delete_sem(core);
  core->delete_shm(core);
  core->delete_msg(core);
}
