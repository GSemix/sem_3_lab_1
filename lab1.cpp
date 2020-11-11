#include <iostream>
#include "lab1.h"

struct matrix * add_matrix (int x_max, int y_max, struct matrix * root) {
    int end;
    struct matrix * first = root;
    
    while (true) {
        struct matrix * elem = new struct matrix;
        
        std::cout << "[x] => ";
        std::cin >> elem->x;
            
        std::cout << std::endl << "[y] => ";
        std::cin >> elem->y;
            
        std::cout << std::endl << "[key] => ";
        std::cin >> elem->key;
        
        if (!root) {
            if (elem->key != 0) {
                root = new struct matrix;
                
                root->x = elem->x;
                root->y = elem->y;
                root->key = elem->key;
                root->next = NULL;
                
                first = root;
            }
            
            delete elem;
        } else {
            if (elem->key != 0) {
                elem->next = NULL;
                
                root->next = elem;
                root = root->next;
            } else {
                if (first->x == elem->x && first->y == elem->y) {
                    struct matrix * del = first;
                    first = first->next;
                    delete del;
                } else
                    delete_elem(first, elem->x, elem->y);
                
                delete elem;
            }
        }
        
        std::cout << std::endl << "(Input 1 for Continue) => ";
        std::cin >> end;
        std::cout << std::endl;
        
        if (end != 1)
            break;
    }
    
    return first;
}

void delete_elem (struct matrix * root, int x, int y) {
    struct matrix * del;

    while (root->next) {
        if (root->next->x == x && root->next->y == y) {
            del = root->next;
            root->next = root->next->next;
            delete del;
        }
    }
}

struct matrix * search (struct matrix * root, int x, int y) {
    while (root) {
        if (x == root->x && y == root->y)
            break;
        
        root = root->next;
    }
    
    return root;
}

void show_matrix (int x_max, int y_max, struct matrix * root) {
    struct matrix * elem;
    
    for (int y = 1; y <= y_max; y++) {
        for (int x = 1; x <= x_max; x++) {
            elem = search(root, x, y);
            
            if (elem)
                std::cout << elem->key << " ";
            else
                std::cout << "0 ";
        }
        
        std::cout << std::endl;
    }
}

void show_sort_matrix (int x_max, int y_max, struct matrix * sort_root, struct matrix * root) {
    struct matrix * elem;
    int x_min;
    
    for (int y = 1; y <= y_max; y++) {
        x_min = min_elem(root, y, x_max);
        
        for (int x = 1; x <= x_max; x++) {
            elem = search(sort_root, x, y);
            
            if (elem)
                std::cout << elem->key << " ";
            else {
                if (x >= x_min || !root)
                    std::cout << "0 ";
            }
        }
        
        std::cout << std::endl;
    }
}

int min_elem (struct matrix * root, int y, int x_max) {
    int x_min = 0;
    int min = 0;
    struct matrix * tmp = root;
    struct matrix * elem;
    
    while (root) {
        if (min == 0 && root->y == y) {
            min = root->key;
            x_min = root->x;
        }
        
        if (root->y == y && root->key < min) {
            min = root->key;
            x_min = root->x;
        }
            
        root = root->next;
    }
    
    if (min >= 0) {
        for (int x = 1; x < x_max; x++) {
            elem = search(tmp, x, y);
            
            if (!elem) {
                x_min = x;
                break;
            }
        }
    }

    return x_min;
}

struct matrix * sort_matrix (struct matrix * root, struct matrix * sort_root, int y_max, int x_max) {
    int x_min;
    struct matrix * tmp;
    struct matrix * start_sort_root;
    struct matrix * elem;
    
    for (int y = 1; y < y_max; y++) {
        tmp = root;
        x_min = min_elem(root, y, x_max);
        
        if (!search(root, x_min, y)) {
            elem = new struct matrix;
            
            elem->y = y;
            elem->x = x_min;
            elem->key = 0;
            elem->next = NULL;
            
            if (!sort_root) {
                sort_root = elem;
                start_sort_root = sort_root;
            } else {
                sort_root->next = elem;
                sort_root = sort_root->next;
            }
        }
        
        while (tmp) {
            if (tmp->y == y && tmp->x >= x_min) {
                elem = new struct matrix;
                
                elem->y = tmp->y;
                elem->x = tmp->x;
                elem->key = tmp->key;
                elem->next = NULL;
                
                if (!sort_root) {
                    sort_root = elem;
                    start_sort_root = sort_root;
                } else {
                    sort_root->next = elem;
                    sort_root = sort_root->next;
                }
            }
            
            tmp = tmp->next;
        }
    }
    
    return start_sort_root;
}

void clean (struct matrix * root, struct matrix * sort_root) {
    struct matrix * del;
    
    while (root != NULL) {
        del = root;
        root = root->next;
        delete del;
    }
    
    while (sort_root != NULL) {
        del = sort_root;
        sort_root = sort_root->next;
        delete del;
    }
}
