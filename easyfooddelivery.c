#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for restaurant, menu item, user, and order
typedef struct MenuItem
{
    char itemName[50];
    float price;
    struct MenuItem* next;
} MenuItem;

typedef struct Restaurant
{
    char name[50];
    MenuItem* menu;
    struct Restaurant* next;
} Restaurant;

typedef struct User
{
    char username[20];
    char password[20];
    char deliveryAddress[20];
    struct User* next;
} User;

typedef struct Order
{
    char restaurantName[50];
    char itemName[50];
    float price;
    char deliveryAddress[20];
    char paymentMethod[20];
    struct Order* next;
} Order;

// Function prototypes
int adminLogin();
void adminMenu();
void addRestaurant();
void addItemToRestaurant();
void deleteRestaurant();
void deleteItemFromRestaurant();
void updateRestaurant();
void updateMenuItem();
void viewAllRestaurants();
void viewRestaurantMenu();
void addUser();
int userLogin();
void userMenu();
void displayRestaurants();
void searchRestaurant();
void placeOrder();
void aboutUS();

// File handling functions
void saveRestaurantsToFile();
void loadRestaurantsFromFile();
void saveUsersToFile();
void loadUsersFromFile();
void saveOrdersToFile();
void loadOrdersFromFile();

// Global variables
Restaurant* restaurantList = NULL;
User* userList = NULL;
Order* orderQueue = NULL;

int main()
{
    system("color 0B");
    // Load data from files
    loadRestaurantsFromFile();
    loadUsersFromFile();
    loadOrdersFromFile();

    printf("\t                *~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.*\n");
    printf("\t          *~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~*\n");
    printf("\t  ~.~.*~.~.~.~.~.* ~.~.~.~.~.*~.~.~.~.~.* ~.~.~.~.~.*~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.* ~.~.~.~.~.*~.~.~.~.~.* ~.~.~.~.~.*~.~.~.~.~.* ~.~.~.~.~.*~.~.~.~.~.* ~.~.~.~.~.*~.~.~.~.~.* ~.~.~.~.~.*.~.*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~------------------------------------------------------------~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~------------------------------------------------------------~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.|                                                            |~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.|                                                            |~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.|................||.. E A S Y F O O D..||...................|~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.|                                                            |~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.|                                                            |~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~------------------------------------------------------------~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~------------------------------------------------------------~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.*\n");
    printf("\t  ~.~.*~.~.~.~.~.* ~.~.~.~.~.*~.~.~.~.~.* ~.~.~.~.~.*~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.*\n");
    printf("\t          *~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~*\n");
    printf("\t                *~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.*\n");



    int choice;
    do
    {
        printf("\n\n");
        printf("\t\t\t*~.~.~.~.~-------------------------------------------------------------~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.~------------------------------------------------------------~.~.~.~.~.~*\n");
        printf("\t\t\t*~.~.~.~.|...F O O D   O R D E R  &   D E L I V E R Y   S Y S T E M ..|~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|                  -----------------                         |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|                  |  1. ADMIN     |                         |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|                  |  2. USER      |                         |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|                  |  3. ABOUT US  |                         |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|                  |  4. EXIT      |                         |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|                  -----------------                         |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|                                                            |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.~-------------------------------------------------------------~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.~-------------------------------------------------------------~.~.~.~.~.*\n");
        printf("\t\t\t\t\tEnter your choice : ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            if (adminLogin())
            {
                adminMenu();
            }
            else
            {
                printf("\n\n");
                printf("                                .-------------------------------------------------------------.\n");
                printf("                                .|         Invalid login credentials for admin.               |\n");
                printf("                                .-------------------------------------------------------------.\n\n");


            }
            break;
        case 2:
            printf("\t\t\t\t\t1.Login\n");
            printf("\t\t\t\t\t2.Register\n");
            printf("\t\t\t\t\t Enter: ");
            int enter, lg;
            scanf("%d",&enter);
            if(enter==1)
            {
                lg = userLogin();
            }
            else if(enter==2)
            {
                addUser();
                lg = userLogin();
            }


            if(lg==1)
            {
                userMenu();
            }
            else
            {
                printf("\n\n");
                printf("                                .-------------------------------------------------------------.\n");
                printf("                                .|      Invalid login credentials for admin.                  |\n");
                printf("                                .-------------------------------------------------------------.\n\n");


            }
            break;
        case 3:
            aboutUS();
            break;
        case 4:
            saveRestaurantsToFile();
            saveUsersToFile();
            saveOrdersToFile();
            printf("\n\n");
            printf("                                .-------------------------------------------------------------.\n");
            printf("                                .|       Exiting program.Data saved to files                  |\n");
            printf("                                .-------------------------------------------------------------.\n");


            break;
        default:
            printf("\n\n");
            printf("                                .-------------------------------------------------------------.\n");
            printf("                                .|    Invalid choice.Please enter a valid option              |\n");
            printf("                                .-------------------------------------------------------------.\n");

        }
    }
    while (choice != 4);

    return 0;
}

// Admin functions
int adminLogin()
{
    char enteredUsername[20];
    char enteredPassword[20];
    printf("\t\t\t\t\tEnter Admin Username : ");
    scanf("%s", enteredUsername);

    printf("\t\t\t\t\tEnter admin password : ");
    scanf("%s", enteredPassword);

    if (strcmp(enteredUsername, "noman") == 0 && strcmp(enteredPassword, "123456") == 0)
    {
        system("cls");
        printf("\n\t\t\t\t\tWelcome again Mr Noman.\n");
        return 1;  // Return 1 for successful login
    }
    else if(strcmp(enteredUsername, "tuly") == 0 && strcmp(enteredPassword, "123456") == 0)
    {
        system("cls");
        printf("\n\t\t\t\t\tWelcome again Ms Tuly\n");
        return 1;
    }
    else if(strcmp(enteredUsername, "shafin") == 0 && strcmp(enteredPassword, "123456") == 0)
    {
        system("cls");
        printf("\n\t\t\t\t\tWelcome again Mr Shafin\n");
        return 1;
    }
    else if(strcmp(enteredUsername, "mim") == 0 && strcmp(enteredPassword, "123456") == 0)
    {
        system("cls");
        printf("\n\t\t\t\t\tWelcome again Ms Mim\n");
        return 1;
    }
    else if(strcmp(enteredUsername, "jamil") == 0 && strcmp(enteredPassword, "123456") == 0)
    {
        system("cls");
        printf("\n\t\t\t\t\tWelcome again Mr Jamil\n");
        return 1;
    }

    else
    {
        printf("\n\n");
        printf("                                .-------------------------------------------------------------.\n");
        printf("                                .|              Invalid login. Please try again               |\n");
        printf("                                .-------------------------------------------------------------.\n");

        return 0;  // Return 0 for unsuccessful login
    }
}

void adminMenu()
{
    int choice;
    do
    {
        printf("\n\n");
        printf("\t\t\t*~.~.~.~.~-------------------------------------------------------------~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.~------------------------------------------------------------~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|...............   A D M I N   M E N U          .............|~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          ------------------------------------              |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          |  1.Add restaurant                |              |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          |  2.Add Item to Restaurant        |              |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          |  3.Delete Restaurant             |              |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          |  4.Delete item from restaurant   |              |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          |  5.Update restaurant information |              |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          |  6.Update item information       |              |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          |  7.View all restaurants          |              |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          |  8.view Restaurant's menu        |              |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          |  9.Exit                          |              |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          ------------------------------------              |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.~-------------------------------------------------------------~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.~-------------------------------------------------------------~.~.~.~.~.*\n");

        printf("\n\t\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Implement add restaurant logic
            addRestaurant();
            break;
        case 2:
            // Implement add item to restaurant logic
            addItemToRestaurant();
            break;
        case 3:
            // Implement delete restaurant logic
            deleteRestaurant();
            break;
        case 4:
            // Implement delete item from restaurant logic
            deleteItemFromRestaurant();
            break;
        case 5:
            // Implement update restaurant information logic
            updateRestaurant();
            break;
        case 6:
            // Implement update item information logic
            updateMenuItem();
            break;
        case 7:
            // Implement view all restaurants logic
            viewAllRestaurants();
            break;
        case 8:
            // Implement view restaurant's menu logic
            viewRestaurantMenu();
            break;
        case 9:
            printf("\t\t\t\t\tExiting admin menu.\n");
            break;
        default:
            printf("\n\n");
            printf("                                .-------------------------------------------------------------.\n");
            printf("                                .|         Invalid choice. Please enter a valid option.       |\n");
            printf("                                .-------------------------------------------------------------.\n");


        }
    }
    while (choice != 9);
}

void addRestaurant()
{
    // Create a new restaurant
    Restaurant* newRestaurant = (Restaurant*)malloc(sizeof(Restaurant));

    printf("\t\t\t\t\tEnter restaurant name: ");
    scanf("%s", newRestaurant->name);

    newRestaurant->menu = NULL; // Initialize menu as empty
    newRestaurant->next = NULL;

    // Add the restaurant to the linked list
    if (restaurantList == NULL)
    {
        restaurantList = newRestaurant;
    }
    else
    {
        Restaurant* lastRestaurant = restaurantList;
        while (lastRestaurant->next != NULL)
        {
            lastRestaurant = lastRestaurant->next;
        }
        lastRestaurant->next = newRestaurant;
    }

    // Add menu items for the restaurant
    int numItems;
    printf("\t\t\t\t\tEnter the number of menu items: ");
    scanf("%d", &numItems);

    for (int i = 0; i < numItems; i++)
    {
        // Create a new menu item
        MenuItem* newMenuItem = (MenuItem*)malloc(sizeof(MenuItem));

        printf("\t\t\t\t\tEnter item name for %s: ", newRestaurant->name);
        scanf("%s", newMenuItem->itemName);

        printf("\t\t\t\t\tEnter price for %s: ", newMenuItem->itemName);
        scanf("%f", &newMenuItem->price);

        newMenuItem->next = NULL;

        // Add the menu item to the restaurant's menu
        if (newRestaurant->menu == NULL)
        {
            newRestaurant->menu = newMenuItem;
        }
        else
        {
            MenuItem* lastMenuItem = newRestaurant->menu;
            while (lastMenuItem->next != NULL)
            {
                lastMenuItem = lastMenuItem->next;
            }
            lastMenuItem->next = newMenuItem;
        }
    }
    printf("\n\n");

    printf("                                .-------------------------------------------------------------.\n");
    printf("                                |               Restaurant added successfully                 |\n");
    printf("                                .-------------------------------------------------------------.\n");



}

void addItemToRestaurant()
{
    char restaurantName[50];
    char itemName[50];
    float itemPrice;

    // Prompt the admin to enter the restaurant name
    printf("\n\t\t\t\t\tEnter the restaurant name to add an item: ");
    scanf("%s", restaurantName);

    // Search for the restaurant in the linked list
    Restaurant* currentRestaurant = restaurantList;
    while (currentRestaurant != NULL)
    {
        if (strcmp(currentRestaurant->name, restaurantName) == 0)
        {
            // If the restaurant is found, prompt for the new item details
            printf("\n\t\t\t\t\tEnter the name of the item to add: ");
            scanf("%s", itemName);

            printf("\t\t\t\t\tEnter the price of the item: ");
            scanf("%f", &itemPrice);

            // Create a new menu item
            MenuItem* newMenuItem = (MenuItem*)malloc(sizeof(MenuItem));
            strcpy(newMenuItem->itemName, itemName);
            newMenuItem->price = itemPrice;
            newMenuItem->next = NULL;

            // Add the new item to the restaurant's menu
            if (currentRestaurant->menu == NULL)
            {
                currentRestaurant->menu = newMenuItem;
            }
            else
            {
                MenuItem* lastMenuItem = currentRestaurant->menu;
                while (lastMenuItem->next != NULL)
                {
                    lastMenuItem = lastMenuItem->next;
                }
                lastMenuItem->next = newMenuItem;
            }

            printf("\n\t\t\t\t\tItem added to %s successfully.\n", restaurantName);
            return;
        }

        currentRestaurant = currentRestaurant->next;
    }

    // If the restaurant is not found
    printf("\t\t\t\t\tRestaurant '%s' not found.\n", restaurantName);
}

void deleteRestaurant()
{
    char restaurantName[50];

    // Prompt the admin to enter the restaurant name to delete
    printf("\t\t\t\t\tEnter the name of the restaurant to delete: ");
    scanf("%s", restaurantName);

    // Handle the case where the restaurant to delete is the first in the list
    if (restaurantList != NULL && strcmp(restaurantList->name, restaurantName) == 0)
    {
        Restaurant* temp = restaurantList;
        restaurantList = restaurantList->next;
        free(temp);
        printf("\n\t\t\t\t\tRestaurant '%s' deleted successfully.\n", restaurantName);
        return;
    }

    // Search for the restaurant in the linked list
    Restaurant* currentRestaurant = restaurantList;
    Restaurant* prevRestaurant = NULL;

    while (currentRestaurant != NULL)
    {
        if (strcmp(currentRestaurant->name, restaurantName) == 0)
        {
            // If the restaurant is found, delete it from the list
            prevRestaurant->next = currentRestaurant->next;
            free(currentRestaurant);
            printf("\t\t\t\t\tRestaurant '%s' deleted successfully.\n", restaurantName);
            return;
        }

        prevRestaurant = currentRestaurant;
        currentRestaurant = currentRestaurant->next;
    }

    // If the restaurant is not found
    printf("\t\t\t\t\tRestaurant '%s' not found.\n", restaurantName);
}

void deleteItemFromRestaurant()
{
    char restaurantName[50];
    char itemName[50];

    // Prompt the admin to enter the restaurant name
    printf("\n\t\t\t\t\tEnter the name of the restaurant to delete an item from: ");
    scanf("%s", restaurantName);

    // Search for the restaurant in the linked list
    Restaurant* currentRestaurant = restaurantList;

    while (currentRestaurant != NULL)
    {
        if (strcmp(currentRestaurant->name, restaurantName) == 0)
        {
            // If the restaurant is found, prompt for the item name to delete
            printf("\t\t\t\t\tEnter the name of the item to delete: ");
            scanf("%s", itemName);

            // Handle the case where the item to delete is the first in the menu
            if (currentRestaurant->menu != NULL && strcmp(currentRestaurant->menu->itemName, itemName) == 0)
            {
                MenuItem* temp = currentRestaurant->menu;
                currentRestaurant->menu = currentRestaurant->menu->next;
                free(temp);
                printf("\t\t\t\t\tItem '%s' deleted from %s successfully.\n", itemName, restaurantName);
                return;
            }

            // Search for the item in the menu
            MenuItem* currentItem = currentRestaurant->menu;
            MenuItem* prevItem = NULL;

            while (currentItem != NULL)
            {
                if (strcmp(currentItem->itemName, itemName) == 0)
                {
                    // If the item is found, delete it from the menu
                    prevItem->next = currentItem->next;
                    free(currentItem);
                    printf("\t\t\t\t\tItem '%s' deleted from %s successfully.\n\n", itemName, restaurantName);
                    return;
                }

                prevItem = currentItem;
                currentItem = currentItem->next;
            }

            // If the item is not found in the menu
            printf("\t\t\t\t\tItem '%s' not found in %s's menu.\n\n", itemName, restaurantName);
            return;
        }

        currentRestaurant = currentRestaurant->next;
    }

    // If the restaurant is not found
    printf("\t\t\t\t\tRestaurant '%s' not found.\n", restaurantName);
}

void updateRestaurant()
{
    char restaurantName[50];
    char newRestaurantName[50];

    // Prompt the admin to enter the name of the restaurant to update
    printf("\n\t\t\t\t\tEnter the name of the restaurant to update: ");
    scanf("%s", restaurantName);

    // Search for the restaurant in the linked list
    Restaurant* currentRestaurant = restaurantList;

    while (currentRestaurant != NULL)
    {
        if (strcmp(currentRestaurant->name, restaurantName) == 0)
        {
            // If the restaurant is found, prompt for the new restaurant name
            printf("\t\t\t\t\tEnter the new name for the restaurant: ");
            scanf("%s", newRestaurantName);

            // Update the restaurant name
            strcpy(currentRestaurant->name, newRestaurantName);

            printf("\t\t\t\t\tRestaurant information updated successfully.\n");
            return;
        }

        currentRestaurant = currentRestaurant->next;
    }

    // If the restaurant is not found
    printf("\t\t\t\t\tRestaurant '%s' not found.\n", restaurantName);
}

void updateMenuItem()
{
    char restaurantName[50];
    char itemName[50];
    char newItemName[50];
    float newPrice;

    // Prompt the admin to enter the name of the restaurant
    printf("\t\t\t\t\tEnter the name of the restaurant: ");
    scanf("%s", restaurantName);

    // Search for the restaurant in the linked list
    Restaurant* currentRestaurant = restaurantList;

    while (currentRestaurant != NULL)
    {
        if (strcmp(currentRestaurant->name, restaurantName) == 0)
        {
            // If the restaurant is found, prompt for the name of the menu item to update
            printf("\t\t\t\t\tEnter the name of the menu item to update: ");
            scanf("%s", itemName);

            // Search for the menu item in the restaurant's menu
            MenuItem* currentItem = currentRestaurant->menu;

            while (currentItem != NULL)
            {
                if (strcmp(currentItem->itemName, itemName) == 0)
                {
                    // If the menu item is found, prompt for the new information
                    printf("\t\t\t\t\tEnter the new name for the menu item: ");
                    scanf("%s", newItemName);

                    printf("\t\t\t\t\tEnter the new price for the menu item: ");
                    scanf("%f", &newPrice);

                    // Update the menu item information
                    strcpy(currentItem->itemName, newItemName);
                    currentItem->price = newPrice;
                    printf("\n\n");
                    printf("                                .-------------------------------------------------------------.\n");
                    printf("                                |         Menu item information updated successfully.         |\n");
                    printf("                                .-------------------------------------------------------------.\n");

                    return;
                }

                currentItem = currentItem->next;
            }

            // If the menu item is not found in the restaurant's menu
            printf("\n\t\t\t\t\tMenu item '%s' not found in %s's menu.\n", itemName, restaurantName);
            return;
        }

        currentRestaurant = currentRestaurant->next;
    }

    // If the restaurant is not found
    printf("\n\t\t\t\t\tRestaurant '%s' not found.\n", restaurantName);
}

void viewAllRestaurants()
{
    // Check if there are no restaurants
    if (restaurantList == NULL)
    {
        printf("\n\n");
        printf("                                .-------------------------------------------------------------.\n");
        printf("                                |              No restaurants available.                       |\n");
        printf("                                .-------------------------------------------------------------.\n");

        return;
    }
    printf("\n\n");
    printf("                                .-------------------------------------------------------------.\n");
    printf("                                |               List of all restaurants                       |\n");
    printf("                                .-------------------------------------------------------------.\n");


    // Iterate through the restaurant list
    Restaurant* currentRestaurant = restaurantList;

    while (currentRestaurant != NULL)
    {
        printf("\n\t\t\t\t\tRestaurant Name: %s\n", currentRestaurant->name);

        // Check if there are no menu items for the current restaurant
        if (currentRestaurant->menu == NULL)
        {
            printf("\n\n");
            printf("                                .-------------------------------------------------------------.\n");
            printf("                                |          No menu items available for this restaurant        |\n");
            printf("                                .-------------------------------------------------------------.\n");


        }
        else
        {
            printf("\n\n");
            printf("                                .-------------------------------------------------------------.\n");
            printf("                                |                     Menu Items                              |\n");
            printf("                                .-------------------------------------------------------------.\n");


            // Iterate through the menu items for the current restaurant
            MenuItem* currentItem = currentRestaurant->menu;

            while (currentItem != NULL)
            {
                printf("\t\t\t\t\t  Item Name: %s, Price: %.2f\n", currentItem->itemName, currentItem->price);
                currentItem = currentItem->next;
            }
        }
      printf("\n\n\t\t\t\t-----------------------------------------------------------------------\n");
        currentRestaurant = currentRestaurant->next;
    }
}

void viewRestaurantMenu()
{
    char restaurantName[50];

    // Prompt the user to enter the name of the restaurant
    printf("\n\n\t\t\t\t\tEnter the name of the restaurant to view the menu: ");
    scanf("%s", restaurantName);

    // Search for the restaurant in the linked list
    Restaurant* currentRestaurant = restaurantList;

    while (currentRestaurant != NULL)
    {
        if (strcmp(currentRestaurant->name, restaurantName) == 0)
        {
            // If the restaurant is found, display its menu
            printf("\n\t\t\t\t\tMenu for %s:\n", restaurantName);

            // Check if there are no menu items for the current restaurant
            if (currentRestaurant->menu == NULL)

            {
                printf("\n\n");
                printf("                                .-------------------------------------------------------------.\n");
                printf("                                |          No menu items available for this restaurant        |\n");
                printf("                                .-------------------------------------------------------------.\n");

            }
            else
            {
                // Iterate through the menu items for the current restaurant
                MenuItem* currentItem = currentRestaurant->menu;

                while (currentItem != NULL)
                {
                    printf("\t\t\t\t\t  Item Name: %s, Price: %.2f\n", currentItem->itemName, currentItem->price);
                    currentItem = currentItem->next;
                }
            }

            return;
        }

        currentRestaurant = currentRestaurant->next;
    }

    // If the restaurant is not found
    printf("\t\t\t\t\tRestaurant '%s' not found.\n", restaurantName);
}


// User functions
void addUser()
{
    // Create a new user
    User* newUser = (User*)malloc(sizeof(User));

    printf("\t\t\t\t\tEnter username: ");
    scanf("%s", newUser->username);

    printf("\t\t\t\t\tEnter password: ");
    scanf("%s", newUser->password);

    printf("\t\t\t\t\tEnter delivery address: ");
    scanf("%s", newUser->deliveryAddress);

    newUser->next = NULL;

    // Add the user to the linked list
    if (userList == NULL)
    {
        userList = newUser;
    }
    else
    {
        User* lastUser = userList;
        while (lastUser->next != NULL)
        {
            lastUser = lastUser->next;
        }
        lastUser->next = newUser;
    }
    printf("\n\n");
    printf("                                .-------------------------------------------------------------.\n");
    printf("                                |                User added successfully                      |\n");
    printf("                                .-------------------------------------------------------------.\n");
}

int userLogin()
{
    char enteredUsername[20];
    char enteredPassword[20];

    printf("\t\t\t\t\tEnter username: ");
    scanf("%s", enteredUsername);

    printf("\t\t\t\t\tEnter password: ");
    scanf("%s", enteredPassword);

    // Search for the user in the linked list
    User* currentUser = userList;

    while (currentUser != NULL)
    {
        if (strcmp(currentUser->username, enteredUsername) == 0 &&
                strcmp(currentUser->password, enteredPassword) == 0)
        {
            printf("\n\n");
            printf("                                .-------------------------------------------------------------.\n");
            printf("                                |                 User login successful                       |\n");
            printf("                                .-------------------------------------------------------------.\n");


            return 1;  // Return 1 for successful login
        }

        currentUser = currentUser->next;
    }
    printf("\n\n");
    printf("                                .-------------------------------------------------------------.\n");
    printf("                                |                 Invalid user credentials                    |\n");
    printf("                                .-------------------------------------------------------------.\n");

    return 0;  // Return 0 for unsuccessful login
}

void userMenu()
{
    int choice;
    do
    {
        printf("\n\n");
        printf("\t\t\t*~.~.~.~.~-------------------------------------------------------------~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.~------------------------------------------------------------~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|...............    U S E R    M E N U          .............|~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          -------------------------------------             |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          |     1.View restaurant             |             |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          |     2.Search Restaurant           |             |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          |     3.Place Order                 |             |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          |     4.Exit                        |             |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.|          -------------------------------------             |~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.~-------------------------------------------------------------~.~.~.~.~.*\n");
        printf("\t\t\t*~.~.~.~.~-------------------------------------------------------------~.~.~.~.~.*\n");

        printf("\t\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayRestaurants();
            break;
        case 2:
            searchRestaurant();
            break;
        case 3:
            placeOrder();
            break;
        case 4:
            printf("\n\n\t\t\t......Exiting user menu.\n");
            break;
        default:
            printf("\n\n");
            printf("                                .-------------------------------------------------------------.\n");
            printf("                                |           Invalid choice. please enter a valid option       |\n");
            printf("                                .-------------------------------------------------------------.\n");


        }
    }
    while (choice != 4);
}

void displayRestaurants()
{
    printf("\n\n");
    printf("                                .-------------------------------------------------------------.\n");
    printf("                                |                   List of restaurants                       |\n");
    printf("                                .-------------------------------------------------------------.\n");


    Restaurant* currentRestaurant = restaurantList;

    while (currentRestaurant != NULL)
    {
        printf("\t\t\t\t\tRestaurant Name: %s\n", currentRestaurant->name);
        printf("\n\n\t\t\t\t\tMenu Items:\n");

        MenuItem* currentMenuItem = currentRestaurant->menu;
        while (currentMenuItem != NULL)
        {
            printf("\t\t\t\t\t  Item: %s, Price: %.2f\n", currentMenuItem->itemName, currentMenuItem->price);
            currentMenuItem = currentMenuItem->next;
        }

        printf("------------------------\n");

        currentRestaurant = currentRestaurant->next;
    }
}


void searchRestaurant()
{
    char searchName[50];
    printf("\t\t\t\t\tEnter the name of the restaurant to search: ");
    scanf("%s", searchName);

    Restaurant* currentRestaurant = restaurantList;
    int found = 0;

    while (currentRestaurant != NULL)
    {
        if (strcmp(currentRestaurant->name, searchName) == 0)
        {
            found = 1;
            printf("\n\n\n\n\t\t\t\t\tRestaurant found!\n");
            printf("\t\t\t\t\tRestaurant Name: %s\n", currentRestaurant->name);
            printf("\t\t\t\t\tMenu Items:\n");

            MenuItem* currentMenuItem = currentRestaurant->menu;
            while (currentMenuItem != NULL)
            {
                printf("\n\t\t\t\t\t  Item: %s, Price: %.2f\n", currentMenuItem->itemName, currentMenuItem->price);
                currentMenuItem = currentMenuItem->next;
            }

            printf("------------------------\n");
            break; // Stop searching after finding the restaurant
        }

        currentRestaurant = currentRestaurant->next;
    }

    if (!found)
    {
        printf("\n\n\t\t\t\t\tRestaurant '%s' not found.\n", searchName);
    }
}

void aboutUS()
{
    printf("\n\n\n\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~------------------------------------------------------------~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~------------------------------------------------------------~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.|                                                            |~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.|...................A B O U T   U S..........................|~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.|                                                            |~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~------------------------------------------------------------~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.*\n");
    printf("*~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~------------------------------------------------------------~.~.~.~.~.*~.~.~.~.~.*~.~.~.~.~.*~.~.*\n\n\n\n");


    printf("\t\t\t\t\t ----------------------------------------\n");
    printf("\t\t\t\t\t ----------------------------------------\n");
    printf("\t\t\t\t\t |.......T E A M   L E A D E R .........|\n");
    printf("\t\t\t\t\t |                                      |\n");
    printf("\t\t\t\t\t |       Abdullah Al Noman              |\n");
    printf("\t\t\t\t\t |   Email:numanyuvraj@gmail.com        |\n");
    printf("\t\t\t\t\t |      Fb:Noman Abdulllah              |\n");
    printf("\t\t\t\t\t ----------------------------------------\n");
    printf("\t\t\t\t\t ----------------------------------------\n\n");



    printf("--------------------------  --------------------------------   -------------------------------   -------------------------------\n");
    printf("--------------------------  --------------------------------   -------------------------------   -------------------------------\n");
    printf("|   Tanjina Ahmed TULY    |  |    Tanjid Ahammed Shafin      |  |     Atia Sultana Mim         |  |      Jamil Hasan            |\n");
    printf("|  Email:tuly@gmail.com   |  |  Email:shafin4903@gmail.com   |  |   Email:atiamim@gmail.com    |  | Email:jomilababu@gmail.com  |\n");
    printf("|   Fb:Tanjina Ahmed      |  |   Fb:Tanjid Ahammed Shafin    |  |    Fb:Atia Sultana Mim       |  |    Fb:Jamil Chowdhory       |\n");
    printf("|                         |  |                               |  |                              |  |                              \n");
    printf("--------------------------   --------------------------------   -------------------------------   ------------------------------\n");
    printf("--------------------------   --------------------------------   -------------------------------   -------------------------------\n");



}


void placeOrder()
{
    displayRestaurants();
    char restaurantName[50];
    char itemName[50];
    char deliveryAddress[20];
    char paymentMethod[20];

    printf("\n\n\t\t\t\t\tEnter the name of the restaurant: ");
    scanf("%s", restaurantName);

    // Search for the restaurant
    Restaurant* currentRestaurant = restaurantList;
    int restaurantFound = 0;

    while (currentRestaurant != NULL)
    {
        if (strcmp(currentRestaurant->name, restaurantName) == 0)
        {
            restaurantFound = 1;
            break;
        }

        currentRestaurant = currentRestaurant->next;
    }

    if (!restaurantFound)
    {
        printf("\n\t\t\t\t\tRestaurant '%s' not found.\n", restaurantName);
        return;
    }

    printf("\t\t\t\t\tEnter the name of the item: ");
    scanf("%s", itemName);

    // Search for the item in the restaurant's menu
    MenuItem* currentMenuItem = currentRestaurant->menu;
    int itemFound = 0;

    while (currentMenuItem != NULL)
    {
        if (strcmp(currentMenuItem->itemName, itemName) == 0)
        {
            itemFound = 1;
            break;
        }

        currentMenuItem = currentMenuItem->next;
    }

    if (!itemFound)
    {
        printf("\t\t\t\t\tItem '%s' not found in the menu.\n", itemName);
        return;
    }
    printf("\t\t\t\t\tAvailable Palce- \n");
    printf("\t\t\t\t\tAB1\n");
    printf("\t\t\t\t\tAB3 \n");
    printf("\t\t\t\t\tAB4\n");
    printf("\t\t\t\t\tYKSG1\n");
    printf("\t\t\t\t\tYKSG2\n");
    printf("\t\t\t\t\tRASG\n");
    printf("\t\t\t\t\tDISS\n");
    printf("\t\t\t\t\tBONOMAYA\n");
    printf("\t\t\t\t\tGATE2\n");
    printf("\t\t\t\t\tEnter Delivery Address :");
    scanf("%s", deliveryAddress);

    printf("\t\t\t\t\tSelect payment method (Bkash, Nagad, Cash): ");
    scanf("%s", paymentMethod);

    // Create a new order
    Order* newOrder = (Order*)malloc(sizeof(Order));
    strcpy(newOrder->restaurantName, restaurantName);
    strcpy(newOrder->itemName, itemName);
    newOrder->price = currentMenuItem->price;
    strcpy(newOrder->deliveryAddress, deliveryAddress);
    strcpy(newOrder->paymentMethod, paymentMethod);
    newOrder->next = NULL;

    // Add the order to the end of the order queue
    if (orderQueue == NULL)
    {
        orderQueue = newOrder;
    }
    else
    {
        Order* lastOrder = orderQueue;
        while (lastOrder->next != NULL)
        {
            lastOrder = lastOrder->next;
        }
        lastOrder->next = newOrder;
    }

    // Update the restaurant's sales information
    currentMenuItem->price += newOrder->price;

    // Save the order to a file
    FILE* orderFile = fopen("orders.txt", "a");
    if (orderFile == NULL)
    {
        printf("\n\n");
        printf("                                .-------------------------------------------------------------.\n");
        printf("                                |               Error opening orders file                     |\n");
        printf("                                .-------------------------------------------------------------.\n");

        return;
    }

    fprintf(orderFile, "\t\t\t\t\tRestaurant: %s, Item: %s, Price: %.2f, Delivery Address: %s, Payment Method: %s\n",
            newOrder->restaurantName, newOrder->itemName, newOrder->price,
            newOrder->deliveryAddress, newOrder->paymentMethod);

    fclose(orderFile);
    printf("                                .-------------------------------------------------------------.\n");
    printf("                                |             Order placed successfully!                      |\n");
    printf("                                .-------------------------------------------------------------.\n");
}


// File handling functions
void saveRestaurantsToFile()
{
    FILE* restaurantFile = fopen("restaurants.txt", "w");

    if (restaurantFile == NULL)
    {
        printf("\n\n");
        printf("                                .-------------------------------------------------------------.\n");
        printf("                                |           Error opening restaurants file for writing        |\n");
        printf("                                .-------------------------------------------------------------.\n");

        return;
    }

    Restaurant* currentRestaurant = restaurantList;

    while (currentRestaurant != NULL)
    {
        fprintf(restaurantFile, "Restaurant: %s\n", currentRestaurant->name);

        MenuItem* currentMenuItem = currentRestaurant->menu;
        while (currentMenuItem != NULL)
        {
            fprintf(restaurantFile, "  Item: %s, Price: %.2f\n", currentMenuItem->itemName, currentMenuItem->price);
            currentMenuItem = currentMenuItem->next;
        }

        fprintf(restaurantFile, "\n");

        currentRestaurant = currentRestaurant->next;
    }

    fclose(restaurantFile);
   // printf("\n\t\t\t\t\tRestaurants data saved to file.\n");
}

void loadRestaurantsFromFile()
{
    FILE* restaurantFile = fopen("restaurants.txt", "r");

    if (restaurantFile == NULL)
    {
        //printf("\t\t\t\t\tError opening restaurants file for reading\n");
        return;
    }

    char buffer[100];  // Assuming a maximum line length of 100 characters

    while (fgets(buffer, sizeof(buffer), restaurantFile) != NULL)
    {
        if (strncmp(buffer, "Restaurant:", 11) == 0)
        {
            // Extract restaurant name
            char restaurantName[50];
            sscanf(buffer, "Restaurant: %[^\n]", restaurantName);

            // Create a new restaurant
            Restaurant* newRestaurant = (Restaurant*)malloc(sizeof(Restaurant));
            strcpy(newRestaurant->name, restaurantName);
            newRestaurant->menu = NULL;
            newRestaurant->next = NULL;

            // Read menu items for the restaurant
            while (fgets(buffer, sizeof(buffer), restaurantFile) != NULL && buffer[0] != '\n')
            {
                char itemName[50];
                float price;
                sscanf(buffer, "  Item: %[^\t,], Price: %f", itemName, &price);

                // Create a new menu item
                MenuItem* newMenuItem = (MenuItem*)malloc(sizeof(MenuItem));
                strcpy(newMenuItem->itemName, itemName);
                newMenuItem->price = price;
                newMenuItem->next = NULL;

                // Add the menu item to the restaurant's menu
                if (newRestaurant->menu == NULL)
                {
                    newRestaurant->menu = newMenuItem;
                }
                else
                {
                    MenuItem* lastMenuItem = newRestaurant->menu;
                    while (lastMenuItem->next != NULL)
                    {
                        lastMenuItem = lastMenuItem->next;
                    }
                    lastMenuItem->next = newMenuItem;
                }
            }

            // Add the restaurant to the linked list
            if (restaurantList == NULL)
            {
                restaurantList = newRestaurant;
            }
            else
            {
                Restaurant* lastRestaurant = restaurantList;
                while (lastRestaurant->next != NULL)
                {
                    lastRestaurant = lastRestaurant->next;
                }
                lastRestaurant->next = newRestaurant;
            }
        }
    }

    fclose(restaurantFile);
    //printf("\n\n\n\t\t\t\t\tRestaurants data loaded from file.\n");
}


void saveUsersToFile()
{
    FILE* userFile = fopen("users.txt", "w");

    if (userFile == NULL)
    {
        return;
    }

    User* currentUser = userList;

    while (currentUser != NULL)
    {
        fprintf(userFile, "Username: %s, Password: %s, Delivery Address: %s\n",
                currentUser->username, currentUser->password, currentUser->deliveryAddress);

        currentUser = currentUser->next;
    }

    fclose(userFile);
   // printf("\n\n\t\t\t\tUsers data saved to file.\n");
}


void loadUsersFromFile()
{
    FILE* userFile = fopen("users.txt", "r");

    if (userFile == NULL)
    {
        return;
    }

    char buffer[100];  // Assuming a maximum line length of 100 characters

    while (fgets(buffer, sizeof(buffer), userFile) != NULL)
    {
        // Extract user information
        char username[20], password[20], deliveryAddress[20];
        sscanf(buffer, "Username: %s, Password: %s, Delivery Address: %[^\n]", username, password, deliveryAddress);

        // Create a new user
        User* newUser = (User*)malloc(sizeof(User));
        strcpy(newUser->username, username);
        strcpy(newUser->password, password);
        strcpy(newUser->deliveryAddress, deliveryAddress);
        newUser->next = NULL;

        // Add the user to the linked list
        if (userList == NULL)
        {
            userList = newUser;
        }
        else
        {
            User* lastUser = userList;
            while (lastUser->next != NULL)
            {
                lastUser = lastUser->next;
            }
            lastUser->next = newUser;
        }
    }

    fclose(userFile);
   // printf("\n\t\t\t\t\tUsers data loaded from file.\n");
}


void saveOrdersToFile()
{
    FILE* orderFile = fopen("orders.txt", "w");

    if (orderFile == NULL)
    {
        return;
    }

    Order* currentOrder = orderQueue;

    while (currentOrder != NULL)
    {
        fprintf(orderFile, "Restaurant: %s, Item: %s, Price: %.2f, Delivery Address: %s, Payment Method: %s\n",
                currentOrder->restaurantName, currentOrder->itemName, currentOrder->price,
                currentOrder->deliveryAddress, currentOrder->paymentMethod);

        currentOrder = currentOrder->next;
    }

    fclose(orderFile);
   // printf("\t\t\t\t\tOrders data saved to file.\n");
}


void loadOrdersFromFile()
{
    FILE* orderFile = fopen("orders.txt", "r");

    if (orderFile == NULL)
    {
        //printf("\t\t\t\t\tError opening orders file for reading.\n");
        return;
    }

    char buffer[100];  // Assuming a maximum line length of 100 characters

    while (fgets(buffer, sizeof(buffer), orderFile) != NULL)
    {
        // Extract order information
        char restaurantName[50], itemName[50], deliveryAddress[20], paymentMethod[20];
        float price;
        sscanf(buffer, "Restaurant: %49[^,], Item: %49[^,], Price: %f, Delivery Address: %19[^,], Payment Method: %19[^\n]",
               restaurantName, itemName, &price, deliveryAddress, paymentMethod);

        // Create a new order
        Order* newOrder = (Order*)malloc(sizeof(Order));
        strcpy(newOrder->restaurantName, restaurantName);
        strcpy(newOrder->itemName, itemName);
        newOrder->price = price;
        strcpy(newOrder->deliveryAddress, deliveryAddress);
        strcpy(newOrder->paymentMethod, paymentMethod);
        newOrder->next = NULL;

        // Add the order to the end of the order queue
        if (orderQueue == NULL)
        {
            orderQueue = newOrder;
        }
        else
        {
            Order* lastOrder = orderQueue;
            while (lastOrder->next != NULL)
            {
                lastOrder = lastOrder->next;
            }
            lastOrder->next = newOrder;
        }
    }

    fclose(orderFile);
    //printf("\t\t\t\t\tOrders data loaded from file.\n");
}




