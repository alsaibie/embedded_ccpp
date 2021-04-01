#include <cstdint>
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    int k = 3;
    switch (k)
    {
    case 2:
        cout << "case 2" << endl; break;
    case 3:
        cout << "case 3" << endl; break;
    case 4:
        cout << "case 4" << endl; break;
    }
    /* Output : case 3 */
    return 0;
}
