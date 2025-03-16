#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int>st;
    stack<int> temp;
    int x;
    cout<<"Push value in stack and press -1 for exit: ";
    while(true){
        cin>>x;
        if(x==-1)break;
        st.push(x);
    }
    int size = st.size();
    for(int i =0 ;i<(size)/2;i++){
        temp.push(st.top());
        st.pop();
    }
    cout<<st.top()<<" Deleted"<<endl;
    st.pop();
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}