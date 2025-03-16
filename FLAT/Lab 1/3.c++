#include <bits/stdc++.h>
using namespace std;

bool rotated(string s , string t){
    if(s.length() != t.length()){return false;}
    int s_index;
    int t_index;
    for(auto i : s){
        for(auto j: t){
            if(i==s){
                
            }
        }
    }
    
}

int main(){
    string s,t;
    cout<<"enter string"<<endl;
    cin>>s;
    cout<<"enter second string"<<endl;
    cin>>t;

    if(rotated(s,t))
    cout<<"Yes";
    else
    cout<<"No";
}