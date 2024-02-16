#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define MAX_NAME_LENGTH 256
#define HASHMAP_DIVIDER 9


struct Person_ {
    char name[MAX_NAME_LENGTH];
    int age;

    struct Person_* next;
};
typedef struct Person_ Person;

Person* hash_table[TABLE_SIZE];


void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void printHashTable() {
    printf("\nPrinting Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL)
            printf("NULL");
        else {
            Person* current_person = hash_table[i];
            while (current_person != NULL) {
                printf("%s, ", current_person->name);
                current_person = current_person->next;
            }
        }
        printf("\n");
    }
    printf("\n");    
}

int hash(char* name) {
    int length = strlen(name);
    unsigned long int ASCII_sum = 0;
    for (int i = 0; i < length; i++, name++) {
        ASCII_sum += *name;
        ASCII_sum *= *name/HASHMAP_DIVIDER;
    }
    return ASCII_sum % TABLE_SIZE;
}

bool insertHashTable(char* name, int age) {
    int index = hash(name);
    if (hash_table[index] == NULL) {

        Person* new_person = (Person*)malloc(sizeof(Person));
        new_person->next = NULL;
        new_person->age = age;
        strcpy(new_person->name, name);

        hash_table[index] = new_person;
        return true;
    }
    else {
        // Traverse linked list to see if there is a duplicate
        Person* current_person = hash_table[index];
        for (; current_person->next != NULL; current_person = current_person->next) {
            if (!strcmp(name, current_person->name) && age == current_person->age) {
                return false;
            }
        }
        // The for loop above does not check the tail, so we have to do this one more time
        if (!strcmp(name, current_person->name) && age == current_person->age) {
            return false;
        }

        // Now we can add it
        Person* new_person = (Person*)malloc(sizeof(Person));
        new_person->next = NULL;
        new_person->age = age;
        strcpy(new_person->name, name);
        
        current_person->next = new_person;
    }
}

bool deletePerson(char* name, int age) {
    
    int index = hash(name);
    Person* current_person = hash_table[index];

    if (!strcmp(current_person->name, name) && age == current_person->age && current_person != NULL) {
        Person* to_delete = current_person;
        hash_table[index] = current_person->next;
        free(to_delete);
        return true;
    }
    else {
        Person* current_person = hash_table[index]->next;
        Person* prev_person = hash_table[index];
        for (; current_person != NULL; current_person = current_person->next, prev_person = prev_person->next) {
            if (!strcmp(current_person->name, name) && age == current_person->age) {
                Person* to_delete = current_person;
                prev_person = to_delete->next;
                free(to_delete);
                return true;
            }
        }
        // Person Not Found
        return false;
    }
}


int main() {
    printHashTable();

    insertHashTable("Selimon Shukurzad", 23);
    printHashTable();

    insertHashTable("Selimon Shukurzad", 24);
    printHashTable();

    deletePerson("Selimon Shukurzad", 23);
    printHashTable();
}