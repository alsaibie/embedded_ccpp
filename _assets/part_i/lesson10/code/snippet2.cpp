#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    int x = 1; int y = 2; int *ptr;

    ptr = &x; /* Grabs the address of the variable x */
    cout << ptr << endl;/* Output: address of x */

    y = *ptr; /* Grabs the value in the address pointed to by ptr = value in x */
    cout << y << endl;  /* Output: 1 */

    x = (int)ptr; /* Grabs address pointed to by ptr and stores it in x */
    cout << hex << x << endl; /* Output: address of x as well */

    *ptr = 4; /* Changes the value stored in the location pointed to by ptr, changes the value of x */
    cout << x << endl; /*Output: 4 */
    return 0;
}
