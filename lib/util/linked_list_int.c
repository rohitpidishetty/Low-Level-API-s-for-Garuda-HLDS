#include <stdio.h>
#include <stdlib.h>

typedef struct int32_node
{
  int data;
  struct int32_node *next;
} i32node;

i32node *alloc_mem_i32node()
{
  return (i32node *)malloc(sizeof(i32node));
}

void add_i32_node(i32node **node, int data, int *magnitude)
{
  i32node *new_node = alloc_mem_i32node();
  if ((*node) == NULL)
  {
    new_node->data = data;
    new_node->next = NULL;
    *node = new_node;
  }
  else
  {
    new_node->data = data;
    new_node->next = NULL;
    i32node *curr = *node;
    while (curr->next != NULL)
      curr = curr->next;
    curr->next = new_node;
  }
  (*magnitude)++;
}

void poll_i32_node(i32node **node, int *magnitude)
{
  i32node *root = *node;
  if (root == NULL)
    return;
  *node = (root)->next;
  free(root);
  (*magnitude)--;
}

void view_i32_node(i32node *root, int l1_size)
{
  int position = 1;
  printf("[");
  while (root != NULL)
  {
    printf(position < l1_size ? "%d, " : "%d", root->data);
    root = root->next;
    position++;
  }
  printf("]\n");
}

// void pop_i32_node(i32node *root, int *magnitude)
// {
//   if (root == NULL)
//     return;
//   i32node *prev_node = NULL;
//   while (root->next != NULL)
//   {
//     prev_node = root;
//     root = root->next;
//   }
//   prev_node->next = NULL;
//   free(root);
//   (*magnitude) -= 1;
// }

void pop_i32_node(i32node **root, int *magnitude)
{
  if (*root == NULL || *magnitude == 0)
    return;

  i32node *current = *root;
  i32node *prev_node = NULL;

  while (current->next != NULL)
  {
    prev_node = current;
    current = current->next;
  }

  if (prev_node == NULL)
  {
    // Only one node in the list
    free(*root);
    *root = NULL;
  }
  else
  {
    prev_node->next = NULL;
    free(current);
  }

  (*magnitude) -= 1;
}

int size_i32_node(int magnitude)
{
  return magnitude;
}

void insert_at_i32_node(i32node **root, int value, int index, int *magnitude)
{
  int position = 0;
  i32node *new_node = alloc_mem_i32node();
  new_node->data = value;
  i32node *prev_node = NULL;
  i32node *current_node = *root;

  if (index == 0)
  {
    new_node->next = (*root);
    *root = new_node;
    (*magnitude)++;
    return;
  }

  while (current_node != NULL)
  {
    if (index == position)
    {
      i32node *successor = prev_node->next;
      prev_node->next = new_node;
      new_node->next = successor;
      (*magnitude)++;
      break;
    }
    prev_node = current_node;
    current_node = current_node->next;
    position++;
  }
}

void delete_at_i32_node(i32node **root, int index, int *magnitude)
{
  i32node *prev_node = NULL;
  i32node *current_node = (*root);
  int position = 0;
  if (index > (*magnitude) - 1)
  {
    printf("List out of bound error\n");
    exit(1);
  }
  if (index == 0)
  {
    poll_i32_node(&(*root), magnitude);
    return;
  }
  while (current_node != NULL)
  {
    if (position == index)
    {
      prev_node->next = current_node->next;
      break;
    }
    prev_node = current_node;
    current_node = current_node->next;
    position++;
  }
  (*magnitude)--;
}

void remove_i32_node(i32node **root, int data, int *magnitude)
{
  i32node *prev_node = NULL;
  i32node *current = *root;
  int removed = 0;
  while (current != NULL)
  {
    if (current->data == data)
    {
      removed = 1;
      if (prev_node == NULL)
      {
        i32node *head = *root;
        *root = head->next;
        free(head);
        (*magnitude)--;
        return;
      }
      else
        prev_node->next = current->next;
    }
    prev_node = current;
    current = current->next;
  }
  if (removed == 1)
    (*magnitude)--;
  else
  {
    printf("Element %d not found\n", data);
    exit(1);
  }
}

int contains_i32_node(i32node **root, int data)
{
  i32node *current = *root;
  while (current != NULL)
  {
    if (current->data == data)
    {
      return 1;
      break;
    }
    current = current->next;
  }
  return 0;
}

int get_i32_node(i32node **root, int index)
{
  int position = 0;
  i32node *current = *root;
  while (current != NULL)
  {
    if (position == index)
      return current->data;
    current = current->next;
    position++;
  }
  return -1;
}

int index_of_i32_node(i32node **root, int value)
{
  int position = 0;
  i32node *current = *root;
  while (current != NULL)
  {
    if (current->data == value)
      return position;
    current = current->next;
    position++;
  }
  return -1;
}

int is_empty_i32_node(int *magnitude)
{
  if ((*magnitude) == 0)
    return 1;
  return 0;
}

void clear_i32_node(i32node **root, int *magnitude)
{
  i32node *current = *root;
  while (current != NULL)
  {
    i32node *next = current->next;
    free(current);
    current = next;
  }
  *root = NULL;
  *magnitude = 0;
}

void reverse_i32_node(i32node **root)
{
  i32node *current = *root;
  i32node *prev_node = NULL;
  i32node *next = NULL;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev_node;
    prev_node = current;
    current = next;
  }

  *root = prev_node;
}

int max_i32_node(i32node **root)
{
  i32node *current = *root;
  int maximum = -0x80000000; // -2147483648
  while (current != NULL)
  {
    if (current->data >= maximum)
      maximum = current->data;
    current = current->next;
  }
  return maximum;
}

int min_i32_node(i32node **root)
{
  i32node *current = *root;
  int minimum = 0x7FFFFFFF; // 2147483647
  while (current != NULL)
  {
    if (current->data < minimum)
      minimum = current->data;
    current = current->next;
  }
  return minimum;
}

int sum_i32_node(i32node **root)
{
  i32node *current = *root;
  int summation = 0;
  while (current != NULL)
  {
    summation += current->data;
    current = current->next;
  }
  return summation;
}

float average_i32_node(i32node **root, int *magnitude)
{
  int sum = sum_i32_node(root);
  return ((float)sum / (float)(*magnitude));
}

i32node *merge_lists(i32node *a, i32node *b)
{
  if (!a)
    return b;
  if (!b)
    return a;
  i32node *result = NULL;
  if (a->data <= b->data)
  {
    result = a;
    result->next = merge_lists(a->next, b);
  }
  else
  {
    result = b;
    result->next = merge_lists(a, b->next);
  }
  return result;
}

void split_list(i32node *source, i32node **front_ref, i32node **back_ref)
{
  i32node *slow = source;
  i32node *fast = source->next;
  while (fast != NULL)
  {
    fast = fast->next;
    if (fast != NULL)
    {
      slow = slow->next;
      fast = fast->next;
    }
  }
  *front_ref = source;
  *back_ref = slow->next;
  slow->next = NULL;
}

i32node *insertion_sort_list(i32node *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  i32node *sorted = NULL;
  while (head != NULL)
  {
    i32node *current = head;
    head = head->next;
    if (sorted == NULL || current->data < sorted->data)
    {
      current->next = sorted;
      sorted = current;
    }
    else
    {
      i32node *temp = sorted;
      while (temp->next != NULL && temp->next->data < current->data)
        temp = temp->next;
      current->next = temp->next;
      temp->next = current;
    }
  }
  return sorted;
}

i32node *merge_sort_list(i32node *head)
{
  if (!head || !head->next)
    return head;
  i32node *a = NULL;
  i32node *b = NULL;
  split_list(head, &a, &b);
  a = merge_sort_list(a);
  b = merge_sort_list(b);
  return merge_lists(a, b);
}

void hybrid_sort_i32_node(i32node **root, int magnitude)
{
  *root = (magnitude <= 75) ? insertion_sort_list(*root) : merge_sort_list(*root);
}

void extend_i32_node(i32node **root_0, i32node **root_1, int *root_0_mag, int *root_1_mag)
{
  i32node *curr = *root_0;
  while (curr->next != NULL)
    curr = curr->next;
  curr->next = (*root_1);
  (*root_0_mag) += (*root_1_mag);
}

int equals_i32_node(i32node **root_0, i32node **root_1, int *root_0_mag, int *root_1_mag)
{
  i32node *r0 = *root_0;
  i32node *r1 = *root_1;

  if ((*root_0_mag) != (*root_1_mag))
    return 0;
  while (r0 != NULL && r1 != NULL)
  {
    if (r0->data != r1->data)
      return 0;
    r0 = r0->next;
    r1 = r1->next;
  }

  return 1;
}
// ----------------------------
// void main()
// {
//   // list<int> l1 = new list<>()
//   i32node *l1 = NULL;
//   int l1_size = 0;

//   // l1.push(1)
//   add_i32_node(&l1, 1, &l1_size);
//   // l1.push(2)
//   add_i32_node(&l1, 2, &l1_size);
//   // l1.push(3)
//   add_i32_node(&l1, 3, &l1_size);
//   // l1.push(4)
//   add_i32_node(&l1, 4, &l1_size);
//   // l1.print()
//   view_i32_node(l1, l1_size);
//   // l1.pop()
//   pop_i32_node(l1, &l1_size);
//   // l1.print()
//   view_i32_node(l1, l1_size);
//   // d = l1.size()
//   // print(d)
//   int d = size_i32_node(l1_size);
//   printf("%d\n", d);
//   // l1.insertAt(1, 12)
//   insert_at_i32_node(&l1, 12, 1, &l1_size);
//   // l1.insertAt(2, 24)
//   insert_at_i32_node(&l1, 24, 2, &l1_size);
//   // l1.insertAt(0, -24)
//   insert_at_i32_node(&l1, -24, 0, &l1_size);
//   // l1.insertAt(5, -4)
//   insert_at_i32_node(&l1, -4, 5, &l1_size);
//   // l1.push(40)
//   add_i32_node(&l1, 40, &l1_size);
//   // l1.print()
//   view_i32_node(l1, l1_size);
//   // l1.poll()
//   poll_i32_node(&l1, &l1_size);
//   // l1.print()
//   view_i32_node(l1, l1_size);
//   // l1.deleteAt(3)
//   delete_at_i32_node(&l1, 0, &l1_size);
//   // l1.print()
//   view_i32_node(l1, l1_size);
//   // l1.push(400)
//   add_i32_node(&l1, 400, &l1_size);
//   // l1.print()
//   view_i32_node(l1, l1_size);
//   // l1.remove(40)
//   remove_i32_node(&l1, 40, &l1_size);
//   // l1.print()
//   view_i32_node(l1, l1_size);
//   // l1.remove(40)
//   remove_i32_node(&l1, 12, &l1_size);
//   // l1.print()
//   view_i32_node(l1, l1_size);
//   // s = l1.contains(400)
//   // print(s)
//   char *s = contains_i32_node(&l1, 400);
//   printf("%s\n", s);
//   // n = l1.get(4)
//   // print(n)
//   int n = get_i32_node(&l1, 4);
//   printf("%d\n", n);
//   // n = l1.indexOf(400)
//   // print(n)
//   n = index_of_i32_node(&l1, -4);
//   printf("%d\n", n);
//   // s = l1.isEmpty()
//   // print(s)
//   s = is_empty_i32_node(&l1_size);
//   printf("%s\n", s);
//   // l1.clear()
//   // clear_i32_node(&l1, &l1_size);
//   // l1.print()
//   view_i32_node(l1, l1_size);
//   // s = l1.isEmpty()
//   // print(s)
//   s = is_empty_i32_node(&l1_size);
//   printf("%s\n", s);
//   // l1.reverse()
//   reverse_i32_node(&l1);
//   // l1.add(123)
//   add_i32_node(&l1, 123, &l1_size);
//   // l1.view()
//   view_i32_node(l1, l1_size);
//   // d = l1.size()
//   // print(d)
//   d = size_i32_node(l1_size);
//   printf("%d\n", d);
//   // d = l1.max()
//   // print(d)
//   d = max_i32_node(&l1);
//   printf("%d\n", d);
//   // d = l1.min()
//   // print(d)
//   d = min_i32_node(&l1);
//   printf("%d\n", d);
//   // d = l1.sum()
//   // print(d)
//   d = sum_i32_node(&l1);
//   printf("%d\n", d);
//   // d2 = l1.avg()
//   // print(d2)
//   float d2 = average_i32_node(&l1, &l1_size);
//   printf("%f\n", d2);
//   // l1.sort()
//   hybrid_sort(&l1, l1_size);
//   // l1.view()
//   view_i32_node(l1, l1_size);
//   // l1.add(234)
//   add_i32_node(&l1, 234, &l1_size);
//   // l1.view()
//   view_i32_node(l1, l1_size);
//   // d = l1.size()
//   // print(d)
//   d = size_i32_node(l1_size);
//   printf("%d\n", d);

//   // list<int> l2 = new list<>()
//   i32node *l2 = NULL;
//   int l2_size = 0;

//   // l2.push(11)
//   add_i32_node(&l2, 1, &l2_size);
//   // l2.push(12)
//   add_i32_node(&l2, 2, &l2_size);
//   // l2.push(13)
//   add_i32_node(&l2, 3, &l2_size);
//   // l2.push(14)
//   add_i32_node(&l2, 4, &l2_size);
//   // s = l1.equals(l2)
//   // print(s)
//   s = equals_i32_node(&l1, &l2, &l1_size, &l2_size);
//   printf("%s\n", s);
//   // l1.extend(l2)
//   extend_i32_node(&l1, &l2, &l1_size, &l2_size);
//   view_i32_node(l1, l1_size);
//   // d = l1.size()
//   // print(d)
//   d = size_i32_node(l1_size);
//   printf("%d\n", d);
// }

/**
list<int> l1 = new list<>()
l1.push(1)
l1.push(2)
l1.push(3)
l1.push(4)
l1.print()
l1.pop()
l1.print()
d = l1.size()
print(d)
l1.insertAt(1, 12)
l1.insertAt(2, 24)
l1.insertAt(0, -24)
l1.insertAt(5, -4)
l1.push(40)
l1.print()
l1.poll()
l1.print()
l1.deleteAt(3)
l1.print()
l1.push(400)
l1.print()
l1.remove(40)
l1.print()
l1.remove(40)
l1.print()
s = l1.contains(400)
print(s)
n = l1.get(4)
print(n)
n = l1.indexOf(400)
print(n)
s = l1.isEmpty()
print(s)
l1.clear()
l1.print()
s = l1.isEmpty()
print(s)
l1.reverse()
l1.add(123)
l1.view()
d = l1.size()
print(d)
d = l1.max()
print(d)
d = l1.min()
print(d)
d = l1.sum()
print(d)
d2 = l1.avg()
print(d2)
l1.sort()
l1.view()
l1.add(234)
l1.view()
d = l1.size()
print(d)

list<int> l2 = new list<>()
l2.push(11)
l2.push(12)
l2.push(13)
l2.push(14)
s = l1.equals(l2)
print(s)
l1.extend(l2)
l1.view()
d = l1.size()
print(d)
 */