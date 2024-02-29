## C - Binary trees
`new_node` is the pointer to the newly created node. It will later be used to update the left child of the parent node and link the new node to the tree structure.

### pre-oder traversal:
    - Visit the current node after its children.
    - The sequence is: Root, Left, Right.
    - Useful when you want to create a deep copy of the tree or create a prefix expression for expression trees
                        .-------(A)-------.
                    .--(B)--.         .--(C)--.
                    (D)     (E)     (F)     (G)
    pre-order: A, B, D, E, C, F, G

### In-oder Traversal:
    - Visit the left subtree, then the root and later the right sub-tree
    - The sequence is: Left, Root, Right

                        .-------(A)-------.
                    .--(B)--.         .--(C)--.
                    (D)     (E)     (F)     (G)
    In-order: D, B, E, A, F, C, G

### Post-order Traversal:
    - Visit the current node after its children.
    - The sequence is: Left, Right, Root.
    - Useful for deleting nodes in a tree, as it ensures that a node's children are deleted before the node itself.

                    .-------(A)-------.
                .--(B)--.         .--(C)--.
                (D)     (E)     (F)     (G)

    post-order: D, E, B, F, G, C, A