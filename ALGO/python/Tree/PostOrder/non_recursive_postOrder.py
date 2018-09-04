 def recursive_post_order(root, result):
     if not root:
         return
    visited=set()
    stack=[]
    node=root
    while stack or node:
        if node:
            stack.append(node)
            node=node.left
        else:
            node=stack.pop()
            if node.right and not node.right in visited:
                stack.append(node)
                node=node.right
            else:
                visited.add(node)
                result.append(node.data)
                node.None
