/*
** shared_memory.c for sharedmemory in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/IPC/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Wed Mar 29 11:05:55 2017 jsx
** Last update Sun Apr  2 02:38:16 2017 herbau_a herbau_a
*/

#include "lemipc.h"

void		delete_shm(t_ipcCore* this)
{
  shmctl(this->shm_id, IPC_RMID, NULL);
  return ;
}

void*		get_shm(t_ipcCore* this)
{
  int		flag;
  void*		shm;

  if ((shm = shmat(this->shm_id, NULL, SHM_R | SHM_W)) == NULL)
    {
      flag = IPC_CREAT | SHM_R | SHM_W;
      this->shm_id = shmget(this->key, sizeof(t_game), flag);
      shm = shmat(this->shm_id, NULL, SHM_R | SHM_W);
    }
  return (shm);
}

void		write_shm(t_ipcCore* this, t_game *data)
{
  memcpy(this->get_shm(this), data, sizeof(t_game));
}

void		link_shm(t_ipcCore* this)
{
  this->delete_shm = &delete_shm;
  this->get_shm = &get_shm;
  this->write_shm = &write_shm;
}
