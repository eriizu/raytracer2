/*
** objects_pr_texture.c for raytracer in /home/elise/Projects/raytracer2/src/data_gathering/
**
** Made by Élise Philippe
** Login   <elise.philippe@epitech.eu>
**
** Started on  Thu May 25 15:18:25 2017 Élise Philippe
** Last update Sat May 27 11:55:34 2017 Élise Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"

int	add_pr_texture(char *buffer, int *idx, t_object *new_object)
{
  if (buffer[*idx] == 'p' && buffer[*idx + 1] == 'F')
    new_object->perlin_fq = (float) my_getnbr(&buffer[*idx + 3]) / 1000;
  else if (buffer[*idx] == 'p' && buffer[*idx + 1] == 'H')
    new_object->perlin_ht = (float) my_getnbr(&buffer[*idx + 3]) / 1000;
  else if (buffer[*idx] == 't' && buffer[*idx + 1] == 'C')
    new_object->chess_board_f = my_getnbr(&buffer[*idx + 3]);
  else
    return (0);
  return (1);
}
