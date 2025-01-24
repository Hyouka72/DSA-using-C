#include <iostream>
using namespace std;

void TOH(int n, char source, char helper, char target);

int main() {
    int nodisk;
    cout << "Enter the number of disks: ";
    cin >> nodisk;

    char A = 'A', B = 'B', C = 'C';                                             // Representing the three rods
    cout << "The steps to solve the Tower of Hanoi are:\n";
    TOH(nodisk, A, B, C);
    cout << "The minimum number of steps are: " << (1 << nodisk) - 1 << endl; // by shifting 1 with n we get 2^n

    return 0;
}

void TOH(int n, char source, char helper, char target) {
    if (n == 1) {
        cout << "Move disk " << n << " from rod " << source << " to rod " << target << endl;        // to show the moves at the end of recursion
        return;
    }
    TOH(n - 1, source, target, helper);                                     // when reduced by 1 the target and helper get swapped
    cout << "Move disk " << n << " from rod " << source << " to rod " << target << endl; // to print the current value of the function
     TOH(n - 1, helper, source, target);                                    //when reduced by 1 the source and helper get swapped
}
 