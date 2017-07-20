/*
** ipcCore.h for ipccore in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/IPC/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Wed Mar 29 10:59:16 2017 jsx
** Last update Sun Apr  2 20:01:13 2017 herbau_a herbau_a
*/

#ifndef IPCCORE_H_
# define IPCCORE_H_

#include "lemipc.h"

# define	LOCKER (1)
# define	MAP_Y (100)
# define	MAP_X (100)

struct	s_ipcCore	init_ipcCore(char*);

typedef struct	s_settings
{
  int		glob;
  int		proba[9][3];
}		t_settings;

typedef	struct	s_game
{
  char		map[MAP_Y * MAP_X];
  int		mapWidth;
  int		mapHeight;
  int		NbTeam;
  int		NbPlayer;
  int		started;
  int		mode;
  int		needLemSmash;
}		t_game;

typedef	struct	s_msg
{
  long		mtype;
  int		posX;
  int		posY;
}		t_msg;

typedef	struct	s_ipcCore
{
  key_t		key;
  int		shm_id;
  int		sem_id;
  int		msg_id;
  int		current_status;
  t_settings settings;
  void		(*delete_sem)(struct s_ipcCore*);
  int		(*get_sem_value)(struct s_ipcCore*);
  int		(*sem_add)(struct s_ipcCore*);
  int		(*sem_sub)(struct s_ipcCore*);
  void		(*delete_shm)(struct s_ipcCore*);
  void*		(*get_shm)(struct s_ipcCore*);
  void		(*write_shm)(struct s_ipcCore*, t_game*);
  void		(*delete_msg)(struct s_ipcCore*);
  void		(*add_msgq)(struct s_ipcCore*, int, int, int);
  t_msg		(*recive_msgq)(struct s_ipcCore*, int);
}		t_ipcCore;

#endif /* end of include guard: IPCCORE_H_ */
