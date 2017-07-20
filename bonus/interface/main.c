/*
** algo.c for algo in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/algo/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Thu Mar 30 11:18:24 2017 jsx
** Last update Sun Apr  2 23:21:11 2017 jsx
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>
#include <stddef.h>
#include "lemipc.h"

int			get_shm(char *path)
{
  key_t			key;
  int			shm_id;

  key = ftok(path, 0);
  shm_id = shmget(key, sizeof(t_game), SHM_R | SHM_W);
  if (shm_id == -1)
    {
      printf("no current map hosted here\n");
      exit(0);
    }
  return (shm_id);
}

sfColor			ctc(int team)
{
  sfColor		colorfull;

  srand(team);
  colorfull.a = 255;
  colorfull.r = rand() % 255;
  colorfull.g = rand() % 255;
  colorfull.b = rand() % 255;
  return (colorfull);
}

void			computing_frame(sfRenderWindow *window,
					t_game *ctx)
{
  sfCircleShape	*item;
  sfVector2f		s;
  sfVector2f		place;
  sfVector2u		winsize;
  sfColor		eddy;

  item = sfCircleShape_create();
  winsize = sfRenderWindow_getSize(window);
  sfCircleShape_setRadius(item, (winsize.x / MAP_X) / 2);
  s.x = -1;
  while (++s.x < ctx->mapWidth)
    {
      s.y = -1;
      while (++s.y < ctx->mapHeight)
	{
	  place.x = (winsize.x / ctx->mapWidth) * s.x;
	  place.y = (winsize.y / ctx->mapWidth) * s.y;
	  sfCircleShape_setPosition(item, place);
	  eddy = ctc(ctx->map[(int)s.y * MAP_X + (int)s.x]);
	  sfCircleShape_setFillColor(item, eddy);
	  sfRenderWindow_drawCircleShape(window, item, NULL);
	}
    }
}

int			main(int ac, char **av)
{
  sfVideoMode		mode;
  sfRenderWindow	*window;
  sfEvent		event;
  t_game		*ctx;

  if (ac != 2)
    return (0);
  ctx = shmat(get_shm(av[1]), NULL, SHM_R | SHM_W);
  mode.width = 1000;
  mode.height = 1000;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, "lemIPC", sfResize | sfClose, NULL);
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(window);
	}
      sfRenderWindow_clear(window, ctc(48));
      computing_frame(window, ctx);
      sfRenderWindow_display(window);
    }
  return (0);
}
