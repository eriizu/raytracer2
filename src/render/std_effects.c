/*
** std_effects.c for raytracer in /home/elise/Projects/raytracer2/src/render/
**
** Made by Élise Philippe
** Login   <elise.philippe@epitech.eu>
**
** Started on  Mon Apr 17 16:14:09 2017 Élise Philippe
** Last update Thu May 25 15:35:54 2017 Élise Philippe
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

static void	prep_ray(t_render_in *in,
			 t_render_out *pr_out,
			 t_env *env)
{
  in->dir_vector.x = env->light.x - pr_out->hit_pt.x;
  in->dir_vector.y = env->light.y - pr_out->hit_pt.y;
  in->dir_vector.z = env->light.z - pr_out->hit_pt.z;
  in->eye_pt = pr_out->hit_pt;
  in->skip = pr_out->last_obj;
}

static void	prep_light_and_normal(sfVector3f *light,
				      sfVector3f *normal,
				      t_env *env,
				      t_render_out *pr_out)
{
  t_object	*objs;
  sfVector3f	hit;

  objs = env->objects;
  while (objs && objs->id != pr_out->last_obj)
    objs = objs->next;
  if (objs && objs->id == pr_out->last_obj)
    {
      hit = translate_inv(pr_out->hit_pt, objs->pos);
      hit = rotate_xyz_inv(hit, objs->rot);
      *light = rotate_xyz_inv(*light, objs->rot);
      if (objs->type == 1)
	*normal = get_normal_sphere(hit);
      else if (objs->type == 2)
	*normal = get_normal_plane(pr_out->last_dir_v.z);
      else if (objs->type == 3)
	*normal = get_normal_cylinder(hit);
      else if (objs->type == 4)
	*normal = get_normal_cone(hit, objs->size_a);
      *normal = rotate_xyz(*normal, objs->rot);
    }
}

float		std_color_effect(t_env *env, t_render_out *pr_out)
{
  t_render_in	in;
  t_render_out	nw_out;
  sfVector3f	light_v;
  sfVector3f	normal_v;
  float		coef;

  my_memset(&normal_v, 0, sizeof(sfVector3f));
  my_memset(&light_v, 0, sizeof(sfVector3f));
  my_memset(&in, 0, sizeof(t_render_in));
  prep_ray(&in, pr_out, env);
  objects_hit_attempt(env, &in, &nw_out);
  prep_light_and_normal(&light_v, &normal_v, env, pr_out);
  if (nw_out.k == 1)
    coef = 0;
  else
    {
      light_v = in.dir_vector;
      coef = get_light_coef(light_v, normal_v);
    }
  coef += (coef < 0.9) ? 0.1 : 1 - coef;
  pr_out->normal = normal_v;
  return (coef);
}
