#include<iostream>
#include<conio.h>
#include<vector>

using namespace std;

void stackoperand(char c , vector<string> &opera){
    for(const string& op : opera){
        cout<<op <<" ";
    }
    cout<<endl;
}

int main(){

    string scan;
    vector<string> operand;
    vector<string> operation;
    
    cout<<"enter the expretion"<<endl;
    cin>>scan;

    for(char c : scan){
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' ){
            operation.push_back(string(1, c));      //type conversion form charcter to string
            stackoperand(c,operation);
        }
    }

}