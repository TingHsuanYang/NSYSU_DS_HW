#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
class Node
{
private:
    Node *left;
    Node *right;
    Node *parent;
    int number;
public:
    Node(int n)
    {
        left = NULL;
        right = NULL;
        parent = NULL;
        number = n;
    }
    int GetNum()
    {
        return this->number;
    }
    //get maximum number of the tree
    int GetMax()
    {
        if(right == NULL)return number;
        return right->GetMax();
    }
    // get minimum number of this tree
    int GetMin()
    {
        if(left == NULL) return number;
        return left->GetMin();
    }
    friend class BST;
};

class BST
{
private:
    Node* root;
public:
    Node* Search(int n)
    {
        Node *cur = root;
        while(cur != NULL && n != cur->number) { // compare n to current node
            if(n < cur->number)cur = cur->left;
            else cur = cur->right;
        }
        return cur;
    }
    void Insert(int n)
    {
        Node *c = NULL; // current node, future place for insert node
        Node *p = NULL; // current node's parent
        Node *i = new Node(n); // insert node
        c = root;
        while(c != NULL) { //find insert place util it is NULL
            p = c; // update parent
            if(n < c->number)c = c->left; //move current to left child
            else c = c->right;
        }
        i->parent = p;
        if(p == NULL) { // empty tree
            this->root = i;
        } else if(i->number < p->number) {
            p->left = i;
        } else {
            p->right = i;
        }
    }
    // replace this node with max of left subtree or min of right subtree, then delete the leaf
    void Delete(int n)
    {
        Node *d = Search(n);
        if(d == NULL) {
            cout << "data not found" << endl;
            return;
        }

        if(d == root) { // deal with root
            if(d->left == NULL && d->right == NULL) {
                root = NULL;
//				d=NULL; //為何不行?
            } else if( d->right != NULL) {
                int min = d->right->GetMin();
                Delete(min);
                d->number = min;
            } else if(d->left != NULL) {
                int max = d->left->GetMax();
                Delete(max);
                d->number = max;
            }
        } else if(d->left == NULL && d->right == NULL) { // the node is leaf
            if(d->parent->left == d)d->parent->left = NULL;
            else d->parent->right = NULL;
            delete d;
        } else { // the node has child
            if(d->right != NULL) { // replace with min of right subtree
                int m = d->right->GetMin();
                Delete(m);
                d->number = m;
            } else { // replace with max of left subtree
                int m = d->left->GetMax();
                Delete(m); // delete m first, else it will find m every time
                d->number = m;
            }
        }
    }
    void Show()
    {
        cout << "node:  " ;
        InorderPrint(root);
        cout << endl ;

        cout << "left:  " ;
        InorderPrintLeft(root);
        cout << endl ;

        cout << "right: " ;
        InorderPrintRight(root);
        cout << endl ;
    }
    void AddNumber(int n)
    {
        Node *s = Search(n);
        if(s == NULL) {
            Insert(n);
        } else {
            Delete(n);
        }
    }
private:
    void InorderPrint(Node* inputN)
    {
        if(inputN == NULL)return;
        InorderPrint(inputN->left);
        printf("%3d ", inputN->number);
        InorderPrint(inputN->right);
    }
    void InorderPrintLeft(Node* inputN)
    {
        if(inputN == NULL)return;
        InorderPrintLeft(inputN->left);
        if(inputN->left == NULL)printf("%3d ", 0);
        else printf("%3d ", inputN->left->number);
        InorderPrintLeft(inputN->right);
    }
    void InorderPrintRight(Node* inputN)
    {
        if(inputN == NULL)return;
        InorderPrintRight(inputN->left);
        if(inputN->right == NULL)printf("%3d ", 0);
        else printf("%3d ", inputN->right->number);
        InorderPrintRight(inputN->right);
    }
};

int main()
{
 	BST *bst ;
 	int n = 0;
    while(cin>>n) {
        bst = new BST();
        while(n != -1) {
            bst->AddNumber(n);
            cin >> n;
        }
        bst->Show();
        delete bst;
    }
    return 0;
}
