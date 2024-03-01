## C - Binary trees
`new_node` is the pointer to the newly created node. It will later be used to update the left child of the parent node and link the new node to the tree structure.

### pre-order traversal:
    - Also called depth-first-value method
    - Implemented on a stack
    - The sequence is: Root, Left, Right.
    - Useful when you want to create a deep copy of the tree or create a prefix expression for expression trees
                        .-------(A)-------.
                    .--(B)--.         .--(C)--.
                    (D)     (E)     (F)     (G)
    pre-order sequence: A, B, D, E, C, F, G

### Level-order traversal
    - Also called breadth-first-values method
    - Traverses through the tree level
    - Can also be implemented using queues

                     .-------(A)-------.
                .--(B)--.         .--(C)--.
                (D)     (E)     (F)     (G)
    Sequence: A, B, C, D, E, F, G

### In-order Traversal:
    - Visit the left subtree, then the root and later the right sub-tree
    - The sequence is: Left, Root, Right

                        .-------(A)-------.
                    .--(B)--.         .--(C)--.
                    (D)     (E)     (F)     (G)
    In-order sequence: D, B, E, A, F, C, G

### Post-order Traversal:
    - Visit the current node after its children.
    - The sequence is: Left, Right, Root.
    - Useful for deleting nodes in a tree, as it ensures that a node's children are deleted before the node itself.

                    .-------(A)-------.
                .--(B)--.         .--(C)--.
                (D)     (E)     (F)     (G)

    post-order sequence: D, E, B, F, G, C, A

### Perfect binary tree:
    - A binary tree is considered perfect if it is both full and complete
        - Full: Every node in the tree has either 0 or 2 children(no nodes have only one child).
        - Complete: All levels of the tree are completely filled.

### Sibling of a node
    - Two nodes are siblings if they have the same parent node

                    .-------(A)-------.
                .--(B)--.         .--(C)--.
                (D)     (E)     (F)     (G)
    - B & C are siblings for parent A
    - D & E are siblings for parent B
    - F & G are siblings for parent C

### Uncle in binary tree
    - The uncle of a node is its parent's sibling, and it could be either on the left or right side of the parent.
    - The key is that the uncle shares the same parent with the node's parent.

                            .-------(A)-------.
                        .--(B)--.         .--(C)--.
                        (D)     (E)     (F)     (G)

    - The uncle to D & E is C
    - The uncle to F & G is B

### complete binary tree
    - A binary tree is considered complete if all levels, except possibly the last, are completely filled, and all nodes are as left as possible.
    - All levels, except possibly the last, must have the maximum number of nodes. This ensures that nodes are filled from left to right on each level.
    - If the last level is not completely filled, it must be filled from left to right.

                    .-------(A)-------.
                 .--(B)--.       .--(C)--.    Complete
                (D)     (E)     (F)     (G)

                    .-------(A)-------.
                .--(B)--.         .--(C)--.   Incomplete
                (D)              (F)

                    .-------(A)-------.
                .--(B)--.         .--(C)--.   Complete
            .--(D)--.  (E)       (F)      (G)
            (H)