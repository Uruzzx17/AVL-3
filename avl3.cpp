public class AVLTree extends BTreePrinter{
    Node root;

    public void singleRotateFromLeft(Node y) {
      if (y == null || y.left == null) return;
      
      Node x = y.left;
      Node w = y.parent;
      Node x2 = x.right;
      
      y.left = x2;
      
      if(x2 != null) {
      x2.parent = y;
      }
      
      x.right = y;
      y.parent = x;
      
      x.parent = w;
      
      if(w == null) root = x;
      else if(w.left == y) w.left = x;
      else w.right = x;
    }

    public void singleRotateFromRight(Node y) {
      if (y == null || y.right == null) return;
      
      Node x = y.right;
      Node w = y.parent;
      Node x2 = x.left;
      
      y.right = x2;
      
      if(x2 != null) {
      x2.parent = y;
      }
      
      x.left = y;
      y.parent = x;
      
      x.parent = w;
      
      if(w == null) root = x;
      else if(w.left == y) w.left = x;
      else w.right = x;
    }

    public void doubleRotateFromLeft(Node y) {
        if (y == null || y.left == null) return;
        Node x = y.left;
        
        if(x == null || x.right == null) return;
        Node z = x.right;
        Node w = y.parent;
        
        Node z1 = z.left;
        Node z2 = z.right;
        
        y.left = z2;
        if(z2 != null) z2.parent = y;
        x.right = z1;
        if(z1 != null) z1.parent = x;
        
        z.left = x;
        x.parent = z;
        z.right = y;
        y.parent = z;
        
        z.parent = w;
        if(w == null) root = z;
        else if(w.left == y) w.left = z;
        else w.right = z;
    }

    public void doubleRotateFromRight(Node y) {
        if (y == null || y.right == null) return;
        Node x = y.right;
        
        if(x == null || x.left == null) return;
        Node z = x.left;
        Node w = y.parent;
        
        Node z1 = z.left;
        Node z2 = z.right;
        
        x.left = z2;
        if(z2 != null) z2.parent = x;
        y.right = z1;
        if(z1 != null) z1.parent = y;
        
        z.left = y;
        y.parent = z;
        z.right = x;
        x.parent = z;
        
        z.parent = w;
        if(w == null) root = z;
        else if(w.left == y) w.left = z;
        else w.right = z;
    }

    public static void rebalance(AVLTree tree, Node node){
        int balanceFactor = 0;              // Calculate balanceFactor
        balanceFactor = height(node.left) - height(node.right);
        if (balanceFactor >1 || balanceFactor <-1){                          // Use balanceFactor to check if unbalanced?
            if (balanceFactor > 1){                      // Use balanceFactor to check if left heavy?
                if (height(node.left.left) >= height(node.left.right)){                  // Use the grandchild to check if Outer or Inner?
                    System.out.println("Perform SingleRotationFromLeft(Node " + node.key +")");   // Fix ??? and call a function
                    tree.singleRotateFromLeft(node);
                }else{
                    System.out.println("Perform DoubleRotationFromLeft(Node " + node.key +")");   // Fix ??? and call a function
                    tree.doubleRotateFromLeft(node);
                }
            }else{
                if (height(node.right.right) >= height(node.right.left)){                  // Use the grandchild to check if Outer or Inner?
                    System.out.println("Perform SingleRotationFromRight(Node " + node.key +")");   // Fix this and call a function
                    tree.singleRotateFromRight(node);
                }else{
                    System.out.println("Perform DoubleRotationFromRight(Node " + node.key +")");   // Fix this and call a function
                    tree.doubleRotateFromRight(node);
                }
            }
        }
    }
    
    // Fix this function to have the rebalancing feature
    // There should be rebalance() function calling somewhere in the code
    public static void insertKey(AVLTree tree, Node node, int key) {
        if (key == node.key) {
            System.out.println("Duplicated key:" + key);
        }else if (key < node.key) {//Go left
            if (node.left == null) {
                node.left = new Node(key);
                node.left.parent = node;
            }else {
                insertKey(tree, node.left, key);
            }
        }else{  // Go right
            if (node.right == null) {
                node.right = new Node(key);
                node.right.parent = node;
            }else {
                insertKey(tree, node.right, key);
            }
        }
        rebalance(tree,node);
    }
    
    // This function is complete, no need to edit
    public void insertKey(int key) {
        if (root == null) {
            root = new Node(key);
        } else {
            insertKey(this, root, key);
        }
    }
    
    // This function is complete, no need to edit
    public Node findKey(int search_key) {
        return Main.findKey(root, search_key);
    }

    // Use this function to check the node height
    // This function is complete, no need to edit
    public static int height(Node node){
        if (node == null)
            return -1;
        else
            return 1 + Math.max(height(node.left), height(node.right));
    }
}
