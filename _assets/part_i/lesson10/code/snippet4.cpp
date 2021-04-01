#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    uint16_t sequence[5] = {2,4,6,8,16};

    cout << sequence[0] << endl; /* Output: 2 */
    cout << sequence    << endl; /* Output: a hex address */
    cout << *(sequence + 2) << endl; /*Output: 6, retrieving the 3rd array element */
    
    return 0;
}
