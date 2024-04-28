/*
** my_strcat.c for lacp in /home/elise/Projects/new_gnl/lib/acp/src/print/
**
** Made by Élise Philippe
** Login   <elise.philippe@epitech.eu>
**
** Started on  Mon May  8 11:15:52 2017 Élise Philippe
** Last update Mon May  8 11:16:34 2017 Élise Philippe
*/

char	*my_strcat(char *s1, char *s2)
{
  int	i1;
  int	i2;

  i1 = 0;
  i2 = 0;
  while (s1[i1])
    i1 += 1;
  while (s2[i2])
    {
      s1[i1] = s2[i2];
      i1 += 1;
      i2 += 1;
    }
  s1[i1] = '\0';
  return (s1);
}
