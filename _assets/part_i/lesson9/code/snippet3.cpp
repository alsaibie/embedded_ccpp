#include <cstdint>
#include <iostream>
using namespace std; 

int add_2(int a){ /* The variable VALUE will be passed to the function */
    a += 2;
    return a;
} 
int add_3(int &a){ /* the variable LOCATION REFERENCE will be passed to the function */
    a += 3;
    return a;
} 

int main(void){
    int b = 3;
    int r1 = add_3(b); /* r1: 6, b = 6 */
    int r2 = add_2(b); /* r2: 8, since b was manipulated (passed by reference) */ 

    cout << r1 << "\n";
    cout << r2 << "\n";

    return 0;
}
