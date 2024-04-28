/*
** lauch.h for raytracer in /home/elise/delivery/raytracer1/include/
**
** Made by Élise Philippe
** Login   <elise.philippe@epitech.eu>
**
** Started on  Sat Mar 18 11:16:50 2017 Élise Philippe
** Last update Sun May 28 22:59:57 2017 Élise Philippe
*/

#ifndef LAUNCH_H_
# define LAUNCH_H_

int	window_loop(t_my_window *, t_env *, char *);
int	raytracer_launcher(char *file_name, int exprt, int a_aliasing);
int	import_launcher(char *file_name);
void	find_light(t_env* env);
void	find_eye(t_env* env);
int	raytracer_thread_launch(t_env *env);

#endif /* !LAUNCH_H_ */
