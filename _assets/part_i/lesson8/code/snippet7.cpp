#include <cstdint>
#include <iostream>

using namespace std; 
int main(int argc, char* argv[]) { 

    int k = 0;
    /* (Condition) */
    do {
        cout << k << endl; /* Output: 0 */
        k++;
    } while(k = 0);
    
    return 0; 
}
