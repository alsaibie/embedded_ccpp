#include <cstdint>
#include <iostream>
using namespace std;

int add(int a, int b = 5); /* Function Declaration */

int main(void){
    int r1 = add(5,4); /* r1: 9 */
    int r2 = add(5); /* The second arg not given, the default value will be used, r2: 10 */

    cout << r1 << "\n";
    cout << r2 << "\n";
    
    return 0;
}

int add(int a, int b){ /* Function Definition */
    return a + b;
}



