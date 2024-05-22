#include <stdio.h>
#include <string.h>
#include <ctype.h> 

struct item {
  int id;
  char itemName[30];
  int price;
};

void displayMenu(struct item menuItems[], int numItems) {
  printf("\n\t FatMouth Menu \n");
  printf("\t-----------------\n");
  for (int i = 0; i < numItems; i++) {
    printf("%d. %s (?%d)\n", menuItems[i].id, menuItems[i].itemName, menuItems[i].price);
  }
  printf("\n");
}

void displayBill(struct item items[], int size, char customerName[], char address[]) {
  int total = 0;

  printf("\n\n\n\n");
  printf("\t FatMouth \n");
  printf("\t----------\n");
  printf("\n");
  printf("Name : %s \t Address : %s \n", customerName, address);
  printf("\n");

  for (int i = 0; i < size; i++) {
    printf("Id : %d\t", items[i].id);
    printf("Name : %s\t", items[i].itemName);
    printf("Price : ?%d\t", items[i].price);
    printf("-----------------------------------------\n");
    total += items[i].price;
  }

  printf("\t\tTotal : ?%d", total);
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

  struct item menuItems[] = {
    {1, "Burger", 100},
    {2, "Fries", 50},
    {3, "Soda", 30},
  };
  int numMenuItems = sizeof(menuItems) / sizeof(menuItems[0]);

  printf("Here's our menu:\n");
  displayMenu(menuItems, numMenuItems);

  printf("Enter the total number of items you want to order: ");
  scanf("%d", &totalItems);

  struct item items[totalItems];

  for (int i = 0; i < totalItems; i++) {
    char selectedItemName[30];
    int found = 0;

    do {
      printf("Enter the name of item %d (from the menu): ", i + 1);
      scanf(" %s", selectedItemName);

      for (int j = 0; j < strlen(selectedItemName); j++) {
        selectedItemName[j] = tolower(selectedItemName[j]);
      }

      for (int j = 0; j < numMenuItems; j++) {
        char menuItemNameLower[30];
        strcpy(menuItemNameLower, menuItems[j].itemName); 
        for (int k = 0; k < strlen(menuItemNameLower); k++) {
          menuItemNameLower[k] = tolower(menuItemNameLower[k]);
        }
        if (strcmp(selectedItemName, menuItemNameLower) == 0) {
          found = 1; 
         break;
        }
      }

      if (!found) {
        printf("Invalid item name. Please choose from the menu.\n");
      }
    } while (!found);
  }

  displayBill(items, totalItems, customerName, address);

  return 0;
}

