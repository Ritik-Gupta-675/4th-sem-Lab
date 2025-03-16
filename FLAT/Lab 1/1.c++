#include <bits/stdc++.h>
using namespace std;

bool validId(string s){
    if((s[0]<'a' || s[0]>'z') && s[0]!='_'){
        return false;
    }
    for(int i=1; i<s.length()-1 ; i++){
        if(isspace(s[i])){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cout<<"enter string"<<endl;
    cin>>s;

    if(validId(s))
    cout<<"Valid";
    else
    cout<<"Not Valid";
}