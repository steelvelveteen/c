#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    char *name;
    int age;
} Pet;

int main (int argc, char **argv) {

    Person person;
    person.name = "Joey";
    person.age = 44;

    printf("Name: %s , Age: %i\n", person.name, person.age);
    Pet *dog = malloc(sizeof(Pet));
    dog->name = "Blacky";
    dog->age = 14;

    printf("Pet name: %s , aged: %d\n", dog->name, dog->age);
    free(dog);
    return 0;

}
