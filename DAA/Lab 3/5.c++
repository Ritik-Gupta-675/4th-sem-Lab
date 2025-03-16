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
Node* remove_zero(Node* head){
    int sum = 0;
    Node* ans = head;
    while(head!=NULL){
        sum = sum + head->data;
        if(sum == 0){
            ans = head->next;
        }
        head = head->next;
    }
    return ans;
}
int main(){
    Node* head = new Node(10);
    insert(head,20);
    insert(head,-30);
    insert(head,40);
    insert(head,70);
    cout<<"original array: ";
    print(head);
    Node* ans = remove_zero(head);
    cout<<"After removing zero sum: ";
    print(ans);
}