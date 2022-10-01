/*Algorithm Preorder(tree)

1.Visit the root.
2.Traverse the left subtree, i.e., call Preorder(left->subtree)
3.Traverse the right subtree, i.e., call Preorder(right->subtree) */
#include <iostream>

using namespace std;

typedef struct node Node;
struct node
{
    int root;
    Node *left_node;
    Node *right_node;
};

Node *create_tree_node(int item);
void add_node_left(Node *root, Node *child);
void add_node_right(Node *root, Node *child);
Node *create_tree(void);
void pre_order(Node *root);

int main(void)
{
    Node *root;

    root = create_tree();
    cout << "Root data: " << root->root << endl;

    pre_order(root);

    return 0;
}

// create tree node
Node *create_tree_node(int item)
{
    Node *new_node = new Node;

    if(new_node == NULL)
    {
        cout << "Error! Could not crate a new node." << endl;
        exit(1);
    }

    new_node->root = item;
    new_node->left_node = NULL;
    new_node->right_node = NULL;

    return new_node;
    delete new_node;
}

// add node left
void add_node_left(Node *root, Node *child)
{
    root->left_node = child;
}

// add node right
void add_node_right(Node *root, Node *child)
{
    root->right_node = child;
}

// create Tree
Node *create_tree(void)
{
    Node *five = create_tree_node(5);
    Node *nine = create_tree_node(9);
    Node *three = create_tree_node(3);
    add_node_left(five, nine);
    add_node_right(five, three);

    Node *four = create_tree_node(4);
    Node *eight = create_tree_node(8);
    add_node_left(nine, four);
    add_node_right(nine, eight);

    Node *two = create_tree_node(2);
    Node *one = create_tree_node(1);
    add_node_left(four, two);
    add_node_right(four, one);

    Node *five_sec = create_tree_node(5);
    add_node_right(three, five_sec);

    Node *six = create_tree_node(6);
    Node *seven = create_tree_node(7);
    add_node_left(five_sec, six);
    add_node_right(five_sec, seven);

    return five;
}

// Pre order traversal
void pre_order(Node *root)
{
    cout << root->root << " ";

    if(root->left_node != NULL)
        pre_order(root->left_node);

    if(root->right_node != NULL)
        pre_order(root->right_node);
}
