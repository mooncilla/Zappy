/*
** egg.c for Zappy in /home/gastal_r/rendu/Zappy/server/src/
**
** Made by gastal_r
** Login   <remi.gastaldi@epitech.eu>
**
** Started on  Fri Jun 30 13:25:04 2017 gastal_r
** Last update Sun Jul  2 21:41:27 2017 Matthias Prost
*/

#include      "utilities.h"

void		add_opened_egg(t_env *env, int x, int y)
{
  t_egg		*egg;
  t_egg		*tmp;

  egg = xmalloc(sizeof(t_egg));
  egg->x = x;
  egg->y = y;
  egg->next = NULL;
  if (env->egg == NULL)
    env->egg = egg;
  else
    {
      tmp = env->egg;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = egg;
    }
}

void		delete_front_egg(t_env *env)
{
  t_egg		*tmp;

  if (env->egg == NULL)
    return;
  tmp = env->egg->next;
  free(env->egg);
  env->egg = tmp;
}

void		eggAction(t_env *env, char **msg, t_users *user)
{
  (void)env;
  (void)msg;
  if (user->socket != -1)
    {
      printf("--> Sent \"egg\" to socket %d\n", user->socket);
      dprintf(user->socket, "egg\n");
    }
}
