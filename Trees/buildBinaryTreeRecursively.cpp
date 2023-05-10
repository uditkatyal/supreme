#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// postOrder

void postOrder(TreeNode *root)
{
    if (root == NULL)
        return;

    // LRN -> leftNode | rightNode | currNode
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// preOrder
void preOrder(TreeNode *root)
{
    if (root == NULL)
        return;

    // NLR -> currNode | leftNode | rightNode

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Inorder
void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    // LNR -> left Node | currNode | rightNode
    inorderTraversal(root->left);

    // print root node
    cout << root->data << " ";

    inorderTraversal(root->right);
}

// printing tree level wise using separator
void levelWisePrintSeparator(TreeNode *root)
{

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}

// printing tree level wise using queue
void levelWisePrint(TreeNode *root)
{

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();
        cout << front->data << " ";

        if (front->left)
        {
            q.push(front->left);
        }
        if (front->right)
        {
            q.push(front->right);
        }
    }
}
// building tree recursively
TreeNode *buildTree()
{

    int data;
    cout << "Enter the data : " << endl;
    cin >> data;

    if (data == -1)
        return NULL;

    TreeNode *root = new TreeNode(data);

    cout << "Enter the left node of " << data << " node " << endl;
    root->left = buildTree();

    cout << "Enter the right node of " << data << " node " << endl;
    root->right = buildTree();
}

int main()
{
    TreeNode *root = NULL;
    root = buildTree();

    levelWisePrint(root);
    cout << endl;
    levelWisePrintSeparator(root);
    return 0;
}