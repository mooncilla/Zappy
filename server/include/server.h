/*
** server.h for Zappy in /home/prost_m/Rendu/Semestre_4/Zappy/includes
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu>
**
** Started on  Thu Jun 15 15:09:06 2017 Matthias Prost
** Last update Thu Jun 22 19:17:56 2017 Matthias Prost
*/

#ifndef _SERVER_H_
#define _SERVER_H_

#include "utilities.h"

#define FD_FREE			0
#define FD_CLIENT		1
#define FD_SERVER		2

#define NBR_ARGS    6

#define LINEMATE    3
#define DERAUMERE   2
#define SIBUR       3
#define MENDIANA    2
#define PHIRAS      3
#define THYSTAME    2

enum Direction
{
    UP,
    DOWN,
    RIGHT,
    LEFT
};

typedef struct	    s_commands
{
  char		          *command;
  void		          (*p)(t_env *env, char **av, int i);
}		                t_commands;

int	    s_error(char *str);

void		printUsage();

void    widthArg(t_env *env, char **av, int i);
void    heightArg(t_env *env, char **av, int i);
void    clientsNbArg(t_env *env, char **av, int i);
void    portArg(t_env *env, char **av, int i);
void    freqArg(t_env *env, char **av, int i);
void    nameArg(t_env *env, char **av, int i);


void		createServer(t_env *env);
void        createMap(t_env *env);
void		serverLoop(t_env *env);

void		addClient(t_env *env, int s);

extern t_commands g_commands[NBR_ARGS];

#endif