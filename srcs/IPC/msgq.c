/*
** msgq.c for msgq in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/IPC/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Wed Mar 29 11:02:34 2017 jsx
** Last update Sun Apr  2 02:33:34 2017 herbau_a herbau_a
*/

#include "lemipc.h"

void	delete_msgq(t_ipcCore* this)
{
  msgctl(this->msg_id, IPC_RMID, NULL);
}

void	add_msgq(t_ipcCore *this, int x, int y, int channel)
{
  t_msg	tmp;

  tmp.mtype = channel;
  tmp.posX = x;
  tmp.posY = y;
  msgsnd(this->msg_id, &tmp, sizeof(tmp), 0);
}

t_msg	recive_msgq(t_ipcCore* this, int channel)
{
  t_msg	ret;

  if (msgrcv(this->msg_id, &ret, sizeof(ret), channel, 0) == -1)
    {
      ret.posX = MAP_X / 2;
      ret.posY = MAP_Y / 2;
      ret.mtype = channel;
    }
  return (ret);
}

void	link_msg(t_ipcCore* this)
{
  this->recive_msgq = &recive_msgq;
  this->add_msgq = &add_msgq;
  this->delete_msg = &delete_msgq;
}
