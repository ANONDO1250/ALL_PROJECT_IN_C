#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100

// Member structure
typedef struct {
    int id;
    char name[100];
    char contact[100];
} Member;

Member members[MAX_MEMBERS];  // Array to store members
int numMembers = 0;           // Number of members in the system

// Function prototypes
void addMember();
void displayMembers();
void searchMember();

int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Member\n");
        printf("2. Display Members\n");
        printf("3. Search Member\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMember();
                break;
            case 2:
                displayMembers();
                break;
            case 3:
                searchMember();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}

// Function to add a member to the system
void addMember() {
    if (numMembers == MAX_MEMBERS) {
        printf("The member database is full. Cannot add more members.\n");
        return;
    }

    Member newMember;
    printf("\nEnter Member ID: ");
    scanf("%d", &newMember.id);
    printf("Enter Member Name: ");
    scanf(" %[^\n]s", newMember.name);
    printf("Enter Contact Information: ");
    scanf(" %[^\n]s", newMember.contact);

    members[numMembers++] = newMember;
    printf("Member added successfully!\n");
}

// Function to display all members in the system
void displayMembers() {
    if (numMembers == 0) {
        printf("No members found in the system.\n");
        return;
    }

    printf("\nMember List:\n");
    printf("-----------------------------\n");
    printf("ID\tName\t\tContact\n");
    printf("-----------------------------\n");

    for (int i = 0; i < numMembers; i++) {
        printf("%d\t%s\t\t%s\n", members[i].id, members[i].name, members[i].contact);
    }
}

// Function to search for a member by name or ID
void searchMember() {
    if (numMembers == 0) {
        printf("No members found in the system.\n");
        return;
    }

    char keyword[100];
    printf("\nEnter the name or ID to search: ");
    scanf(" %[^\n]s", keyword);

    printf("\nSearch Results:\n");
    printf("-----------------------------\n");
    printf("ID\tName\t\tContact\n");
    printf("-----------------------------\n");

    int found = 0;

    for (int i = 0; i < numMembers; i++) {
        if (strstr(members[i].name, keyword) != NULL || members[i].id == atoi(keyword)) {
            printf("%d\t%s\t\t%s\n", members[i].id, members[i].name, members[i].contact);
            found = 1;
        }
    }

    if (!found) {
        printf("No members found matching the search criteria.\n");
    }
}
