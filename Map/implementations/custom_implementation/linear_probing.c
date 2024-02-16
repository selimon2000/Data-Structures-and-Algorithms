#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define HASHMAP_DIVIDER 9


// NOTE: USING AGE AS A VARIABLE WHEN FINDING PERSON IS DUMB AS IT WILL CHANGE 
typedef struct {
    char name[MAX_NAME];
    int age;
} Person;

// Advantage of using pointers - dynamic memory
Person* hash_table[TABLE_SIZE];

int hash(char* name) {
    int length = strlen(name);
    unsigned long int ASCII_sum = 0;
    for (int i = 0; i < length; i++, name++) {
        ASCII_sum += *name;
        ASCII_sum *= *name/HASHMAP_DIVIDER;
    }
    return ASCII_sum % TABLE_SIZE;
}

void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hash_table[i] = NULL;    
}

void printTable() {
    printf("Printing Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL)
            printf("NULL\n");
        else
            printf("NAME: %s, AGE: %d\n", hash_table[i]->name, hash_table[i]->age);
    }
     printf("\n");
}

// Returning False if function is not able to insert
bool insert(char* name, int age) {
    Person *new_person = (Person *)malloc(sizeof(Person));
    new_person->age = age;
    strncpy(new_person->name, name, MAX_NAME);

    int index = hash(name);
    if (hash_table[index] == NULL) {
        hash_table[index] = new_person;
        return true;
    }
    else {
        // If the exact user already exists, we can avoid entering it twice
        if (!strcmp(name, hash_table[index]->name) && age == hash_table[index]->age) {
            printf("ERROR: PERSON ALREADY EXISTS\n\n");
            return false; // I guess I could return true here since the person is in here
        }
        // If there is a collision, resolve it with linear probing
        else {
            int starting_index = index;
            index++;
            index %= TABLE_SIZE;
            while (hash_table[index] != NULL) {

                // The exact user may already exist in the next linear location due to linear probing
                if (!strcmp(name, hash_table[index]->name) && age == hash_table[index]->age) {
                    printf("ERROR: PERSON ALREADY EXISTS\n\n");
                    return false; // I guess I could return true here since the person is in here
                }

                if (index == starting_index) {
                    printf("Insert Operation cancelled as no empty spaces\n\n");
                    return false;
                }

                index++;
                index %= TABLE_SIZE;
            }
            
            hash_table[index] = new_person;
            return true;
        }
    }
}

Person* lookup(char* name, int age) {
    int index = hash(name);

    for (int i = 0; i < TABLE_SIZE; i++) {

        Person* possible_person = hash_table[index];
        if (hash_table[index] != NULL && !strcmp(name, possible_person->name) && possible_person->age == age)
            return (hash_table[index]);
    }

    // Person not found
    return NULL;
}

Person* deletePerson(char* name, int age) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        
        Person* possible_person = hash_table[try];
        if (hash_table[try] != NULL && !strcmp(name, possible_person->name) && possible_person->age == age) {
            hash_table[try] = NULL;
            return possible_person;
        }
    }
    // Person Not Found
    return NULL;
}


int main() {
    init_hash_table();
    printTable();

    insert("Selimon Shukurzad", 23);
    printTable();

    insert("Selimon Shukurzad", 24);
    printTable();

    insert("Selimon Shukurzad", 24);
    printTable();

    insert("Subhan Shukurzad", 12);
    printTable();

    Person* lookup_person = lookup("Selimon Shukurzad", 23);
    if (lookup_person == NULL)
        printf("Lookup operation failed - person not found\n\n");
    else
        printf("From Lookup:\nName: %s\nAge: %d\n\n", lookup_person->name, lookup_person->age);
    
    deletePerson("Selimon Shukurzad", 23);
    printTable();
}