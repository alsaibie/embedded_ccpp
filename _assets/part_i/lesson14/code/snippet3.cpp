#include <iostream>
using namespace std;

#ifndef FW_VER /* We can check if a macro is undefined */
    #define FW_VER 1 
#endif

/* Then we can define different functions / routines / objects etc. based on FW version*/
#if(FW_VER == 1)
    #define print_version() cout<<"Version 1" <<endl; 
#elif(FW_VER == 2)
    #define print_version() cout<<"Version 2" <<endl;
#endif

int main(int argc, char *argv[]){
    print_version(); /* Output: Version 1 */
    return 0;
}
