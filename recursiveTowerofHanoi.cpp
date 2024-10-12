/* Towers of Hanoi - Recursion

@AJ Enrique Arguello (10/1/24)

* Objective: Use recursion to solve the Tower of Hanoi problem for n= 4 bits.
*/

#include <iostream>
#include <stack>

using namespace std;

void Board(); // prototype for board function 
void recursivetowerOfHanoi(int n, stack<char> &T1, stack<char> &T2, stack<char> &T3, char t1Name, char t2Name, char t3Name); // recursive function prototype
stack<char> T1; // tower 1 stack
stack<char> T2; // tower 2 stack
stack<char> T3; // tower 3 stack

int main() {
    char a = 'A', b = 'B', c = 'C', d = 'D'; // characters a, b, c, d
    int n = 4; // number of disks (4 in this case)

    T1.push(a);  
    T1.push(b);
    T1.push(c);
    T1.push(d);  

    Board();
    
    recursivetowerOfHanoi(n, T1, T2, T3, '1', '2', '3'); // call tower of hanoi function to solve puzzle using recursion 

    cout << "\nCongrats! You completed the puzzle!\n";

    return 0;
}

// function to display the contents of the stack from bottom to top
void displayStack(stack<char> s) {
    stack<char> tempStack;
    // transfers elements to temporary stack to reverse the order
    while (!s.empty()) {
        tempStack.push(s.top());
        s.pop();
    }
    // prints from the temporary stack
    while (!tempStack.empty()) {
        cout << "\t" << tempStack.top();
        tempStack.pop();
    }
}

// function to display the current board state
void Board() {
    cout << "\nT1 ";  // displays all the tiles on Tower 1
    displayStack(T1);
    cout << "\n\nT2 ";  // displays all the tiles on Tower 2
    displayStack(T2);
    cout << "\n\nT3 ";  // displays all the tiles on Tower 3
    displayStack(T3);
    cout << "\n\n";
}

// solves tower of hanoi puzzle recursively
void recursivetowerOfHanoi(int n, stack<char> &T1, stack<char> &T2, stack<char> &T3, char t1Name, char t2Name, char t3Name) {
    // if there's only one tile move it from source to destination
    if (n == 1) {
        cout << "Move tile " << T1.top() << " from Tower " << t1Name << " to Tower " << t3Name << endl;
        T3.push(T1.top());
        T1.pop();
        Board();  // Display the current board state after each move
        return;
    }

    // move the top n-1 tiles from tower 1 to tower 2 using tower 3 as a holding spot
    recursivetowerOfHanoi(n - 1, T1, T3, T2, t1Name, t3Name, t2Name);

    // move the largest tile from tower 1 to tower 3
    cout << "Move disk " << T1.top() << " from Tower " << t1Name << " to Tower " << t3Name << endl;
    T3.push(T1.top());
    T1.pop();
    Board();  // display the current board state after each move

    // move the n-1 disks from tower 2 to tower 3 using tower 1 as a holding spot
    recursivetowerOfHanoi(n - 1, T2, T1, T3, t2Name, t1Name, t3Name);
}

