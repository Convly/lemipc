/*
** ipcCore.c for ipccore in /home/jsx/Epitech/tek2/PSU/lemipc/PSU_2016_lemipc/srcs/IPC/
**
** Made by jsx
** Login   <jean-sebastien.herbaux@epitech.eu>
**
** Started on  Wed Mar 29 10:58:45 2017 jsx
** Last update Sun Apr  2 23:12:26 2017 jsx
*/

#include "lemipc.h"

void		link_sem(struct s_ipcCore*);
void		link_shm(struct s_ipcCore*);
void		link_msg(struct s_ipcCore*);

void		linkCore(struct s_ipcCore* this)
{
  link_sem(this);
  link_shm(this);
  link_msg(this);
}

static void	createSharedMemory(t_ipcCore* core)
{
  int		flag;

  flag = IPC_CREAT | SHM_R | SHM_W;
  core->shm_id = shmget(core->key, sizeof(t_game), flag);
}

static void	createSemaphore(t_ipcCore* core)
{
  int		flag;

  flag = IPC_CREAT | SHM_R | SHM_W;
  core->sem_id = semget(core->key, 1, flag);
  semctl(core->sem_id, 0, SETVAL, LOCKER);
}

static void	createMsgQ(t_ipcCore* core)
{
  int		flag;

  flag = IPC_CREAT | SHM_R | SHM_W;
  core->msg_id = msgget(core->key, flag);
}

t_ipcCore	init_ipcCore(char* path)
{
  t_ipcCore	this;

  this.settings = get_stats();
  if ((this.key = ftok(path, 0)) == -1)
    {
      fprintf(stderr, "Fatal error: Invalid path \"%s\"\n", path);
      exit(84);
    }
  this.current_status = 0;
  this.shm_id = shmget(this.key, sizeof(t_game), SHM_R | SHM_W);
  if (this.shm_id == -1 && (this.current_status += 1))
    createSharedMemory(&this);
  this.sem_id = semget(this.key, 1, SHM_R | SHM_W);
  if (this.sem_id == -1 && (this.current_status += 2))
    createSemaphore(&this);
  this.msg_id = msgget(this.key, SHM_R | SHM_W);
  if (this.msg_id == -1 && (this.current_status += 4))
    createMsgQ(&this);
  linkCore(&this);
  return (this);
}
