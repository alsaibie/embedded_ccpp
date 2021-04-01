#include <cstdint>
#include <iostream>

using namespace std; 
int main(int argc, char* argv[]) { 

    int k = 0;
    /* (Condition) */
    while(true) {
        cout << k << endl; /* Output: 0, 1, 2, 3, 4, 5 */
        k++;
        if (k == 6) break; /* This will break the program from the loop */
    }
    return 0; 
}
