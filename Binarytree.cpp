#include <iostream>
using namespace std;

class Node
{
    public:
        int info;
        Node *leftchild;
        Node *rightchild;

        //Constructor for the node class

    Node()
    {
        leftchild = nullptr; //initialize left child to null
        rightchild = nullptr; // initialize right child to null
    }
};

class Binarytree
{
    public:
        Node *ROOT;

    Binarytree()
    {
        ROOT = nullptr; //initializing ROOT to null
    }

    void insert()
    {
        int x;
        cout << "Masukkan nilai: ";
        cin >> x;

        // Step 1: Allocate memory for the new node
        Node *newNode = new Node();

        // Step 2: Assign value to the data field of new node
        newNode->info = x;

        // Step 3: Make the left and right child of the new node point to NULL
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        //Step 4: Locate the node which will be the parent of the node to be
        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode);

        // step 5: if parent is NULL (Tree is empty)
        if (parent == nullptr)
        {
            //5a : Mark the new node as ROOT
            ROOT = newNode;
            //5b : Exit
            return;
        }

        // step 6: if the value in the data field of new node is less than that of parent
        if (x < parent->info)
        {
            // 6a: Make the left child of parent point to thw new node
            parent->leftchild = newNode;
            // 6b : exit
            return;
        }
        // step 7: if the value in the data filed of the new node is greater than that of the parent
        else if (x > parent->info)
        {
            // 7a : make the right child of parentt point to the new node
            parent->rightchild = newNode;
            // 7b: exit
            return;
        }
    }


void search(int element, Node *&parent, Node *&currentNode)
{
    currentNode = ROOT;
    parent = nullptr;
    while ((currentNode != nullptr) && (currentNode->info !=element))
    {
        parent = currentNode;
        if (element < currentNode->info)
            currentNode = currentNode->leftchild;
        else
            currentNode = currentNode->rightchild;
    }
}

void inorder(Node *ptr)
{
    if (isEmpty())
    {
        cout << "tree is empty" << endl;
        return;
    }
    if (ptr == nullptr)
        return;

    inorder(ptr->leftchild);
    cout << ptr->info << " "; //parent
    inorder(ptr->rightchild);
}
void preorder(Node *ptr)
{
    if (isEmpty())
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr == nullptr)
    return;

    cout << ptr->info << " ";
    preorder(ptr->leftchild);
    preorder(ptr->rightchild);
}

void postorder(Node *ptr)
{
    if (isEmpty())
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr == nullptr)
        return;

    postorder(ptr->leftchild);
    postorder(ptr->rightchild);
    cout << ptr->info << " ";
}

bool isEmpty()
{
    //Checks if the tree is empty
    return ROOT == nullptr;
}
};

int main()
{
    Binarytree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            x.insert();
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {

            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {

            x.postorder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
}