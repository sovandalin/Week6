## About
 This small exercise implements a tree-based data structure in C to model administrative units (Country → Province → District → Commune → Village). It includes a simple CLI (in `main.c`) with operations to list children, count descendants, find parents, show paths to root, list by level, reparent subtrees, and search by name or ID.

 ## Files
 - `cambodia_admin.c` - implementation of the tree and operations
 - `cambodia_admin.h` - declarations and data structures
 - `main.c` - CLI interface to interact with the admin tree

 ## Build

 ```sh
 gcc -o admin main.c cambodia_admin.c
 ```

 ## Run

 ```sh
 ./admin
 ```

 ## Usage
 After running the program, choose an operation from the menu. Enter node IDs like `SR` for Siem Reap or `PP` for Phnom Penh district codes used in the sample. Use option 5 to list all nodes at a specific administrative level (0=Country .. 4=Village).

 
