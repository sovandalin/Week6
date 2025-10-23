#ifndef CAMBODIA_ADMIN_H
#define CAMBODIA_ADMIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 100
#define MAX_ID_LENGTH 20
#define MAX_CHILDREN 50

typedef enum {
    COUNTRY,
    PROVINCE,
    DISTRICT,
    COMMUNE,
    VILLAGE
} AdminType;

typedef struct TreeNode {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    AdminType type;
    struct TreeNode* children[MAX_CHILDREN];
    int child_count;
    struct TreeNode* parent;
} TreeNode;

typedef struct {
    TreeNode* root;
    TreeNode** nodes_by_id;
    char** node_ids;
    int node_count;
    int capacity;
} CambodiaAdminTree;

// Function prototypes
CambodiaAdminTree* create_admin_tree();
TreeNode* create_node(const char* name, const char* id, AdminType type);
void init_sample_data(CambodiaAdminTree* tree);
void destroy_tree(CambodiaAdminTree* tree);

// Core operations
void list_children(CambodiaAdminTree* tree, const char* node_id);
int count_descendants(TreeNode* node);
void find_parent(CambodiaAdminTree* tree, const char* node_id);
void path_to_root(CambodiaAdminTree* tree, const char* node_id);
void list_by_level(CambodiaAdminTree* tree, AdminType level);
void reparent_subtree(CambodiaAdminTree* tree, const char* subtree_id, const char* new_parent_id);
void search_node(CambodiaAdminTree* tree, const char* search_term);

// Helper functions
TreeNode* find_node_by_id(CambodiaAdminTree* tree, const char* id);
void add_child(TreeNode* parent, TreeNode* child);
void print_node(TreeNode* node);
const char* type_to_string(AdminType type);

#endif