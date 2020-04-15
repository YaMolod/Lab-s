// Муллов Игорь, 19 Бинарные деревья

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>
using namespace std;
int tabs = 0;

struct Tree
{
    char data;
    Tree* left;
    Tree* right;
};

void print_tree(Tree*& root)
{
    
    if (root == NULL)
    {
        return;
    }
    else
    {        
        tabs++;
        print_tree(root->left); 

        for (int i = 0; i < tabs; i++)
        {
            cout << " ";
        } 
        cout << root->data << endl; 
        
        print_tree(root->right);
        
        tabs--;              
    }    
}

void create_tree(Tree*& root)
{
   
        if (root==NULL)
        {
            root = new Tree;
            root->data =(char)rand() % 10;
            root->left = NULL;
            root->right = NULL;
            return;
        }
        else
        {          
                create_tree(root->left);
                create_tree(root->right);                                 
        }
    
}

int tree_height(const Tree* p)
{
    int l, r, h = 0;
    if (p != NULL)
    {
        l = tree_height(p->left);
        r = tree_height(p->right);
        h = ((l > r) ? l : r) + 1;
    }
    return h;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    Tree* root = NULL;
    int n = rand() % 10;

        for (int i = 0; i < n; i++)
        {
            create_tree(root);
        }
     
    print_tree(root);
    cout<<"Высота дерева - "<<tree_height(root);
}

