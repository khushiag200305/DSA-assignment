#include <iostream>
using namespace std;

class DLLNode {
public:
    int data;
    DLLNode* next;
    DLLNode* prev;
    DLLNode(int v){ data=v; next=prev=NULL; }
};

class CLLNode {
public:
    int data;
    CLLNode* next;
    CLLNode(int v){ data=v; next=NULL; }
};

// DLL CLASS
class DLL {
public:
    DLLNode* head=NULL;

    void insert(int v){
        DLLNode* n=new DLLNode(v);
        if(!head){ head=n; return; }
        DLLNode* t=head;
        while(t->next) t=t->next;
        t->next=n; n->prev=t;
    }

    int size(){
        int cnt=0;
        DLLNode* t=head;
        while(t){ cnt++; t=t->next; }
        return cnt;
    }
};

// CLL CLASS
class CLL {
public:
    CLLNode* head=NULL;

    void insert(int v){
        CLLNode* n=new CLLNode(v);
        if(!head){ head=n; n->next=n; return; }
        CLLNode* t=head;
        while(t->next!=head) t=t->next;
        t->next=n;
        n->next=head;
    }

    int size(){
        if(!head) return 0;
        int cnt=0;
        CLLNode* t=head;
        do{
            cnt++;
            t=t->next;
        } while(t!=head);
        return cnt;
    }
};

int main(){
    DLL d;
    d.insert(1); d.insert(2); d.insert(3);
    cout<<"DLL Size = "<<d.size()<<endl;

    CLL c;
    c.insert(10); c.insert(20); c.insert(30);
    cout<<"CLL Size = "<<c.size()<<endl;
}
