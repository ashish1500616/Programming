def non_recursive_preorder(root, result):
    if not root:
        return

    stack = []
    stack.append(root)

    while stack:
        node = stack.pop()
        result.append(root.data)
        if node.left:
            stack.append(node.left)
        if node.right:
            stack.append(node.right)

    # Time Complexity = O(n)
    # Space Complexity =O(n)
