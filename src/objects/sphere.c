/*
** intersect_sphere.c for raycaster1 in /home/elise/delivery/bsraytracer1/src/
**
** Made by Élise Philippe
** Login   <elise.philippe@epitech.eu>
**
** Started on  Tue Feb  7 15:35:04 2017 Élise Philippe
** Last update Fri Apr 28 15:27:03 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include "intersect.h"

static inline sfVector3f	define_quad_eq_vars(sfVector3f eye_pos,
						    sfVector3f dir_vector,
						    float radius)
{
  sfVector3f		abc;

  abc.x = powf(dir_vector.x, 2) + powf(dir_vector.y, 2);
  abc.x += powf(dir_vector.z, 2);
  abc.y = (eye_pos.x * dir_vector.x) + (eye_pos.y * dir_vector.y);
  abc.y += eye_pos.z * dir_vector.z;
  abc.y *= 2;
  abc.z = powf(eye_pos.x, 2) + powf(eye_pos.y, 2);
  abc.z += powf(eye_pos.z, 2);
  abc.z -= powf(radius, 2);
  return (abc);
}

float		intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector,
				 float radius)
{
  sfVector3f	abc;
  float		discriminant;
  float		sol;

  abc = define_quad_eq_vars(eye_pos, dir_vector, radius);
  discriminant = powf(abc.y, 2) - (4 * abc.x * abc.z);
  sol = solve_quadric_eq(discriminant, abc.x, abc.y);
  return (sol);
}

float		intersect_ltd_sphere(sfVector3f eye_pos,
				     sfVector3f dir_vector,
				     float radius,
				     t_object *object)
{
  sfVector3f	abc;
  float		discriminant;
  float		sol;

  abc = define_quad_eq_vars(eye_pos, dir_vector, radius);
  discriminant = powf(abc.y, 2) - (4 * abc.x * abc.z);
  abc.z = discriminant;
  sol = solve_ltd_quadric_eq(abc, eye_pos, dir_vector, object);
  return (sol);
}

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  return (intersection_point);
}
