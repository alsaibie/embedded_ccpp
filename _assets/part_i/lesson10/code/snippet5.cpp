#include <iostream>
using namespace std;

/* A function accepts a ptr, a ptr is just a variable */
void sum_array(uint8_t *arr, size_t arr_s, uint16_t *sum_ptr);

int main(int argc, char *argv[]){
    uint8_t sequence[4] = {2, 3, 4, 1};
    uint16_t sum = 0; 
    /* When passing an array, need to pass size of array */
    sum_array(sequence,sizeof(sequence), &sum);
    cout << sum << endl;
    return 0;
}

void sum_array(uint8_t *arr, size_t arr_s, uint16_t *sum_ptr){
    for (int k = 0; k < arr_s; k++){
        *sum_ptr += arr[k]; /* The original variable is manipulated */
    }
}
