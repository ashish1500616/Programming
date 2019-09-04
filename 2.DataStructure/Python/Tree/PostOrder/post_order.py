def postorder(root, result):
    if not root:
        return
    postorder(root.left)
    postorder(root.right)
    result.append(root.data)
