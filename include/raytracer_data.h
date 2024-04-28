/*
** raytracer_data.h for raytracer1 in /home/elise/delivery/raytracer1/include/
**
** Made by Élise Philippe
** Login   <elise.philippe@epitech.eu>
**
** Started on  Sat Feb 18 13:51:25 2017 Élise Philippe
** Last update Sat May 27 12:10:20 2017 Élise Philippe
*/

#ifndef RAYTRACER_DATA_H_
# define RAYTRACER_DATA_H_

t_object	*get_objects_from_file(char *file_name);
t_object	*create_object(char *buffer, int *idx);
char		*file_to_buffer(char *file_name);
void		*fd_errors(int e, char *f_name);
int		match(char *, char *);
t_object	*add_to_object_list(t_object *new_object,
				    t_object *objects);
t_object	*create_list_node();
int		check_list_content(t_object *list, char *file_name);
char		*get_object_type(int);
int		add_brightness_reflect(char *buffer,
				       int *idx,
				       t_object *new_object);
int		add_pr_texture(char *buffer,
			       int *idx,
			       t_object *new_object);

extern int g_hash[];

#endif /* !RAYTRACER_DATA_H_ */
