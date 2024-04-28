/*
** launch.c for raytracer in /home/elise/Projects/raytracer2/src/
**
** Made by Élise Philippe
** Login   <elise.philippe@epitech.eu>
**
** Started on  Wed Apr 19 15:52:50 2017 Élise Philippe
** Last update Sun May 28 11:00:07 2017 Élise Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include "acp.h"
#include "raytracer.h"
#include "raytracer_messages.h"
#include "raytracer_data.h"
#include "launch.h"

int		raytracer_launcher(char *file_name,
				   int exprt,
				   int a_aliasing)
{
  t_my_window	w;
  t_env		env;

  env.w = &w;
  env.objects = get_objects_from_file(file_name);
  if (!env.objects)
    return (EXIT_FAIL);
  find_eye(&env);
  find_light(&env);
  env.screen_size.x = SC_W;
  env.screen_size.y = SC_H;
  env.a_aliasing = a_aliasing;
  if (!(w.buffer = my_framebuffer_create(SC_W, SC_H)))
    return (EXIT_FAIL);
  raytracer_thread_launch(&env);
  open_window(&w, file_name);
  if (exprt && export_render(file_name, env.w->buffer) == -1)
    acp_print("export error");
  while (window_loop(&w, &env, file_name));
  destroy_objects(env.objects);
  window_destroy(&w);
  return (0);
}
