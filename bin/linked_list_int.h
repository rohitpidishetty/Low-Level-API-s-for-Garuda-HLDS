#include <stdio.h>
#include <stdlib.h>

typedef struct int32_node
{
  int data;
  struct int32_node *next;
} i32node;

// Memory allocation function
i32node *alloc_mem_i32node();

// List manipulation functions
void add_i32_node(i32node **node, int data, int *magnitude);
void poll_i32_node(i32node **node, int *magnitude);
void pop_i32_node(i32node *root, int *magnitude);
void insert_at_i32_node(i32node **root, int value, int index, int *magnitude);
void delete_at_i32_node(i32node **root, int index, int *magnitude);
void remove_i32_node(i32node **root, int data, int *magnitude);

// Search and access functions
char *contains_i32_node(i32node **root, int data);
int get_i32_node(i32node **root, int index);
int index_of_i32_node(i32node **root, int value);
char *is_empty_i32_node(int *magnitude);

// Utility functions
int size_i32_node(int magnitude);
void clear_i32_node(i32node **root, int *magnitude);
void reverse_i32_node(i32node **root);
int max_i32_node(i32node **root);
int min_i32_node(i32node **root);
int sum_i32_node(i32node **root);
float average_i32_node(i32node **root, int *magnitude);

// Sorting functions
void hybrid_sort(i32node **root, int magnitude);
void extend_i32_node(i32node **root_0, i32node **root_1, int *root_0_mag, int *root_1_mag);
char *equals_i32_node(i32node **root_0, i32node **root_1, int *root_0_mag, int *root_1_mag);

// List viewing function
void view_i32_node(i32node *root, int l1_size);
