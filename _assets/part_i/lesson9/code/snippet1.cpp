#include <iostream>
using namespace std;

int add(int a, int b); /* Function Declaration */
int multiply(int a, int b){ /* Function Declaration and Definition */
    return a * b;
}

int main(void){
    int r1 = add(5,4);
    int r2 = multiply(3,3);

    cout << r1 << "\n";
    cout << r2 << "\n";
    return 0;
}

int add(int a, int b){ /* Function Definition */
    return a + b;
}
