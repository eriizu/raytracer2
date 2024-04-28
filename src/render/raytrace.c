/*
** raytrace.c for raytracer in /home/elise/Projects/raytracer2/src/render/
**
** Made by Élise Philippe
** Login   <elise.philippe@epitech.eu>
**
** Started on  Sat Apr 15 13:26:22 2017 Élise Philippe
** Last update Wed Jun  7 22:33:20 2017 Élise Philippe
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

static int	hit_single_obj(t_render_in *in,
			       t_render_out *out,
			       t_object *objs)
{
  float		k;

  k = obj_fctn_shunter(objs, in);
  if (k >= 0 && (out->k == -1 || out->k > k))
    {
      out->k = (in->skip && k > 0 && k < 1) ? 1 : k;
      out->type = objs->type;
      out->last_obj = objs->id;
      out->reflect = objs->reflection;
      out->refract = objs->refraction;
      out->refract_idx = objs->refract_idx;
      if (in->skip && k > 0 && k < 1)
	return (1);
    }
  return (0);
}

void		objects_hit_attempt(t_env *env,
				    t_render_in *in,
				    t_render_out *out)
{
  t_object	*objs;

  objs = env->objects;
  if (objs && objs->id == in->skip)
    objs = objs->next;
  my_memset(out, 0, sizeof(t_render_out));
  out->k = -1;
  while (objs)
    {
      if (hit_single_obj(in, out, objs))
	return ;
      objs = objs->next;
      if (objs && objs->id == in->skip)
	objs = objs->next;
    }
  out->k = (out->k >= 0) ? out->k : 0;
  if (out->k >= 0)
    out->hit_pt = get_intersection(in->eye_pt, in->dir_vector, out->k);
}

static void	prep_ray(t_render_in *in,
			 t_env *env,
			 sfVector2i px,
			 int thread)
{
  int		sub_ray;

  sub_ray = in->sub_ray;
  px.y += thread * (SC_H / 4);
  my_memset(in, 0, sizeof(t_render_in));
  in->sub_ray = sub_ray;
  in->dir_vector = calc_sub_dir_vector(SC_W, env->screen_size,
				       px, in->sub_ray);
  in->dir_vector = rotate_xyz(in->dir_vector, env->eye_rt);
  in->eye_pt = env->eye_pt;
}

void		send_ray(t_env *env, t_px *px, int sub_ray, int id_thread)
{
  t_render_in	in;
  t_render_out	out;
  sfColor	old_color;

  in.sub_ray = sub_ray;
  prep_ray(&in, env, px->pos, id_thread);
  objects_hit_attempt(env, &in, &out);
  if (out.k > 0)
    {
      out.last_dir_v = in.dir_vector;
      old_color = px->color;
      set_color(env, &(px->color), &out, 0);
      px->color = get_color_avg(old_color, px->color, sub_ray);
    }
  else
    px->color = get_color_avg(px->color, MY_BLACK, sub_ray);
}

void		raytrace_full_scene(t_env *env, int id_thread)
{
  t_px		px;
  int		sub_ray;

  px.total_px = px.pos.x = px.pos.y = 0;
  while (px.pos.y < SC_H / 4)
    {
      px.color = sfBlack;
      sub_ray = 0;
      while (sub_ray <= ((env->a_aliasing) ? 4 : 0))
	send_ray(env, &px, sub_ray++, id_thread);
      my_put_pixel(env->w->buffer, px.pos.x,
		   px.pos.y + (id_thread * (SC_H / 4)), px.color);
      display_progress(&(px.total_px), 1);
      progress_to_next_px(&(px.total_px), &(px.pos));
    }
}
