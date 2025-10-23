#include "cambodia_admin.h"

CambodiaAdminTree* create_admin_tree() {
    CambodiaAdminTree* tree = (CambodiaAdminTree*)malloc(sizeof(CambodiaAdminTree));
    if (!tree) return NULL;
    
    tree->capacity = 100;
    tree->node_count = 0;
    tree->nodes_by_id = (TreeNode**)malloc(sizeof(TreeNode*) * tree->capacity);
    tree->node_ids = (char**)malloc(sizeof(char*) * tree->capacity);
    
    // Create root node (Cambodia)
    tree->root = create_node("Cambodia", "KHM", COUNTRY);
    tree->nodes_by_id[0] = tree->root;
    tree->node_ids[0] = strdup("KHM");
    tree->node_count = 1;
    
    init_sample_data(tree);
    return tree;
}

TreeNode* create_node(const char* name, const char* id, AdminType type) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) return NULL;
    
    strncpy(node->name, name, MAX_NAME_LENGTH - 1);
    strncpy(node->id, id, MAX_ID_LENGTH - 1);
    node->type = type;
    node->child_count = 0;
    node->parent = NULL;
    
    for (int i = 0; i < MAX_CHILDREN; i++) {
        node->children[i] = NULL;
    }
    
    return node;
}

void add_child(TreeNode* parent, TreeNode* child) {
    if (parent->child_count < MAX_CHILDREN) {
        parent->children[parent->child_count++] = child;
        child->parent = parent;
    }
}

void init_sample_data(CambodiaAdminTree* tree) {
    // Create provinces
    TreeNode* phnom_penh = create_node("Phnom Penh", "PP", PROVINCE);
    TreeNode* siem_reap = create_node("Siem Reap", "SR", PROVINCE);
    TreeNode* battambang = create_node("Battambang", "BT", PROVINCE);

    add_child(tree->root, phnom_penh);
    add_child(tree->root, siem_reap);
    add_child(tree->root, battambang);

    // Add to index
    tree->nodes_by_id[tree->node_count] = phnom_penh;
    tree->node_ids[tree->node_count] = strdup("PP");
    tree->node_count++;
    
    tree->nodes_by_id[tree->node_count] = siem_reap;
    tree->node_ids[tree->node_count] = strdup("SR");
    tree->node_count++;

    tree->nodes_by_id[tree->node_count] = battambang;
    tree->node_ids[tree->node_count] = strdup("BT");
    tree->node_count++;
    
    // Create districts under Phnom Penh
    TreeNode* chamkarmon = create_node("Chamkar Mon", "PP-01", DISTRICT);
    TreeNode* tuol_kork = create_node("Tuol Kork", "PP-02", DISTRICT);
    TreeNode* daun_penh = create_node("Daun Penh", "PP-03", DISTRICT);
    
    add_child(phnom_penh, chamkarmon);
    add_child(phnom_penh, tuol_kork);
    add_child(phnom_penh, daun_penh);
    
    // Index districts
    tree->nodes_by_id[tree->node_count] = chamkarmon;
    tree->node_ids[tree->node_count] = strdup("PP-01");
    tree->node_count++;
    
    tree->nodes_by_id[tree->node_count] = tuol_kork;
    tree->node_ids[tree->node_count] = strdup("PP-02");
    tree->node_count++;
    
    tree->nodes_by_id[tree->node_count] = daun_penh;
    tree->node_ids[tree->node_count] = strdup("PP-03");
    tree->node_count++;
    
    // Create communes under Chamkar Mon
    TreeNode* tonle_bassi = create_node("Tonle Bassac", "PP-01-01", COMMUNE);
    TreeNode* boeung_keng_kang = create_node("Boeung Keng Kang", "PP-01-02", COMMUNE);
    
    add_child(chamkarmon, tonle_bassi);
    add_child(chamkarmon, boeung_keng_kang);
    
    // Index communes
    tree->nodes_by_id[tree->node_count] = tonle_bassi;
    tree->node_ids[tree->node_count] = strdup("PP-01-01");
    tree->node_count++;
    
    tree->nodes_by_id[tree->node_count] = boeung_keng_kang;
    tree->node_ids[tree->node_count] = strdup("PP-01-02");
    tree->node_count++;
    
    // Create villages
    TreeNode* village1 = create_node("Village 1", "PP-01-01-01", VILLAGE);
    TreeNode* village2 = create_node("Village 2", "PP-01-01-02", VILLAGE);
    TreeNode* village3 = create_node("Village 3", "PP-01-02-01", VILLAGE);
    
    add_child(tonle_bassi, village1);
    add_child(tonle_bassi, village2);
    add_child(boeung_keng_kang, village3);
    
    // Index villages
    tree->nodes_by_id[tree->node_count] = village1;
    tree->node_ids[tree->node_count] = strdup("PP-01-01-01");
    tree->node_count++;
    
    tree->nodes_by_id[tree->node_count] = village2;
    tree->node_ids[tree->node_count] = strdup("PP-01-01-02");
    tree->node_count++;
    
    tree->nodes_by_id[tree->node_count] = village3;
    tree->node_ids[tree->node_count] = strdup("PP-01-02-01");
    tree->node_count++;

    // --- Add Siem Reap districts, communes, villages ---
    // Districts
    TreeNode* siem_reap_city = create_node("Siem Reap City", "SR-01", DISTRICT);
    TreeNode* angkor_chum = create_node("Angkor Chum", "SR-02", DISTRICT);

    add_child(siem_reap, siem_reap_city);
    add_child(siem_reap, angkor_chum);

    // Index Siem Reap districts
    tree->nodes_by_id[tree->node_count] = siem_reap_city;
    tree->node_ids[tree->node_count] = strdup("SR-01");
    tree->node_count++;

    tree->nodes_by_id[tree->node_count] = angkor_chum;
    tree->node_ids[tree->node_count] = strdup("SR-02");
    tree->node_count++;

    // Communes under Siem Reap City
    TreeNode* svay_dong = create_node("Svay Dangkum", "SR-01-01", COMMUNE);
    TreeNode* krom = create_node("Krom", "SR-01-02", COMMUNE);

    add_child(siem_reap_city, svay_dong);
    add_child(siem_reap_city, krom);

    tree->nodes_by_id[tree->node_count] = svay_dong;
    tree->node_ids[tree->node_count] = strdup("SR-01-01");
    tree->node_count++;

    tree->nodes_by_id[tree->node_count] = krom;
    tree->node_ids[tree->node_count] = strdup("SR-01-02");
    tree->node_count++;

    // Villages under Svay Dangkum
    TreeNode* svay_vill1 = create_node("Svay Village 1", "SR-01-01-01", VILLAGE);
    TreeNode* svay_vill2 = create_node("Svay Village 2", "SR-01-01-02", VILLAGE);

    add_child(svay_dong, svay_vill1);
    add_child(svay_dong, svay_vill2);

    tree->nodes_by_id[tree->node_count] = svay_vill1;
    tree->node_ids[tree->node_count] = strdup("SR-01-01-01");
    tree->node_count++;

    tree->nodes_by_id[tree->node_count] = svay_vill2;
    tree->node_ids[tree->node_count] = strdup("SR-01-01-02");
    tree->node_count++;

    // Villages under Krom
    TreeNode* krom_vill1 = create_node("Krom Village 1", "SR-01-02-01", VILLAGE);
    add_child(krom, krom_vill1);
    tree->nodes_by_id[tree->node_count] = krom_vill1;
    tree->node_ids[tree->node_count] = strdup("SR-01-02-01");
    tree->node_count++;

    // Communes under Angkor Chum
    TreeNode* angkor_chum_comm1 = create_node("Angkor Chum Commune 1", "SR-02-01", COMMUNE);
    TreeNode* angkor_chum_comm2 = create_node("Angkor Chum Commune 2", "SR-02-02", COMMUNE);

    add_child(angkor_chum, angkor_chum_comm1);
    add_child(angkor_chum, angkor_chum_comm2);

    tree->nodes_by_id[tree->node_count] = angkor_chum_comm1;
    tree->node_ids[tree->node_count] = strdup("SR-02-01");
    tree->node_count++;

    tree->nodes_by_id[tree->node_count] = angkor_chum_comm2;
    tree->node_ids[tree->node_count] = strdup("SR-02-02");
    tree->node_count++;

    // Villages under Angkor Chum communes
    TreeNode* ac_vill1 = create_node("Angkor Chum Village 1", "SR-02-01-01", VILLAGE);
    TreeNode* ac_vill2 = create_node("Angkor Chum Village 2", "SR-02-02-01", VILLAGE);

    add_child(angkor_chum_comm1, ac_vill1);
    add_child(angkor_chum_comm2, ac_vill2);

    tree->nodes_by_id[tree->node_count] = ac_vill1;
    tree->node_ids[tree->node_count] = strdup("SR-02-01-01");
    tree->node_count++;

    tree->nodes_by_id[tree->node_count] = ac_vill2;
    tree->node_ids[tree->node_count] = strdup("SR-02-02-01");
    tree->node_count++;
}

// Operation 1: List Children of X
void list_children(CambodiaAdminTree* tree, const char* node_id) {
    TreeNode* node = find_node_by_id(tree, node_id);
    if (!node) {
        printf("Node %s not found\n", node_id);
        return;
    }
    
    printf("Children of %s (%s):\n", node->name, type_to_string(node->type));
    for (int i = 0; i < node->child_count; i++) {
        printf("  - %s (%s)\n", node->children[i]->name, 
               type_to_string(node->children[i]->type));
    }
}

// Operation 2: Count Descendants of X
int count_descendants(TreeNode* node) {
    if (!node) return 0;
    
    int total = 0;
    for (int i = 0; i < node->child_count; i++) {
        total += 1 + count_descendants(node->children[i]);
    }
    return total;
}

// Operation 3: Find Parent of X
void find_parent(CambodiaAdminTree* tree, const char* node_id) {
    TreeNode* node = find_node_by_id(tree, node_id);
    if (!node) {
        printf("Node %s not found\n", node_id);
        return;
    }
    
    if (node->parent) {
        printf("Parent of %s: %s (%s)\n", node->name, 
               node->parent->name, type_to_string(node->parent->type));
    } else {
        printf("%s is the root node (no parent)\n", node->name);
    }
}

// Operation 4: Path to Root
void path_to_root(CambodiaAdminTree* tree, const char* node_id) {
    TreeNode* node = find_node_by_id(tree, node_id);
    if (!node) {
        printf("Node %s not found\n", node_id);
        return;
    }
    
    printf("Path from %s to root:\n", node->name);
    TreeNode* current = node;
    while (current) {
        printf("  -> %s (%s)\n", current->name, type_to_string(current->type));
        current = current->parent;
    }
}

// Operation 5: Level Listing
void list_by_level_helper(TreeNode* node, AdminType target_level) {
    if (!node) return;
    
    if (node->type == target_level) {
        printf("  - %s (%s)\n", node->name, node->id);
    }
    
    for (int i = 0; i < node->child_count; i++) {
        list_by_level_helper(node->children[i], target_level);
    }
}

void list_by_level(CambodiaAdminTree* tree, AdminType level) {
    printf("All %s level administrative units:\n", type_to_string(level));
    list_by_level_helper(tree->root, level);
}

// Operation 6: Reparent Subtree (Simplified)
void reparent_subtree(CambodiaAdminTree* tree, const char* subtree_id, const char* new_parent_id) {
    TreeNode* subtree = find_node_by_id(tree, subtree_id);
    TreeNode* new_parent = find_node_by_id(tree, new_parent_id);
    
    if (!subtree || !new_parent) {
        printf("Invalid nodes specified\n");
        return;
    }
    
    // Remove from current parent
    if (subtree->parent) {
        TreeNode* old_parent = subtree->parent;
        for (int i = 0; i < old_parent->child_count; i++) {
            if (old_parent->children[i] == subtree) {
                // Shift remaining children
                for (int j = i; j < old_parent->child_count - 1; j++) {
                    old_parent->children[j] = old_parent->children[j + 1];
                }
                old_parent->child_count--;
                break;
            }
        }
    }
    
    // Add to new parent
    add_child(new_parent, subtree);
    printf("Successfully moved %s under %s\n", subtree->name, new_parent->name);
}

// Operation 7: Search by Name/ID
void search_node(CambodiaAdminTree* tree, const char* search_term) {
    printf("Search results for '%s':\n", search_term);
    bool found = false;
    
    for (int i = 0; i < tree->node_count; i++) {
        if (strstr(tree->nodes_by_id[i]->name, search_term) != NULL ||
            strcmp(tree->nodes_by_id[i]->id, search_term) == 0) {
            printf("  - %s (%s) [%s]\n", tree->nodes_by_id[i]->name,
                   tree->nodes_by_id[i]->id, type_to_string(tree->nodes_by_id[i]->type));
            found = true;
        }
    }
    
    if (!found) {
        printf("  No matches found\n");
    }
}

// Helper Functions
TreeNode* find_node_by_id(CambodiaAdminTree* tree, const char* id) {
    for (int i = 0; i < tree->node_count; i++) {
        if (strcmp(tree->node_ids[i], id) == 0) {
            return tree->nodes_by_id[i];
        }
    }
    return NULL;
}

void print_node(TreeNode* node) {
    if (node) {
        printf("%s (%s) - %s\n", node->name, node->id, type_to_string(node->type));
    }
}

const char* type_to_string(AdminType type) {
    switch (type) {
        case COUNTRY: return "Country";
        case PROVINCE: return "Province";
        case DISTRICT: return "District";
        case COMMUNE: return "Commune";
        case VILLAGE: return "Village";
        default: return "Unknown";
    }
}

void destroy_tree(CambodiaAdminTree* tree) {
    if (!tree) return;
    
    // Free all node IDs
    // Free all nodes (each node pointer stored in nodes_by_id)
    for (int i = 0; i < tree->node_count; i++) {
        if (tree->nodes_by_id[i]) {
            free(tree->nodes_by_id[i]);
        }
    }

    // Free node id strings
    for (int i = 0; i < tree->node_count; i++) {
        if (tree->node_ids[i]) {
            free(tree->node_ids[i]);
        }
    }

    // Free the arrays
    free(tree->nodes_by_id);
    free(tree->node_ids);
    
    free(tree);
}