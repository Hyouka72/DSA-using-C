#include<iostream>
using namespace std;
int fib(int);
int main(){
    int n;
    cout<<"Enter the value for fibonnaci"<<endl<<"=>";
    cin>>n;
    cout<<"the factorial of "<<n<<" are"<<endl;
   for (int i = 0; i < n; i++)
   {
    cout<<fib(i)<<"\t";
   }
    return 0;
}
int fib(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
    return 1;
    }
    else{
        return (fib(n-1)+fib(n-2));
    }
}