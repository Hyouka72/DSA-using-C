#include<iostream> //stick 3 but disk has size  as  demanded
using namespace std;
int TOH(int, int, int, int);
int main(){
    int nodisk;
    cout<<"Enter the number of disk"<<endl<<"\n=>";
    cin>>nodisk;
    //A=1;
    //B=2;
    //C=3;
    //D=4;
    int A=1,B=2,C=3;
    cout<<"The minumum steps are"<<TOH(nodisk,A,B,C);

    return 0;
}

int TOH(int n, int a, int b, int c){
    int i;
    while (n>1)
    {
            TOH(n-1,a,c,b);
            TOH(n-1,b,a,c);
        i++;
    }
    return i;
}
// set no of disk
// set there value;
// no need ot set stick stick will be always 3
