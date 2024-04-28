/*
** match.c for raytracer in /home/elise/delivery/raytracer1/src/data_gathering/
**
** Made by Élise Philippe
** Login   <elise.philippe@epitech.eu>
**
** Started on  Thu Feb 16 14:58:50 2017 Élise Philippe
** Last update Thu Feb 16 15:05:12 2017 Élise Philippe
*/

int	match(char *s1, char *s2)
{
  int	exit;

  exit = 0;
  if (*s1 && *s2 == '*')
    exit = (match(s1 + 1, s2) || match(s1, s2 + 1));
  else if (!*s1 && *s2 == '*')
    exit = match(s1, s2 + 1);
  else if (*s1 == *s2 && *s1)
    exit = match(s1 + 1, s2 + 1);
  else if (*s1 == *s2 && !*s1)
    exit = 1;
  return (exit);
}
