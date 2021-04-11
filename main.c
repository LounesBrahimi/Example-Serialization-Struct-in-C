#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* STRUCT_FORMAT_OUT = "(%s, %d, %c)\n";
const char* STRUCT_FORMAT_IN = "(%[^,], %d, %c)\n";

typedef struct person{
    char name[15];
    int age;
    char gender;
} person;

int main()
{
    person p = {
        .name = "Lounes",
        .age = 24,
        .gender = 'M'
    };

    FILE* flux;
    fopen_s(&flux, "serialization.txt", "w+");
    if (flux == NULL){
        printf("Error\n");
    }
    else {
        person p2;
        fprintf_s(flux, STRUCT_FORMAT_OUT, p.name, p.age, p.gender);
        fseek(flux,0, SEEK_SET);
        fscanf(flux, STRUCT_FORMAT_IN, p2.name, &p2.age, &p2.gender);
        printf("p2 : \n");
        printf("name : %s\n", p2.name);
        printf("age : %d\n", p2.age);
        printf("gender : %c\n", p2.gender);
    }
    return 0;
}
