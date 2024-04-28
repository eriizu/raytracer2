/*
** objs_types.c for raytracer in /home/elise/Projects/raytracer2/src/data_gathering/
**
** Made by Élise Philippe
** Login   <elise.philippe@epitech.eu>
**
** Started on  Tue Apr 18 13:50:17 2017 Élise Philippe
** Last update Sat May 27 12:32:49 2017 Élise Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

static t_keywords	g_keywords[] =
  {
    {ID_SPHERE, OBJ_SPHERE, TYPE_SPHERE},
    {ID_PLANE, OBJ_PLANE, TYPE_PLANE},
    {ID_CYLINDER, OBJ_CYLINDER, TYPE_CYLINDER},
    {ID_CONE, OBJ_CONE, TYPE_CONE},
    {ID_LIGHT, OBJ_LIGHT, TYPE_LIGHT},
    {ID_EYE, OBJ_EYE, TYPE_EYE},
    {ID_TORUS, OBJ_TORUS, TYPE_TORUS},
    {0, NULL, NULL},
  };

int	resolve_object_type(char *str)
{
  int	i;

  i = 0;
  while (g_keywords[i].id_type)
    {
      if (g_keywords[i].name && match(str, g_keywords[i].match_name))
	return (g_keywords[i].id_type);
      i += 1;
    }
  return (0);
}

char	*get_object_type(int type)
{
  int	i;

  i = 0;
  while (g_keywords[i].id_type)
    {
      if (type == g_keywords[i].id_type)
	return (g_keywords[i].name);
      i += 1;
    }
  return (TYPE_UNK);
}
