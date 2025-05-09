#define LINKED_LIST_INT

#include <stdio.h>
#include <stdlib.h>

#include "linked_list_int.h"

void main()
{
  i32node *l1 = NULL;
  int l1_size = 0;

  add_i32_node(&l1, 1, &l1_size);
  add_i32_node(&l1, 2, &l1_size);
  add_i32_node(&l1, 3, &l1_size);
  add_i32_node(&l1, 4, &l1_size);
  view_i32_node(l1, l1_size);
  pop_i32_node(l1, &l1_size);
  view_i32_node(l1, l1_size);
  int d = size_i32_node(l1_size);
  printf("%d\n", d);
  insert_at_i32_node(&l1, 12, 1, &l1_size);
  insert_at_i32_node(&l1, 24, 2, &l1_size);
  insert_at_i32_node(&l1, -24, 0, &l1_size);
  insert_at_i32_node(&l1, -4, 5, &l1_size);
  add_i32_node(&l1, 40, &l1_size);
  view_i32_node(l1, l1_size);
  poll_i32_node(&l1, &l1_size);
  view_i32_node(l1, l1_size);
  delete_at_i32_node(&l1, 0, &l1_size);
  view_i32_node(l1, l1_size);
  add_i32_node(&l1, 400, &l1_size);
  view_i32_node(l1, l1_size);
  remove_i32_node(&l1, 40, &l1_size);
  view_i32_node(l1, l1_size);
  remove_i32_node(&l1, 12, &l1_size);
  view_i32_node(l1, l1_size);
  char *s = contains_i32_node(&l1, 400);
  printf("%s\n", s);
  int n = get_i32_node(&l1, 4);
  printf("%d\n", n);
  n = index_of_i32_node(&l1, -4);
  printf("%d\n", n);
  s = is_empty_i32_node(&l1_size);
  printf("%s\n", s);
  view_i32_node(l1, l1_size);
  s = is_empty_i32_node(&l1_size);
  printf("%s\n", s);
  reverse_i32_node(&l1);
  add_i32_node(&l1, 123, &l1_size);
  view_i32_node(l1, l1_size);
  d = size_i32_node(l1_size);
  printf("%d\n", d);
  d = max_i32_node(&l1);
  printf("%d\n", d);
  d = min_i32_node(&l1);
  printf("%d\n", d);
  d = sum_i32_node(&l1);
  printf("%d\n", d);
  float d2 = average_i32_node(&l1, &l1_size);
  printf("%f\n", d2);
  hybrid_sort(&l1, l1_size);
  view_i32_node(l1, l1_size);
  add_i32_node(&l1, 234, &l1_size);
  view_i32_node(l1, l1_size);
  d = size_i32_node(l1_size);
  printf("%d\n", d);

  i32node *l2 = NULL;
  int l2_size = 0;
  add_i32_node(&l2, 1, &l2_size);
  add_i32_node(&l2, 2, &l2_size);
  add_i32_node(&l2, 3, &l2_size);
  add_i32_node(&l2, 4, &l2_size);
  s = equals_i32_node(&l1, &l2, &l1_size, &l2_size);
  printf("%s\n", s);
  extend_i32_node(&l1, &l2, &l1_size, &l2_size);
  view_i32_node(l1, l1_size);
  d = size_i32_node(l1_size);
  printf("%d\n", d);


  // --------------------



  /**
   * dict<str, int> map = new dict<>(10)
   */
  int map_size = 10;
  ch8node_i32node_Tree *map[map_size];
  for (int i = 0; i < map_size; i++)
    map[i] = NULL;

  /**
   * map.set("hello", 10)
   */

  set_dict_ch8k_i32v(map, "hello", __ch8_key_hash("hello", &map_size), 10);
  // // --------------
  set_dict_ch8k_i32v(map, "world", __ch8_key_hash("world", &map_size), 5674);
  set_dict_ch8k_i32v(map, "how", __ch8_key_hash("how", &map_size), 3434);
  /**
   * map.set("are", 234)
   */
  set_dict_ch8k_i32v(map, "are", __ch8_key_hash("are", &map_size), 234);

  /**
   * v = map.get(7)
   */
  int v = get_dict_ch8k_i32v(map, "hello", &map_size);
  printf("%d\n", v);

  v = get_dict_ch8k_i32v(map, "how", &map_size);
  printf("%d\n", v);

  /**
   * map.remove(7)
   */
  remove_dict_ch8k_i32v(map, "how", __ch8_key_hash("how", &map_size));

  v = get_dict_ch8k_i32v(map, "how", &map_size);
  printf("%d\n", v);

  /**
   * keys = map.keys()
   * keys.view()
   */

  ch8node *keys = NULL;
  int keys_size = 0;
  keys_dict_ch8k_i32v(map, &map_size, &keys, &keys_size);
  view_ch8_node(keys, keys_size);

  /**
   * values = map.values()
   * values.view()
   */
  i32node *values = NULL;
  int values_size = 0;
  values_dict_ch8k_i32v(map, &map_size, &values, &values_size);
  view_i32_node(values, values_size);

  /**
   * items = map.items()
   * items.view()
   */
  ch8node *items = NULL;
  int items_size = 0;
  items_dict_ch8k_i32v(map, &map_size, &items, &items_size);
  view_ch8_node(items, items_size);

  /**
   * map.clear()
   */
  clear_dict_ch8k_i32v(map, &map_size);


}
