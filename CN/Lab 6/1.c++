#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int>complement(vector<int>num){
    for(int i=0;i<num.size();i++){
        num[i]=num[i]==0?1:0;
    }
    return num;
}
vector<int>sumF(vector<int>f1,vector<int>f2){
    int n=f1.size();
    int carry=0;
    vector<int>sumX(n,0);

    for(int i=n-1;i>=0;i--){
        sumX[i]=f1[i]+f2[i]+carry;
        if(sumX[i]>1){
            sumX[i]=0;
            carry=1;
        }else{
            carry=0;
        }
    }

    for(int i=n-1;i>=0;i--){
        sumX[i]=sumX[i]+carry;
        if(sumX[i]>1){
            sumX[i]=0;
            carry=1;
        }else{
            carry=0;
        }
    } 

    return sumX;

}
vector<int>toVector(string str){
    vector<int>vec;

    for(int i=0;i<str.size();i++){
        vec.push_back(int(str[i]-'0'));
    }
    return vec;
}
vector<int> getCheckSum(vector<string>data){
    int n=data.size();
    vector<int>f;
    vector<int>sumX=toVector(data[0]);

    for(int i=1;i<n;i++){
        f=toVector(data[i]);
        sumX=sumF(sumX,f);
    }
    sumX=complement(sumX);
    return sumX;
}
int main(){
    int n;
    vector<string>data;

    cout<<"Enter number of frames :";
    cin>>n;

    while(n>0){
        cout<<"Enter Frame :";
        string f;
        getline(cin,f,',');
        data.push_back(f);
        n--;
    }
    vector<int>checkSum=getCheckSum(data);
    cout<<"CheckSum :";
    for(int i=0;i<checkSum.size();i++){
        cout<<checkSum[i];
    }
    cout<<endl;
    return 0;
}