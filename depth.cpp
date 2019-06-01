#include<iostream>
#include<queue>
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
    void PrintPostOrder(TreeNode* rt){
        if (rt==NULL) return;
        for (int i=0;i<rt->child_count;i++){
            PrintPostOrder(rt->children[i]);
            if(rt->child_count==0)
            {
			cout<<rt->data;
            cout<<endl<<"leave node";
        }
        cout<<rt->data<<" ";
    }
}
    void PrintPostOrder(){
        cout<<"PostOrder:";
        PrintPostOrder(root);
        cout<<endl;

    }

    void FillLevelOrder(){
        cout<<"Enter data for root:";
        int d; cin>>d;
        root=new TreeNode(d);
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            cout<<"Enter no of children for Node#"<<f->data<<":";
            int c;cin>>c;
            f->child_count=c;
            f->children=new TreeNode* [c];
            for (int i=0;i<c;i++){
                cout<<"Enter data for child#"<<i<<" of node#"<<f->data<<":";
                cin>>d;
                f->children[i]=new TreeNode(d);
                q.push(f->children[i]);
            }
        }
        cout<<endl;
    }
    void PrintLevelOrder(){
        cout<<"Level Order:";
        if (root==NULL) return;
        queue<TreeNode*> q;
        q.push(root);q.push(NULL);
        while (!q.empty()){
            TreeNode*f=q.front();
            q.pop();
            if (f==NULL){
                cout<<endl;
                if (!q.empty()) q.push(NULL);
            } else {
                cout<<f->data<<" ";
                for (int i=0;i<f->child_count;i++){
                    q.push(f->children[i]);
                }
            }
        }
        cout<<endl;
    }
    void PrintMaxNode_BF(TreeNode* rt, int &max){
        if (rt==NULL) return;
        if (rt->data>max) max=rt->data;
        for (int i=0;i<rt->child_count;i++){
            PrintMaxNode_BF(rt->children[i],max);
        }

    }

    int PrintMaxNode_BF(TreeNode* rt){
        static int max=INT_MIN;
        ///using static memory
        if (rt==NULL) return -1;
        if (rt->data>max) max=rt->data;
        for (int i=0;i<rt->child_count;i++){
            PrintMaxNode_BF(rt->children[i]);
        }
        return max;
    }

    int PrintMaxNode_Greedy (TreeNode* rt){
        if (rt==NULL) return INT_MIN;
        int max=rt->data;
        for(int i=0;i<rt->child_count;i++){
            int ans=PrintMaxNode_Greedy(rt->children[i]);
            if (ans>max) max=ans;
        }
        return max;
    }

    void PrintMaxNode(){
        cout<<"Max Node:";
        int max=INT_MIN;
        PrintMaxNode_BF(root,max);
        cout<<max<<endl;
        cout<<PrintMaxNode_BF(root)<<endl;
        cout<<PrintMaxNode_Greedy(root)<<endl;
    }
};



  int main(){
    GenericTree gt;
    ///gt.FillPreOrder();
    gt.FillLevelOrder();
    gt.PrintPreOrder();
    gt.PrintPostOrder();
    gt.PrintLevelOrder();
    gt.PrintMaxNode();
}
///PreOrder:
///1 3 2 2 5 2 9 0 10 0 6 0 3 0 4 2 7 2 11 0 12 0 8 0
///LO
///1 3 2 3 4 2 5 6 0 2 7 8 2 9 10 0 2 11 12 0 0 0 0 0

