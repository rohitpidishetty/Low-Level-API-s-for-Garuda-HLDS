#include <stdio.h>
#include <stdlib.h>
#include "./lib/util/tree_set_string.c"
int main()
{
  // Two sets
  ch8_t_set *set1 = NULL;
  seed_ch8_t_set(&set1, "ram");
  seed_ch8_t_set(&set1, "ramesh");
  seed_ch8_t_set(&set1, "rakesh");
  ch8_t_set *set2 = NULL;
  seed_ch8_t_set(&set2, "ram");
  seed_ch8_t_set(&set2, "rasheesh");
  seed_ch8_t_set(&set2, "ravi");

  union_ch8_t_set(&set1, &set2);

  ch8node *ex = NULL;
  int ex_size = 0;
  elements_ch8_t_set(&set1, &ex, &ex_size);

  view_ch8_set(ex, ex_size);

  ch8node *intsec = NULL;
  int intsec_size = 0;
  instersection_ch8_t_set(&set1, &set2, &intsec, &intsec_size);

  view_ch8_set(intsec, intsec_size);

  difference_ch8_t_set(&set1, &set2);

  ex = NULL;
  ex_size = 0;
  elements_ch8_t_set(&set1, &ex, &ex_size);

  view_ch8_set(ex, ex_size);
}