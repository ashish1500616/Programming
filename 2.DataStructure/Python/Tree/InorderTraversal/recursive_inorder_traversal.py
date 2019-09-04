def recursive_inorder(root, result):
    if root is None:
        return
    recursive_inorder(root.left, result)
    result.append(root.data)
    recursive_inorder(root.right, result)
