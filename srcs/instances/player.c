/*
** player.c for player in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/instances/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Wed Mar 29 14:48:42 2017 jsx
** Last update Sun Apr  2 20:00:12 2017 herbau_a herbau_a
*/

#include "lemipc.h"

static void	run(t_player*, t_ipcCore*);

t_Pos		getRandomPlayerPosition(t_game* game)
{
  t_Pos		pos;
  int		goOut;
  int		i;

  pos.x = pos.y = i = -1;
  goOut = 0;
  while (++i < MAP_X * MAP_Y)
    {
      if (game->map[i] == '0')
	goOut = 1;
    }
  while (goOut)
    {
      pos.x = rand() % MAP_X;
      pos.y = rand() % MAP_Y;
      if (game->map[pos.y * MAP_X + pos.x] == '0')
	goOut = 0;
    }
  return (pos);
}

void		dumpMap(t_game* game)
{
  int		i;
  int		j;
  int		k;
  char		display[MAP_X * MAP_Y +
			((MAP_X - 1) * MAP_X) +
			((MAP_Y - 1) * MAP_Y) + 1];

  i = -1;
  k = 0;
  while (++i < MAP_Y)
    {
      j = -1;
      while (++j < MAP_X)
	{
	  printf("%c ", game->map[i * MAP_X + j]);
	  display[k++] = game->map[i * MAP_X + j];
	  if (j < MAP_X - 1)
	    display[k++] = ' ';
	}
      display[k++] = ((i < MAP_Y - 1)? '|': '\0');
      printf("\n");
    }
  printf("\n");
  fprintf(stderr, "%s", display);
}

static void	run(t_player* player, t_ipcCore* core)
{
  t_game*	game;
  int		fcflag;

  game = (t_game*)core->get_shm(core);
  fcflag = 0;
  while (player->isAlive)
    {
      core->sem_sub(core);
      if (game->needLemSmash == 1 && (player->lemSmash = 1))
	game->needLemSmash = 0;
      if (game->NbTeam == 1 && game->started && (fcflag = 1))
      	fclean(core);
      if (!isSurrounded(game, player) || fcflag)
	{
	  clean(game, player);
	  core->sem_add(core);
	  return ;
	}
      player->compute(core, game, player);
      if (game->mode)
      	dumpMap(game);
      core->sem_add(core);
    }
}

static void	setPlayerBehaviour(
				   t_ipcCore* core,
				   t_player* player)
{
  t_settings	settings;
  int		tmp;

  tmp = rand() % 100;
  settings = core->settings;
  if (tmp < settings.proba[player->teamId - 1][0] % 101)
    {
      player->compute = &goBaronne;
      player->cycle = 500;
    }
  else if (tmp < settings.proba[player->teamId - 1][1] % 101)
    player->compute = &goMartinez;
  else if (tmp < settings.proba[player->teamId - 1][2] % 101)
    player->compute = &goSam;
  else
    player->compute = &goAllamel;
}

t_player*	createNewPlayer(t_ipcCore* core, int teamId)
{
  t_game*	game;
  t_player*	elem;

  game = (t_game*)core->get_shm(core);
  if ((elem = malloc(sizeof(t_player))) == NULL)
    return (NULL);
  elem->pos = getRandomPlayerPosition(game);
  if (elem->pos.x == -1 && elem->pos.y == -1 && setError(NO_SPACE) == -1)
    return (NULL);
  elem->run = &run;
  elem->isAlive = 1;
  elem->teamId = teamId;
  if (isNewTeam(game, elem->teamId) && (game->NbTeam += 1)
      && !(game->started) && game->NbTeam > 1)
    game->started = 1;
  game->map[elem->pos.y * MAP_X + elem->pos.x] = elem->teamId + 48;
  game->NbPlayer++;
  elem->lemSmash = 0;
  elem->playerId = game->NbPlayer;
  elem->cycle = 0;
  setPlayerBehaviour(core, elem);
  return (elem);
}
