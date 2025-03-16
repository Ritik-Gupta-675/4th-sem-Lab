#include <bits/stdc++.h>
using namespace std;
void find_bin(int n){
    if(n==0){
        return ;
    }
    find_bin(n/2);
    cout<<n % 2;
}
int main(){
    int n;
    cout<<"Enter any number: ";
    cin>>n;
    int p=n;
    string binary = "";
    if (n == 0) { 
        binary = "0"; 
    } else {
        while (n > 0) {
            binary = char('0' + (n % 2)) + binary;
            n /= 2;
        }
    }
    cout<<"Binary from loop: "<<binary<<endl;
    cout<<"Binary from Recurssion: ";
    find_bin(p);

}