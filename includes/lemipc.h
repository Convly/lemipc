/*
** lemipc.h for lemipc in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/includes/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Mon Mar 27 10:54:41 2017 jsx
** Last update Sun Apr  2 17:31:03 2017 jsx
*/

#ifndef LEMIPC_H_
# define LEMIPC_H_

#include <sys/time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include "ipcCore.h"
#include "player.h"

# define	INVALID_ARG	"Invalid arguments"
# define	BAD_ALLOC	"Cannot allocate memory"
# define	NO_SPACE	"no more space on the map"

extern char*	errgo;

typedef	struct	s_map
{
  size_t	width;
  size_t	height;
  char**	map;
}		t_map;

int		raiseError();
int		setError();
int		err_nbArgs(int);
int		parser(int, char**);
int		getIntLen(int);
int		initFirstLap(t_ipcCore*, int mode);
int		isNewTeam(t_game*, int);
int		getNbTeamOnMap(t_game*);
int		checkCase(int, char[], char);
void		tryAnywhere(t_Pos*, t_game*, t_player*);
void		tryGoTowardPos(t_Pos*, t_game*, t_Pos*, t_player*);
t_Pos		getTeamBarycenter(t_game*, char teamId);
t_Pos		getGenBarycenter(t_game*);
t_Pos		getJoeTarget(t_game*, t_Pos, char);
void		GOMIDREPORTTHIBAULTMARTINEZAPE(t_ipcCore*,
					       t_game*,
					       t_player*);
void		GOBOTORGETFRIENDZONEDALLAMEL(t_game*,
					     t_player*);
void		GOTOPORFLAMESAM(t_ipcCore*,
				t_game*,
				t_player*);
void		GOJUNGLEORJOELOPEZ(t_game*,
				   t_player*);
void		SUPORAFKBARONNE(t_game*, t_player*);
void		calcAndSendNewDestinationSam(t_ipcCore*, t_game*, char);
void		calcAndSendNewDestinationMartinez(t_ipcCore*, t_game*);
t_Pos		calcNewHidingPlaceForAllamel(t_game*);
int		getDist(t_Pos, int, int);

#endif /* end of include guard: LEMIPC_H_ */
