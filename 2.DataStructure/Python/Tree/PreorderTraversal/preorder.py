def preorder_recursive(root, result):
    if not root:
        return

    result.append(root.data)
    preorder_recursive(root.left, result)
    preorder_recursive(root.right, result)

# Time Complexity = O(n)
# Space Complexity =O(n)
