#include <stdio.h>
#include <stdlib.h>
#include "./lib/util/tree_set_float64.c"
int main()
{
  // Two sets
  f64_t_set *set1 = NULL;
  seed_f64_t_set(&set1, 1.1);
  seed_f64_t_set(&set1, 2.1);
  seed_f64_t_set(&set1, 3.1);
  f64_t_set *set2 = NULL;
  seed_f64_t_set(&set2, 4.1);
  seed_f64_t_set(&set2, 5.1);
  seed_f64_t_set(&set2, 3.1);

  // union_f64_t_set(&set1, &set2);

  f64node *ex = NULL;
  int ex_size = 0;
  elements_f64_t_set(&set1, &ex, &ex_size);

  view_f64_set(ex, ex_size);

  f64node *intsec = NULL;
  int intsec_size = 0;
  instersection_f64_t_set(&set1, &set2, &intsec, &intsec_size);

  view_f64_set(intsec, intsec_size);

  difference_f64_t_set(&set1, &set2);

  ex = NULL;
  ex_size = 0;
  elements_f64_t_set(&set1, &ex, &ex_size);
  printf("%d\n", ex_size);
  view_f64_set(ex, ex_size);
}