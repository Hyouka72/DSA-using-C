#include<iostream>
#include<string>
using namespace std;
int main(){
    char *stack;
    string a;
    int k=0;
    cout<<"Write the expression"<<endl<<"=>";
    cin>>a;
    int length = a.length(); 
    stack = new char[length];
    
    for(int i = 0; i<length ;i++){
        cout<<a[i]<<endl;
        if(a[i]=='+' || a[i]=='-'){
            stack[k]=a[i];
            k++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout<<"new"<<endl;
        cout<<stack[i]<<endl;
    }
    
    return 0;

}