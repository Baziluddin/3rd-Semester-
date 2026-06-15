#include <iostream>
using namespace std;

class Node
{
   public:
   
   string Data;
   int PlayCounts;
   Node * LeftChild;
   Node * RightChild;
   
   Node(string data, int count)
  {
    Data = data;
    PlayCounts = count;
    LeftChild = nullptr;
    RightChild = nullptr;
   }
   
   
};

class MusicBst
{
 
    public:
    Node * Root;
   
    MusicBst()
    {
        Root = nullptr;
    }
   
    Node * InsertNode(Node * root,Node * newnode)
    {
        if(root == nullptr)
        {
             root = newnode;
             return root;
        }
       
        if(newnode->PlayCounts < root->PlayCounts)
        {
            root->LeftChild = InsertNode(root->LeftChild,newnode);
        }
       
        else if (newnode->PlayCounts > root->PlayCounts)
        {
            root->RightChild = InsertNode(root->RightChild,newnode);
        }
       
        return root;
    }
   
    Node * SearchSong(int count,Node * Root)
    {
        if(Root == nullptr)
        {
            return nullptr;
        }
       
        if(Root->PlayCounts == count)
        {
            cout << " song : "<< Root->Data << " Total Times Played " << count << endl;
            return Root;
        }
       
        else if(Root->PlayCounts > count  )
        {
            
            return SearchSong(count,Root->LeftChild);
        }
       
        else
        {
            return SearchSong(count,
            Root->RightChild);
        }
    }
   
    void InOrder(Node * Root)
    {
        if(Root == nullptr)
        {
            return ;
        }
       
        InOrder(Root->LeftChild);
        cout << " " << Root->Data << " "<< "("<<Root->PlayCounts << ") ";
        InOrder(Root->RightChild);
    }
   
    void PostReverseInOrder(Node * Root)
    {
        if(Root == nullptr)
        {
            return ;
        }
       
        
        PostReverseInOrder(Root->RightChild);
        PostReverseInOrder(Root->LeftChild);
        cout << " " << Root->Data << " "<< "("<<Root->PlayCounts << ") ";
       
    }
    
    Node * min(Node * root)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        else if(root->LeftChild != nullptr)
        {
            return min(root->LeftChild);
        }
        else
        {
            return root;
        }
    }
    
    Node * DeleteSong(Node * root,int count)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        
        if(count < root->PlayCounts)
        {
            root->LeftChild = DeleteSong(root->LeftChild,count);
        }
        else if(root->PlayCounts < count)
        {
            root->RightChild = DeleteSong(root->RightChild,count);
        }
        
        else
        {
            if(root->LeftChild == nullptr && root->RightChild == nullptr)
            {
                delete root;
                return nullptr;
             
            }
            
            else if(root->RightChild == nullptr)
            {
                Node * temp = root->LeftChild;
                delete root;
                return temp;
                
            }
            
            else if(root->LeftChild == nullptr)
            {
                Node * temp = root->RightChild;
                delete root;
                return temp;
                
            }
            else
            {
                Node * bode = min(root->RightChild);
                root->Data = bode->Data;
                root->PlayCounts = bode->PlayCounts;
                root->RightChild = DeleteSong(root->RightChild,bode->PlayCounts);
                
            }
            
            
        }
        return root;
        
    }
    
    
};

int main()  
{  
    MusicBst bst;  

    bst.Root = bst.InsertNode(bst.Root, new Node("SongA", 50));  
    bst.Root = bst.InsertNode(bst.Root, new Node("SongB", 20));  
    bst.Root = bst.InsertNode(bst.Root, new Node("SongC", 70));  
    
    bst.SearchSong(50, bst.Root);

    cout << "Inorder: ";  
    bst.InOrder(bst.Root);  
    cout << endl;  

    cout << "Postorder: ";  
    bst.PostReverseInOrder(bst.Root);  
    cout << endl;  

    bst.Root = bst.DeleteSong(bst.Root, 20);  
    cout << "After delete: ";  
    bst.InOrder(bst.Root);  
    cout << endl;  

    return 0;  
}
