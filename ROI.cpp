#include <stdio.h>
#include <string.h>

struct list {
    int id;
    char itemName[30];
    int price;
};

void displayBill(struct list items[], int size, char customerName[], char address[]) { 
    int total = 0;

    printf("\n\n\n\n");
    printf("\t FatMouth \n");
    printf("\t-----------------------\n");
    printf("\n");
    printf("Name : %s \t Address : %s \n", customerName, address);
    printf("\n");

    for (int i = 0; i < size; i++) {
        printf("Id : %d\t", items[i].id);
        printf("Name : %s\t", items[i].itemName);
        printf("-----------------------------------------\n");
        printf("Price : %d\t", items[i].price);
        printf("-----------------------------------------\n");
        total += items[i].price;
    }

    printf("\t\tTotal : %d", total);
    printf("\n\n");
    printf("\t Thanks for visiting FatMouth! \n"); 
    printf("\n\n");
}

int main() {
    printf("Hello! Welcome to FatMouth.\n"); 

    char customerName[30];
    char address[30];
    int totalItems;

    printf("Enter your name: ");
    scanf(" %s", customerName); 

    printf("Enter your address: ");
    scanf(" %s", address);

    printf("Enter the total number of items: ");
    scanf("%d", &totalItems);

   
    struct list items[totalItems];


    for (int i = 0; i < totalItems; i++) {
        items[i].id = i + 1; 
        printf("Enter the name of item %d: ", i + 1);
        scanf(" %s", items[i].itemName);

        printf("Enter the price of item %d: ", i + 1);
        scanf("%d", &items[i].price);
    }

    displayBill(items, totalItems, customerName, address);

    return 0;
}

