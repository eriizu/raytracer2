/*
** colored_light_effect.c for raytracer in /home/elise/Projects/raytracer2/src/render/
**
** Made by Élise Philippe
** Login   <elise.philippe@epitech.eu>
**
** Started on  Wed Apr 19 08:57:36 2017 Élise Philippe
** Last update Wed May  3 16:50:22 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"
#include "launch.h"

void	apply_colored_light_effect(sfColor *color, t_object *objects)
{
  while (objects)
    {
      if (objects->type == ID_LIGHT && objects->col.a)
	{
	  color->r = (objects->col.r < color->r) ? objects->col.r : color->r;
	  color->g = (objects->col.g < color->g) ? objects->col.g : color->g;
	  color->b = (objects->col.b < color->b) ? objects->col.b : color->b;
	}
      objects = objects->next;
    }
}
