#include<iostream>
using namespace std;
int main(){
    int *b;
    b = new int[2];
    int a[5] = {1,2,3,4,5};
    b[0] = 1;
    b[1] = 2;
    b[2] = 3;
    cout<<a[1]<<endl;
    cout<<a[4]<<endl;
    cout<<a<<endl;
    cout<<b[1]<<endl;
    cout<<b[2]<<endl;
    cout<<b;



}