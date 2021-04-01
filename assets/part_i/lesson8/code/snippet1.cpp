#include <cstdint>
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    int k = 3;
    if (k == 1)
    {      cout << k << endl;  }
    else if (k == 2)
    {     cout << k << endl;   }
    else /* This condition is valid */
    {    cout << k << endl; /* Output: 3*/ }
    return 0;
}
