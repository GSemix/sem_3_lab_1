#include <iostream>

struct matrix {
    int x;
    int y;
    int key;
    struct matrix * next;
};

struct matrix * add_matrix (int x_max, int y_max, struct matrix * root);
void show_matrix (int x_max, int y_max, struct matrix * root);
struct matrix * search (struct matrix * root, int x, int y);
int min_elem (struct matrix * root, int y, int x_max);
struct matrix * sort_matrix (struct matrix * root, struct matrix * sort_root, int y_max, int x_max);
void show_sort_matrix (int x_max, int y_max, struct matrix * sort_root, struct matrix * root);
void clean (struct matrix * root, struct matrix * sort_root);
void delete_elem (struct matrix * root, int x, int y);
