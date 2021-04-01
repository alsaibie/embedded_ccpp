struct test_scores_t{
    int midterm_1;
    int midterm_2;
    int final_exam;
};

struct person_t{
    /* a struct can accept a mixture of unordered types */
    char name[10];
    int class_year;
    char gender;
    test_scores_t test_scores; /* a struct can be nested within a struct */
};

int main(void){
    person_t Ahmed;
    return 0;
}
