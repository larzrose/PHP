#include <stdio.h>
#include <string.h>

struct menu_item {
  int id;
  char name[30];
  int price;
};

struct menu_item menu[] = {
  {1, "Classic Burger", 59},
  {2, "Biryani", 199},
  {3, "Root Beer", 80},
  {4, "Fries", 49},
  {5, "Onion Rings", 120},
  {6, "Soft Drink", 25},
};

int num_menu_items = sizeof(menu) / sizeof(menu[0]);

void displayMenu() {
  printf("\n\n FatMouth Menu \n");
  printf("---------------------\n\n");
  for (int i = 0; i < num_menu_items; i++) {
    printf("Id: %d\t Name: %-30s Price: %d\n", menu[i].id, menu[i].name, menu[i].price);
  }
}

void displayBill(struct menu_item items[], int size, char customerName[], char address[]) {
  int total = 0;

  printf("\n\n\n\n");
  printf("\t FatMouth \n");
  printf("\t-----------\n");
  printf("\n");
  printf("Name : %s \t Address : %s \n", customerName, address);
  printf("\n");

  for (int i = 0; i < size; i++) {
    printf("Id : %d\t", items[i].id);
    printf("Name : %s\t", items[i].name);
    printf("Price : %d\t", items[i].price);
    printf("\n-----------------------------------------\n");
    total += items[i].price;
  }

  printf("\t\tTotal : %d", total);
  printf("\n\n");
  printf("\t Thanks for visiting FatMouth! \n");
  printf("\n\n");
}

int main() {
  printf("Hello! Welcome to FatMouth.\n\n");

  char customerName[30];
  char address[30];
  int totalItems;
  char orderAgain; 

  printf("Enter your name: ");
  fgets(customerName, 30, stdin);
  customerName[strcspn(customerName, "\n")] = '\0';

  printf("Enter your address: ");
  fgets(address, 30, stdin);
  address[strcspn(address, "\n")] = '\0';

  do {
    displayMenu();

    printf("\nHow many items would you like to order? ");
    scanf("%d", &totalItems);

    struct menu_item items[totalItems];

    for (int i = 0; i < totalItems; i++) {
      int selectedId;
      int found = 0;

      do {
        printf("\nEnter the ID of item %d (from the menu): ", i + 1);
        scanf("%d", &selectedId);

        for (int j = 0; j < num_menu_items; j++) {
          if (menu[j].id == selectedId) {
            items[i] = menu[j];
            found = 1;
            break;
          }
        }

        if (!found) {
          printf("Invalid ID. Please enter a valid ID from the menu.\n");
        }
      } while (!found);
    }

    displayBill(items, totalItems, customerName, address);

    printf("Would you like to order again? (y/n): ");
    scanf(" %c", &orderAgain); 
  } while (orderAgain == 'y' || orderAgain == 'Y'); 

  return 0;
}

