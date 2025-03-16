#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s){
    for(int i =0 ; i<s.length()/2 ; i++){
        if(s[i]!=s[s.length()-1-i]){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cout<<"enter string"<<endl;
    cin>>s;

    if(palindrome(s))
    cout<<"Palindrome";
    else
    cout<<"Not palindrome";
}