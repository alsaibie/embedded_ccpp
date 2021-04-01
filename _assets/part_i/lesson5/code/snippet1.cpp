#include <cstdint>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) { 
    uint16_t A[5] = {1,2,3,4,5}; /* A five element array */
    uint16_t B[3][2] = {{1,10},{300,230},{100,120}}; /* A 3x2 element array */
    float    C[2] = {0.0}; /* Assigns 0.0 to both array elements */
    int16_t  D[3] = {-1, 2}; /* Third element assigned 0 */
    
    cout << A[2] << endl; /* Output: 3, index starts at 0 */
    cout << B[2][0] << endl; /* Output: 100 */
    cout << C[1] << endl; /* Output: 0.0 */
    cout << D[2] << endl; /* Output: 0 */
    return 0;
}
