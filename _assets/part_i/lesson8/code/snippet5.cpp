#include <cstdint>
#include <iostream>

using namespace std; 
int main(int argc, char* argv[]) { 

    int k = 0;
    /* (Condition) */
    while(++k < 5) {
        cout << k << endl; /* Output: 1, 2, 3, 4 */
    }
    return 0; 
}

