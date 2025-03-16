#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next  = NULL;
    }
};
void insert(Node* &head,int data){
   Node* temp= new Node(data);
   if(head == NULL){
    head = temp;
    return;
   }
   Node* curr = head;
   while(curr->next!=NULL){
    curr = curr->next;
   }
   curr->next = temp;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void split(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow  = slow ->next;
        fast = fast ->next->next;
    }
    Node* head2 = slow->next;
    slow->next = NULL;
    cout<<"First split is: ";
    print(head);
    cout<<"Second split is: ";
    print(head2);
}
int main(){
    Node* head = new Node(10);
    insert(head,20);
    insert(head,30);
    insert(head,40);
    insert(head,50);
    insert(head,60);
    insert(head,70);
    cout<<"original Linked list: "<<endl;
    print(head);
    split(head);
}