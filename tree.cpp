#include<iostream>
using namespace std;

class TreeNode{
private:
    int data;
    TreeNode** children;
    int child_count;
public:
    TreeNode(int d){
        data=d;
        child_count=0;
        children=NULL;
    }
friend class GenericTree;
};

class GenericTree{
private:
    TreeNode *root;
public:
    GenericTree(){
        root=NULL;
    }

    TreeNode * FillPreOrder_rec(){
        cout<<"Please enter the data: ";
        int d; cin>>d;
        TreeNode* rt=new TreeNode(d);
        cout<<"Enter No of Children for node#"<<d<<" : ";
        int c; cin>>c;
        rt->child_count=c;
        rt->children=new TreeNode*[c];
        for (int i=0;i<c;i++){
            rt->children[i]=FillPreOrder_rec();
        }

        return rt;
    }

    void FillPreOrder(){
        root=FillPreOrder_rec();
        cout<<endl;
    }

    void PrintPreOrder(TreeNode* rt){
        if (rt==NULL) return;
        cout<<rt->data<<" ";
        for (int i=0;i<rt->child_count;i++){
            PrintPreOrder(rt->children[i]);
        }
    }
    void PrintPreOrder(){
        cout<<"PreOrder:";
        PrintPreOrder(root);
        cout<<endl;
    }

    void PrintPostOrder(){

    }
};

int main(){
    GenericTree gt;
    gt.FillPreOrder();
    gt.PrintPreOrder();
    gt.PrintPostOrder();
}
///PreOrder:
///1 3 2 2 5 2 9 0 10 0 6 0 3 0 4 2 7 2 11 0 12 0 8 0
