/*
** launch_import.c for raytracer in /home/elise/Projects/raytracer2/src/
**
** Made by Élise Philippe
** Login   <elise.philippe@epitech.eu>
**
** Started on  Sat Apr 22 13:45:47 2017 Élise Philippe
** Last update Mon May  1 22:37:24 2017 Élise Philippe
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include "raytracer.h"
#include "raytracer_data.h"
#include "raytracer_messages.h"
#include "launch.h"
#include "acp.h"

int		framebuffer_from_file(char *file_name,
				      t_fbuffer *buffer)
{
  int		fd;
  t_fbuffer	ingest;

  acp_print(HINT_LOAD_FB, file_name);
  errno = 0;
  if ((fd = open(file_name, O_RDONLY)) == -1
      || read(fd, &ingest, sizeof(t_fbuffer)) != sizeof(t_fbuffer))
    {
      fd_errors(errno, file_name);
      return (-1);
    }
  if (ingest.width != SC_W || ingest.height != SC_H)
    {
      acp_print("import error\n");
      return (-1);
    }
  if (read(fd, buffer->pixels, ingest.width * ingest.height * 4)
      != ingest.width * ingest.height * 4)
    return (-1);
  buffer->width = ingest.width;
  buffer->height = ingest.height;
  return (EXIT_SUCCESS);
}

int	import_launcher(char *file_name)
{
  t_my_window	w;

  if (!(w.buffer = my_framebuffer_create(SC_W, SC_H)))
    return (EXIT_FAIL);
  if ((framebuffer_from_file(file_name, w.buffer)) == -1)
    return (EXIT_FAIL);
  open_window(&w, file_name);
  while (window_loop(&w, NULL, file_name));
  window_destroy(&w);
  return (EXIT_SUCCESS);
}
