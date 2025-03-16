#include <iostream>
using namespace std;
string  complement(string bin){
    for(char &i :bin){
        i=i==0?1:0;} }
int main() {
    int  data[] = {
        11,15,13,12
    };
int sum =0;
    for(int i=0;i<4;i++){
        sum = sum + data[i];}
    int bin_sum;
    while(sum!=0){
        int dig =  sum%2;
        bin_sum = dig + bin_sum*2;
        sum = sum/2;}
    string temp = to_string(bin_sum);
    cout<<temp;

    return 0;
}
