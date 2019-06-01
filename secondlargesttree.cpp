// CPP program to find second largest node 
// in an n-ary tree. 
#include <bits/stdc++.h> 
using namespace std; 
  
// Structure of a node of an n-ary tree 
struct Node { 
    int key; 
    vector<Node*> child; 
}; 
  
// Utility function to create a new tree node 
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    return temp; 
} 
  
void secondLargestUtil(Node* root, Node** first, 
                       Node** second) 
{ 
    if (root == NULL) 
        return; 
  
    // If first is NULL, make root equal to first 
    if (!(*first)) 
        *first = root; 
  
    // if root is greater than first then second 
    // will become first and update first equal 
    // to root 
    else if (root->key > (*first)->key) { 
        *second = *first; 
        *first = root; 
    } 
  
    // If root is less than first but greater than 
    // second 
    else if (!(*second) || root->key > (*second)->key) 
        *second = root; 
  
    // number of children of root 
    int numChildren = root->child.size(); 
  
    // recursively calling for every child 
    for (int i = 0; i < numChildren; i++) 
        secondLargestUtil(root->child[i], first, second); 
} 
  
Node* secondLargest(Node* root) 
{ 
    // second will store the second highest value 
    Node* second = NULL; 
  
    // first will store the largest value in the tree 
    Node* first = NULL; 
  
    // calling the helper function 
    secondLargestUtil(root, &first, &second); 
  
    if (second == NULL) 
        return NULL; 
  
    // This handles the case when every element in tree are same. 
    if (first->key == second->key) 
        return NULL; 
  
    // return the second largest element 
    return second; 
} 
  
// Driver program 
int main() 
{ 
    /*   Let us create below tree 
   *             5 
   *         /   |  \ 
   *         1   2   3 
   *        /   / \   \ 
   *       15  4   5   6 
   */
  
    Node* root = newNode(5); 
    (root->child).push_back(newNode(1)); 
    (root->child).push_back(newNode(2)); 
    (root->child).push_back(newNode(3)); 
    (root->child[0]->child).push_back(newNode(15)); 
    (root->child[1]->child).push_back(newNode(4)); 
    (root->child[1]->child).push_back(newNode(5)); 
    (root->child[2]->child).push_back(newNode(6)); 
  
    if (secondLargest(root) != NULL) 
        cout << "Second largest element is : " << secondLargest(root)->key << endl; 
    else
        cout << "Second largest element not found\n"; 
  
    return 0; 
} 
