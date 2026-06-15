#include <iostream>
using namespace std;

class Node
{
   public:
   
   string Data;
   Node * LeftChild;
   Node * RightChild;
   
   Node(string data)
   {
       Data = data;
        LeftChild = nullptr;  
        RightChild = nullptr;
   }
   
   
};

class FamilyAnsectorTree
{
 
    public:
     Node * Root;
    FamilyAnsectorTree()
    {
        Root = nullptr;
    }
   
    void SetRoot(Node *r)
    {
        Root = r;
    }
   
    void PrintYoungest(Node * Root)
    {
        if(Root == nullptr)
        {
            return;
        }
       
        cout << " Youngest " << Root->Data << endl;
    }
   
    int HeightOfTree(Node * root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        else
        {
            int heightr = HeightOfTree(root->RightChild);
            int heightl = HeightOfTree(root->LeftChild);
            if(heightr > heightl)
            {
                return heightr+1;
            }
            else
            {
                return heightl + 1;
            }
        }
    }
   
    void LeafNodesPrint(Node * Root)
    {
        if(Root == nullptr)
        {
            return ;
        }
       
        if(Root->LeftChild == nullptr && Root->RightChild == nullptr)
        {
            cout << " Data "<< Root->Data << endl;
            return;
        }
        LeafNodesPrint(Root->LeftChild);
        LeafNodesPrint(Root->RightChild);
       
       
    }
   
    void PrintLevelOfEach(Node * Root,int level)
    {
        if(Root == nullptr)
        {
            return;
        }
        cout << Root->Data << " is at level " << level << endl;
        PrintLevelOfEach(Root->LeftChild, level + 1);
       PrintLevelOfEach(Root->RightChild, level + 1);
    }
   
};

int main()
{
    FamilyAnsectorTree family;

    Node * john = new Node("John");
    Node * mary = new Node("Mary");
    Node * david = new Node("David");
    Node * anna = new Node("Anna");
    Node * tom = new Node("Tom");
    Node * susan = new Node("Susan");
    Node * robert = new Node("Robert");

   
    john->LeftChild = mary;
    john->RightChild = david;

    mary->LeftChild = anna;
    mary->RightChild = tom;

    david->LeftChild = susan;
    david->RightChild = robert;

    family.SetRoot(john);
    family.PrintYoungest(family.Root);

    cout << " Leaf nodes ancestors with no known parents : " << endl;
    family.LeafNodesPrint(family.Root);

    cout << " Height of the tree: " << family.HeightOfTree(family.Root) << endl;

    cout << "Level of each member: " << endl;
    family.PrintLevelOfEach(family.Root, 0);

    return 0;
}
