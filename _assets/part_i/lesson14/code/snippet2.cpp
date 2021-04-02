#include <iostream>
using namespace std;

#define FW_VER 2 /* We define some macro here, such as Firmware version */

/* Then we can define different functions / routines / objects etc. based on FW version*/
#if(FW_VER == 1)
    #define print_version() cout<<"Version 1" <<endl; 
#elif(FW_VER == 2)
    #define print_version() cout<<"Version 2" <<endl;
#endif

int main(int argc, char *argv[]){
    print_version(); /* Output: Version 2 */
    return 0;
}
