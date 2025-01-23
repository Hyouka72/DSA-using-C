#include<iostream>
using namespace std;
int fact(int);
int main(){
    int n;
    cout<<"Enter the value for factorial"<<endl<<"=>";
    cin>>n;
    cout<<"the factorial of "<<n<<" is "<<fact(n);
    return 0;
}

int fact(int n){
    if(n==0||n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}