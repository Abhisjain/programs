#include<iostream>
using namespace std;

class Node{
private:
    int data;
    Node* next;
public:
    Node(int d){
        data=d;
        next=NULL;
    }
friend class LinkedList;
};

class LinkedList{
private:
    Node *head;
public:
    LinkedList(){
        head=NULL;
    }
    void InsertAtBegin(int d){
        Node* nn=new Node(d);
        nn->next=head;
        head=nn;
    }
    void InsertAtLast(int d){
        if (head==NULL) {
            InsertAtBegin(d);
            return;
        }
        Node *t=head;
        while (t->next!=NULL){
            t=t->next;
        }
        Node * nn=new Node(d);
        t->next=nn;
    }
    void InsertAtK(int d, int k){
        if (head==NULL || k==1) {
            InsertAtBegin(d);
            return;
        }
        Node*t=head; int i=1;
        while (i<k-1&&t->next!=NULL){
            i++; t=t->next;
        }
        Node* nn=new Node(d);
        nn->next=t->next;
        t->next=nn;
    }
    void Print(){
        Node*t=head;
        while (t!=NULL){
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
    void DeleteAtBegin(){
        if (head==NULL) return;
        Node* t=head;
        head=head->next;
        delete t;
    }
    void DeleteAtLast(){
        if (head==NULL) return;
        if (head->next==NULL) {DeleteAtBegin(); return;}
        Node* t=head;
        while (t->next->next!=NULL){
            t=t->next;
        }
        delete t->next;
        t->next=NULL;
    }
    void DeleteAtK(int k){
        if(head==NULL) return;
        if (k==1) {DeleteAtBegin()
            ; return;}
        int i=1; Node* t=head;
        while (i<k-1 && t->next!=NULL){
            t=t->next;i++;
        }
        if (i==k-1){
            Node* del=t->next;
            t->next=del->next;
            delete del;
        }
    }
private:
    bool Search (Node* hd, int d){
        ///this should be a private function
        if (hd==NULL) return false;
        if (hd->data==d) return true;
        return Search(hd->next,d);
    }
public:
    bool Search(int d){
        ///this should be a public function
        return Search(head,d);
    }

    bool IsSorted(Node* hd){
        if (hd==NULL || hd->next==NULL) return true;
        if (hd->data>hd->next->data) return false;
        return IsSorted(hd->next);
    }

    bool IsSorted(){
        return IsSorted(head);
    }
};

int main(){
    LinkedList ll;
    ll.InsertAtBegin(21);
    ll.InsertAtBegin(2);
    ll.InsertAtBegin(13);
    ll.InsertAtBegin(4);
    ll.InsertAtLast(25);
    ll.InsertAtK(6,2);
    ll.InsertAtK(7,10);
    ll.Print();
    ll.DeleteAtBegin();
    ll.DeleteAtLast();
    ll.DeleteAtK(10);
    ll.DeleteAtK(3);
    ll.Print();
    cout<<"Search:"<<ll.Search(15)<<endl;
    cout<<"IsSorted:"<<ll.IsSorted()<<endl;
}

