//
// str 2 wordtab & co
// by ol


#include <stdlib.h>
#include <string.h>

int	mlx_int_str_str(char *str,char *find,int len)
{
  int	len_f;
  int	pos;
  char	*s;
  char	*f;

  len_f = strlen(find);
  if (len_f>len)
    return (-1);
  pos = 0;
  while (*(str+len_f-1))
    {
      s = str;
      f = find;
      while (*(f++) == *(s++))
        if (!*f)
          return (pos);
      str ++;
      pos ++;
    }
  return (-1);
}



int	mlx_int_str_str_cote(char *str,char *find,int len)
{
  int	len_f;
  int	pos;
  char	*s;
  char	*f;
  int	cote;

  len_f = strlen(find);
  if (len_f>len)
    return (-1);
  cote = 0;
  pos = 0;
  while (*(str+len_f-1))
    {
      if (*str=='"')
	cote = 1-cote;
      if (!cote)
	{
	  s = str;
	  f = find;
	  while (*(f++) == *(s++))
	    if (!*f)
	      return (pos);
	}
      str ++;
      pos ++;
    }
  return (-1);
}


char	**mlx_int_str_to_wordtab(char *str)
{
  char	**tab;
  int	pos;
  int	nb_word;
  int	len;

  len = strlen(str);
  nb_word = 0;
  pos = 0;
  while (pos<len)
  {
    while (*(str+pos)==' ' || *(str+pos)=='\t')
      pos ++;
    if (*(str+pos))
      nb_word ++;
    while (*(str+pos) && *(str+pos)!=' ' && *(str+pos)!='\t')
      pos ++;
  }
  if (!(tab = malloc((1+nb_word)*sizeof(*tab))))
    return ((char **)0);
  nb_word = 0;
  pos = 0;
  while (pos<len)
    {
      while (*(str+pos)==' ' || *(str+pos)=='\t')
	{
	  *(str+pos) = 0;
	  pos ++;
	}
      if (*(str+pos))
	{
	  tab[nb_word] = str+pos;
	  nb_word ++;
	}
      while (*(str+pos) && *(str+pos)!=' ' && *(str+pos)!='\t')
	pos ++;
    }
  tab[nb_word] = 0;
  return (tab);
}
