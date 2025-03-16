#include <bits/stdc++.h>
using namespace std;

    int sumDigit(int n){
        if(n==0)return 0;

        return n%10 + sumDigit(n/10);
    }
    int findRoot(int n){
        if(n<10)return n;
        return findRoot(sumDigit(n));
    }

int main(){
    int n;
    cout<<"Enter the number for digital root: ";
    cin>>n;
    int ans = findRoot(n);
    cout<<"Digital Root is: "<<ans;
}