#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_putchar(char c);
void sapin(int size);

int main(int argc, char**argv)
{
  if (argc != 2)
    return(1);
  int size;
  size = atoi(argv[1]);
  sapin(size);
  return(0);
}

void my_putchar(char c)
{
  write(1, &c, 1);
}

void sapin(int size)
{
  if (size == 0)
  {
    my_putchar(' ');
  }
  else
  {
    int nb_space = 0;
    int nb_char = 1;
    int nb_lines = 4;
    int nb_lines_total = 0;
    int i, j, k, m;
    int l = 0;
    int n;
    int nb_char_max;

    for (n=0; n < size; n++)
    {
      nb_lines_total += 4 + n;
    }

    nb_char_max = nb_lines_total + ((size + 1)/2) + 1 + size; // On récupère le nombre de char max pour gérer les spaces
    nb_lines_total = 0;

    for (i = 0; i < size; i++)
    {
      for (j = 0; j < nb_lines; j++)
      {
        l = 0;
        while (l < (nb_char_max - nb_char) / 2) // affichage des espaces
        {
          my_putchar(' ');
          l++;
        }
        for (k = 0; k < nb_char; k++) // affichage des char
        {
          my_putchar('*');
        }
        my_putchar('\n');
        nb_char = nb_char + 2;
      }
      k = 0;
      j = 0;
      nb_lines_total += nb_lines;
      nb_char = nb_lines_total + (((i+1)/2) + 1); // ajuster le nombre de char à afficher en fonction de la ligne
      nb_lines += 1;
    }
    int o = 0;
    for (l = 0; l < size; l++)
    {
      o = 0;
      while (o < (nb_char_max / 2 - (size / 2)))
      {
        my_putchar(' ');
        o++;
      }
      for (m = 0; m < size; m++) // Gestion du tronc
      {
      my_putchar('|');
      }
    my_putchar('\n');
    m = 0;
    }
  }
}
