#include <cstdint>
#include <iostream>
using namespace std; 

void add(int &r, int a, int b = 5); /* Function Declaration */

int main(void){
    int r1;
    add(r1, 5, 4); /* r1 will be passed by reference, r1: 9 */ 

    cout << r1  << "\n";

    return 0;
}

void add(int &r, int a, int b){ /* Function Definition */
    /* the function doesn't return any argument,
     * instead changing r changes the r1 inside main()
     */
    r = a + b;
}
