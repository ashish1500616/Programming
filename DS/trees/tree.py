class BinaryTreeNode:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
    def set_data(self,data):
        self.data=data

    def get_data(self,data):
        return self.data

    def get_left(self):
        return self.left

    def get_right(self):
        return self.get_right

    def insert_left(self,new_node):
        if self.left == None:
            self.left =BinaryTreeNode(new_node)
        else:
            temp=BinaryTreeNode(new_node)
            temp.left=self.left
            self.left=temp

    def insert_right(self,new_node):
        if self.right == None :
            self.right=BinaryTreeNode(new_node)
        else:
            temp=BinaryTreeNode(new_node)
            temp.right=self.right
            self.right=temp


    def insert_in_binary_tree(root,data):
        new_node=BinaryTree(data)
        if root is None:
            root=new_node
            return root
        q=Queue()
        q.en_queue(root)
        node=None
        while not q.is_empty():
            node=q.de_queue()
            if data==node.get_data():
                return root
            if node.left is not None:
