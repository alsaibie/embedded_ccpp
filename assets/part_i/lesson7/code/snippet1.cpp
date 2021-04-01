#include <cstdint>
#include <iostream>
#include <bitset>

using namespace std; 

int main(int argc, char* argv[]) { 
    int b = 0b10001100; /* Store a binary value in b*/
    bitset<8> binary_var(b); /* Convert format for display only */
    int hex_var  = 0x8C; /* Store a hexadecimal value in hex_var */
    cout << "binary = " << binary_var << endl; 
    cout << "hex = " << hex << hex_var << endl; /* use std::hex to format into hex*/
    return 0; 
}
