#include <iostream>
#include "lab1.h"

int main () {
    int x_max = 10;
    int y_max = 10;
    
    struct matrix * sort_root = NULL;
    struct matrix * root = NULL;
    
    root = add_matrix(x_max, y_max, root);
    show_matrix(x_max, y_max, root);
    sort_root = sort_matrix(root, sort_root, y_max, x_max);
    
    std::cout << "\n###########\n\n";
    
    show_sort_matrix(x_max, y_max, sort_root, root);
    clean(root, sort_root);
    
    return 0;
}
