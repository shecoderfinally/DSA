/*Algorithm Postorder(tree)
1.Traverse the left subtree, i.e., call Postorder(left->subtree)
2.Traverse the right subtree, i.e., call Postorder(right->subtree)
3.Visit the root */
#include <iostream>

using namespace std;

typedef struct node Tree_Node;
struct node
{
    int root;
    Tree_Node *left_node;
    Tree_Node *right_node;
};

void post_order_traversal(Tree_Node *root);
Tree_Node *create_tree_node(int item);
void add_left_node(Tree_Node *root, Tree_Node *child);
void add_right_node(Tree_Node *root, Tree_Node *child);
Tree_Node *create_tree();

int main(void)
{
    Tree_Node *root;

    root = create_tree();
    cout << "Root Tree dataa: " << root->root << endl;

    post_order_traversal(root);

    return 0;
}

// post order traversal
void post_order_traversal(Tree_Node *root)
{
    if(root->left_node != NULL)
        post_order_traversal(root->left_node);

    if(root->right_node != NULL)
        post_order_traversal(root->right_node);

    cout << root->root << " ";
}

// Create Tree node
Tree_Node *create_tree_node(int item)
{
    Tree_Node *new_node = new Tree_Node;

    if(new_node == NULL)
    {
        cout << "Error! Could not create a new node.\n";
        exit(1);
    }

    new_node->root = item;
    new_node->left_node = NULL;
    new_node->right_node = NULL;

    return new_node;
    delete new_node;
}

// add left node
void add_left_node(Tree_Node *root, Tree_Node *child)
{
    root->left_node = child;
}

// add right node
void add_right_node(Tree_Node *root, Tree_Node *child)
{
    root->right_node = child;
}

// Create Tree;
Tree_Node *create_tree()
{
    Tree_Node *five = create_tree_node(5);
    Tree_Node *nine = create_tree_node(9);
    Tree_Node *three = create_tree_node(3);
    add_left_node(five, nine);
    add_right_node(five, three);

    Tree_Node *four = create_tree_node(4);
    Tree_Node *eight = create_tree_node(8);
    add_left_node(nine, four);
    add_right_node(nine, eight);

    Tree_Node *two = create_tree_node(2);
    Tree_Node *one = create_tree_node(1);
    add_left_node(four, two);
    add_right_node(four, one);

    Tree_Node *five_sec = create_tree_node(5);
    add_right_node(three, five_sec);

    Tree_Node *six = create_tree_node(6);
    Tree_Node *seven = create_tree_node(7);
    add_left_node(five_sec, six);
    add_right_node(five_sec, seven);

    return five;
}

