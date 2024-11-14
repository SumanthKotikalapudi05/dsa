#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    node* prev;
    int data;
    node* next;
        public:
        Node(Node*prev1,int data1,Node*next1){
            prev=prev1;
            data=data1;
            next=next1;
        }
        public:
        Node(int data1,Node*next1){
            prev=nullptr;
            data=data1;
            next=next1;
        }
        public:
        Node(int data1){
            prev=nullptr;
            data=data1;
            next=nullptr;
        }
};
/*converting array to dll*/
int convertArr2DLL(vector<int> &arr){
    Node*head=new Node(arr[0]);
    Node*p=head;
    for(int i=1;i<arr.size();i++){
        Node*temp=new Node(p,arr[i],nullptr);
        p->next=temp;
        p=temp;
    }
    return head;
}
void print(Node*head){
    while (head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    vector<int> arr ={12,5,6,8,7};
    node*head=convertArr2DLL(arr);
    print(head);
    return 0;
}