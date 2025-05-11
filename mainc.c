#include <stdio.h>
#include <stdlib.h>

#include "./lib/util/linked_list_int.c"
#include "./lib/util/linked_list_string.c"
#include "./lib/util/linked_list_float.c"

void main()
{
    ch8node *c1 = NULL;
    int c1_size = 0;
    add_ch8_node(&c1, "aa", &c1_size);
    add_ch8_node(&c1, "bb", &c1_size);
    add_ch8_node(&c1, "cc", &c1_size);
    add_ch8_node(&c1, "dd", &c1_size);
    add_ch8_node(&c1, "ee", &c1_size);
    view_ch8_node(c1, c1_size);
    poll_ch8_node(&c1, &c1_size);
    view_ch8_node(c1, c1_size);
    poll_ch8_node(&c1, &c1_size);
    poll_ch8_node(&c1, &c1_size);
    poll_ch8_node(&c1, &c1_size);
    view_ch8_node(c1, c1_size);
    poll_ch8_node(&c1, &c1_size);
    view_ch8_node(c1, c1_size);
    poll_ch8_node(&c1, &c1_size);
    printf("need to throw an error when there is nothing to remove check line 25\n");
    view_ch8_node(c1, c1_size);
    printf("Size: %d\n", size_ch8_node(c1_size));
    add_ch8_node(&c1, "aa", &c1_size);
    add_ch8_node(&c1, "bb", &c1_size);
    add_ch8_node(&c1, "cc", &c1_size);
    add_ch8_node(&c1, "dd", &c1_size);
    add_ch8_node(&c1, "ee", &c1_size);
    view_ch8_node(c1, c1_size);
    printf("Size: %d\n", size_ch8_node(c1_size));
    insert_at_ch8_node(&c1, "ff", 1, &c1_size);
    view_ch8_node(c1, c1_size);
    remove_ch8_node(&c1, "gg", &c1_size);
    view_ch8_node(c1, c1_size);
    printf("need to throw an error when there is no such character to remove ckeck line 38\n");
    view_ch8_node(c1, c1_size);
    reverse_ch8_node(&c1);
    view_ch8_node(c1, c1_size);
    printf(contains_ch8_node(&c1, "aa"));
    printf("\n");
    printf(contains_ch8_node(&c1, "gg"));
    printf("\n");
    printf(get_ch8_node(&c1, 7));
    printf("If we are trying to get a character that does not exist it should throw an error\n once check line 48 \n");
    printf(is_empty_ch8_node(&c1_size));
    printf("\n Size: %d\n", size_ch8_node(c1_size));
    poll_ch8_node(&c1, &c1_size);
    poll_ch8_node(&c1, &c1_size);
    poll_ch8_node(&c1, &c1_size);
    poll_ch8_node(&c1, &c1_size);
    poll_ch8_node(&c1, &c1_size);
    poll_ch8_node(&c1, &c1_size);
    view_ch8_node(c1, c1_size);
    printf(is_empty_ch8_node(&c1_size));
}
