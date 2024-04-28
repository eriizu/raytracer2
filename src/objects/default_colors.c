/*
** default_colors.c for raytracer in /home/elise/Projects/raytracer2/src/render/
**
** Made by Élise Philippe
** Login   <elise.philippe@epitech.eu>
**
** Started on  Mon Apr 17 17:46:14 2017 Élise Philippe
** Last update Sun May 28 17:48:03 2017 Élise Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

sfColor	get_def_color_ob(t_object *obj)
{
  if (obj->type == 1)
    return (sfRed);
  else if (obj->type == 2)
    return (sfBlue);
  else if (obj->type == 3)
    return (sfGreen);
  else if (obj->type == 4)
    return (sfYellow);
  else
    return (sfBlack);
}

sfColor	get_def_color_ty(int type)
{
  if (type == 1)
    return (sfRed);
  else if (type == 2)
    return (sfBlue);
  else if (type == 3)
    return (sfGreen);
  else if (type == 4)
    return (sfYellow);
  else
    return (sfBlack);
}

sfColor	get_color_from_objs(t_object *objs, int id)
{
  while (objs)
    {
      if (objs->id == id)
	{
	  if (objs->col.a)
	    return (objs->col);
	  else
	    return (get_def_color_ob(objs));
	}
      objs = objs->next;
    }
  return (sfBlack);
}
