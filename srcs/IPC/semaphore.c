/*
** semaphore.c for semaphore in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/IPC/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Wed Mar 29 11:04:14 2017 jsx
** Last update Sun Apr  2 02:37:16 2017 herbau_a herbau_a
*/

#include "lemipc.h"

void		delete_sem(t_ipcCore *this)
{
  semctl(this->sem_id, 1, IPC_RMID);
  return ;
}

int		sem_add(t_ipcCore* this)
{
  struct sembuf	add;

  add.sem_num = 0;
  add.sem_flg = 0;
  add.sem_op = 1;
  semop(this->sem_id, &add, 1);
  return (0);
}

int		sem_sub(t_ipcCore* this)
{
  struct sembuf	sub;

  sub.sem_num = 0;
  sub.sem_flg = 0;
  sub.sem_op = -1;
  semop(this->sem_id, &sub, 1);
  return (0);
}

int		get_sem_value(t_ipcCore* this)
{
  int		ret;

  ret = semctl(this->sem_id, 0, GETVAL);
  return (ret);
}

void		link_sem(t_ipcCore* this)
{
  this->delete_sem = &delete_sem;
  this->get_sem_value = &get_sem_value;
  this->sem_add = &sem_add;
  this->sem_sub = &sem_sub;
}
