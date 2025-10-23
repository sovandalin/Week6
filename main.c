#include "cambodia_admin.h"

void display_menu() {
    printf("\n=== Cambodia Administrative Structure Operations ===\n");
    printf("1. List children of a node\n");
    printf("2. Count descendants of a node\n");
    printf("3. Find parent of a node\n");
    printf("4. Show path to root\n");
    printf("5. List all nodes at specific level\n");
    printf("6. Reparent subtree\n");
    printf("7. Search by name/ID\n");
    printf("8. Exit\n");
    printf("Choose an operation: ");
}

int main() {
    CambodiaAdminTree* tree = create_admin_tree();
    if (!tree) {
        printf("Failed to create administrative tree\n");
        return 1;
    }
    
    int choice;
    char input[100];
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1:
                printf("Enter node ID: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                list_children(tree, input);
                break;
                
            case 2:
                printf("Enter node ID: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                {
                    TreeNode* node = find_node_by_id(tree, input);
                    if (node) {
                        int count = count_descendants(node);
                        printf("Total descendants of %s: %d\n", node->name, count);
                    } else {
                        printf("Node not found\n");
                    }
                }
                break;
                
            case 3:
                printf("Enter node ID: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                find_parent(tree, input);
                break;
                
            case 4:
                printf("Enter node ID: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                path_to_root(tree, input);
                break;
                
            case 5:
                printf("Enter level (0=Country, 1=Province, 2=District, 3=Commune, 4=Village): ");
                int level;
                scanf("%d", &level);
                list_by_level(tree, (AdminType)level);
                break;
                
            case 6:
                printf("Enter subtree ID to move: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                printf("Enter new parent ID: ");
                char parent_id[100];
                fgets(parent_id, sizeof(parent_id), stdin);
                parent_id[strcspn(parent_id, "\n")] = 0;
                reparent_subtree(tree, input, parent_id);
                break;
                
            case 7:
                printf("Enter search term: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                search_node(tree, input);
                break;
                
            case 8:
                destroy_tree(tree);
                printf("Goodbye!\n");
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}