#include <cstdint>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int k = 3;
    switch (k)
    {
    case 2:
        cout << "case 2" << endl;
    case 3:
        cout << "case 3" << endl;
    case 4:
        cout << "case 4" << endl;
    }
    /* Output : case 3, case 4
     * if no break statement is provided, all proceeding instructions will be executed 
     */  
    return 0;
}


