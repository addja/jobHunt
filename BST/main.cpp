#include<iostream>

using namespace std;

// Binary tree data structure
// right child has smaller values than parent
// left child has bigger values than parent
// both childs are BST

template <class T>
class BSTree {
  private:
    struct node {
      node* right;
      node* left;
      T elem;

      node(T e) {
        right = NULL; left = NULL; elem = e;
      }
    };

    node* root;

    void inorder(node * n) {
      if (n != NULL) {
        inorder(n->left);
        cout << " " << n->elem;
        inorder(n->right);
      }
    }

    void postorder(node * n) {
      if (n != NULL) {
        postorder(n->left);
        postorder(n->right);
        cout << " " << n->elem;
      }
    }

    void preorder(node * n) {
      if (n != NULL) {
        cout << " " << n->elem;
        preorder(n->left);
        preorder(n->right);
      }
    }

    node * minInorder(node * root) {
      if (root == NULL) return NULL;
      node * n = root;
      while (n->left != NULL) n = n->left;
      return n;
    }

    node * deleteRec(node * root, T elem) {
        if (root == NULL) return root;
        else if (elem > root->elem) {
          root->right = deleteRec(root->right,elem);
        }
        else if (elem < root->elem) {
          root->left = deleteRec(root->left,elem);
        }
        else {
          node * n;
          if (root->left == NULL) {
            n = root->right; delete root; return n;
          }
          else if (root->right == NULL) {
            n = root->left; delete root; return n;
          }

          n = minInorder(root->right);
          root->elem = n->elem;
          root->right = deleteRec(root->right, n->elem);
        }
        return root;
    }

  public:
    BSTree() {
      root = NULL;
    }

    void insert(T elem) {
      if (root == NULL) {
        root = new node(elem);
        return;
      }
      node * n = root;
      while (n != NULL) {
        if (n->elem < elem) {
          if (n->right == NULL) {
            n->right = new node(elem);
            break;
          }
          n = n->right;
        }
        else {
          if (n->left == NULL) {
            n->left = new node(elem);
            break;
          }
          n = n->left;
        }
      }
    }

    void inorderTraversal() {
      cout << "Printing inorder traversal";
      inorder(root); cout << endl;
    }

    void postorderTraversal() {
      cout << "Printing postorder traversal";
      postorder(root); cout << endl;
    }

    void preorderTraversal() {
      cout << "Printing preorder traversal";
      preorder(root); cout << endl;
    }

    bool search(T elem) {
      if (root == NULL) return false;
      node *n = root;
      while (n != NULL) {
        if (n->elem == elem) return true;
        else if (n->elem < elem) n = n->right;
        else n = n->left;
      }
      return false;
    }

    void deleteNode(T elem) {
      if (root == NULL) return;
      root = deleteRec(root,elem);
    }

};

int main() {
  BSTree<int> t;
  //  BSTree<int> * t = new BSTree<int>(); alternative
  t.insert(50); t.insert(30); t.insert(20); t.insert(40);
  t.insert(70); t.insert(60); t.insert(80);

  t.inorderTraversal();

  if (t.search(50)) cout << "Found 50!" << endl;
  if (t.search(42)) cout << "Found 42!" << endl;

  t.deleteNode(50); cout << "50 deleted" << endl;

  t.inorderTraversal();
  t.preorderTraversal();
  t.postorderTraversal();

}
