#include "./lib/util/linked_list_int.c"
#include "./lib/util/linked_list_string.c"
#include "./lib/util/linked_list_float.c"
#include <stdio.h>
#include <stdlib.h>

void main()
{
    f64node *f1 = NULL;
    int f1_size = 0;

    add_f64_node(&f1, 4.1, &f1_size);
    add_f64_node(&f1, 4.2, &f1_size);
    add_f64_node(&f1, 4.3, &f1_size);
    add_f64_node(&f1, 4.4, &f1_size);
    add_f64_node(&f1, 4.51, &f1_size);
    add_f64_node(&f1, 4.6, &f1_size);

    view_f64_node(f1, f1_size);

    remove_f64_node(&f1, 4.2, &f1_size);
    view_f64_node(f1, f1_size);

    poll_f64_node(&f1, &f1_size);
    view_f64_node(f1, f1_size);

    remove_f64_node(&f1, 4.4, &f1_size);
    view_f64_node(f1, f1_size);
    

    add_f64_node(&f1, 4.7, &f1_size);
    view_f64_node(f1, f1_size);

    remove_f64_node(&f1, 4.6, &f1_size);
    view_f64_node(f1, f1_size);

    remove_f64_node(&f1, 4.51, &f1_size);
    view_f64_node(f1, f1_size);

    poll_f64_node(&f1, &f1_size);
    poll_f64_node(&f1, &f1_size);
    view_f64_node(f1, f1_size);

    add_f64_node(&f1, 4.1, &f1_size);
    view_f64_node(f1, f1_size);

    poll_f64_node(&f1, &f1_size);
    poll_f64_node(&f1, &f1_size);
    view_f64_node(f1, f1_size);

    add_f64_node(&f1, 4.1, &f1_size);
    add_f64_node(&f1, 4.2, &f1_size);
    add_f64_node(&f1, 4.3, &f1_size);
    add_f64_node(&f1, 4.4, &f1_size);
    add_f64_node(&f1, 4.51, &f1_size);
    add_f64_node(&f1, 4.6, &f1_size);
    view_f64_node(f1, f1_size);

    f64node *f2 = NULL;
    int f2_size = 0;
    add_f64_node(&f2, 1.1, &f2_size);
    view_f64_node(f2, f2_size);
    add_f64_node(&f2, 2.2, &f2_size);
    view_f64_node(f2, f2_size);
    add_f64_node(&f2, 3.3, &f2_size);
    add_f64_node(&f2, 4.4, &f2_size);
    view_f64_node(f2, f2_size);

    insert_at_f64_node(&f2, 2.22, 1, &f2_size);
    view_f64_node(f2, f2_size);

    insert_at_f64_node(&f2, 6.2, 4, &f2_size);
    view_f64_node(f2, f2_size);

    insert_at_f64_node(&f2, 7.1, 5, &f2_size);
    view_f64_node(f2, f2_size);

    printf("Contains 7.10: %s\n", contains_f64_node(&f2, 7.10));
    printf("Contains 7.13: %s\n", contains_f64_node(&f2, 7.13));
    printf("Get index 2: %.2f\n", get_f64_node(&f2, 2));
    printf("Get index 8: %.2f\n", get_f64_node(&f2, 8));
    printf("Is empty: %s\n", is_empty_f64_node(&f2_size));

    remove_f64_node(&f2, 2.2, &f2_size);
    view_f64_node(f2, f2_size);

    poll_f64_node(&f2, &f2_size);
    view_f64_node(f2, f2_size);

    poll_f64_node(&f2, &f2_size);
    view_f64_node(f2, f2_size);

    remove_f64_node(&f2, 3.30, &f2_size);
    view_f64_node(f2, f2_size);

    remove_f64_node(&f2, 1.76, &f2_size);
    view_f64_node(f2, f2_size);

    printf("[6.20, 7.104.40]\n");
}
