#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *street;
    char *city;
    char *state;
    char *zip;
} Address;

typedef struct
{
    char *name;
    int age;
    Address address;
    // Flexible array member for hobbies
    char hobbies[];
} Person;

int main()
{
    // Allocate memory for a Person with space for 3 hobby strings
    Person *person1 = malloc(sizeof(Person) + 3 * sizeof(char[50]));
    strcpy(person1->name, "John Doe");
    person1->age = 30;
    strcpy(person1->address.street, "123 Main St");
    strcpy(person1->address.city, "Anytown");
    strcpy(person1->address.state, "NY");
    strcpy(person1->address.zip, "12345");

    // Set hobbies
    strcpy(person1->hobbies, "Programming");
    strcpy(person1->hobbies + strlen("Programming") + 1, "Gaming");
    strcpy(person1->hobbies + strlen("Programming") + 1 + strlen("Gaming") + 1, "Reading");

    printf("Name: %s\n", person1->name);
    printf("Age: %d\n", person1->age);
    printf("Address: %s, %s, %s %s\n", person1->address.street, person1->address.city, person1->address.state, person1->address.zip);
    printf("Hobbies: %s, %s, %s\n", person1->hobbies, person1->hobbies + strlen("Programming") + 1, person1->hobbies + strlen("Programming") + 1 + strlen("Gaming") + 1);

    free(person1);

    return 0;
}