/*
** player.h for player in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/instances/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Wed Mar 29 14:48:32 2017 jsx
** Last update Sun Apr  2 20:01:41 2017 herbau_a herbau_a
*/

#ifndef PLAYER_H_
# define PLAYER_H_

#include "lemipc.h"

typedef struct	s_Pos
{
  int		x;
  int		y;
}		t_Pos;

typedef struct	s_player
{
  int		teamId;
  t_Pos		pos;
  int		playerId;
  int		isAlive;
  int		lemSmash;
  int		cycle;
  void		(*run)(struct s_player*, t_ipcCore*);
  void		(*compute)(t_ipcCore*, t_game*, struct s_player*);
}		t_player;

t_settings	get_stats();
t_player*	createNewPlayer(t_ipcCore*, int);
t_Pos		getRandomPlayerPosition(t_game*);
int		isSurrounded(t_game*, t_player*);
void		fclean(t_ipcCore*);
void		clean(t_game*, t_player*);
void		dumpMap(t_game*);
void		goSam(t_ipcCore*, t_game*, t_player*);
void		goMartinez(t_ipcCore*, t_game*, t_player*);
void		goAllamel(t_ipcCore*, t_game*, t_player*);
void		goLopez(t_ipcCore*, t_game*, t_player*);
void		goBaronne(t_ipcCore*, t_game*, t_player*);

#endif /* end of include guard: PLAYER_H_ */
