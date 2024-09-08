#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define character stats
typedef struct {
    char name[30];
    int health;
    int attack;
    int defense;
    int potions;
    char classType[20];
} Character;

// Function prototypes
void createCharacter(Character *player);
void showIntro();
void encounterGoblin(Character *player);
void encounterSorcerer(Character *player);
void combat(Character *player, const char *enemy, int enemyHealth, int enemyAttack);
int playerTurn(Character *player, const char *enemy, int *enemyHealth);
void enemyTurn(Character *player, const char *enemy, int enemyAttack);
void rest(Character *player);

int main() {
    Character player;
    createCharacter(&player);

    showIntro();

    encounterGoblin(&player); // First enemy
    if (player.health > 0) {
        rest(&player); // Player can rest and regain health
        encounterSorcerer(&player); // Final boss
    }

    if (player.health > 0) {
        printf("\nCongratulations, %s! You have saved the kingdom of Eloria!\n", player.name);
    } else {
        printf("\nYou have fallen on your quest. The kingdom of Eloria falls into darkness...\n");
    }

    return 0;
}

// Character creation
void createCharacter(Character *player) {
    printf("Welcome to the land of Eloria!\n");
    printf("Enter your name, adventurer: ");
    fgets(player->name, 30, stdin);
    player->name[strcspn(player->name, "\n")] = 0; // Remove newline

    printf("Choose your class (Warrior, Mage, Rogue): ");
    fgets(player->classType, 20, stdin);
    player->classType[strcspn(player->classType, "\n")] = 0;

    // Set initial stats based on class
    if (strcmp(player->classType, "Warrior") == 0) {
        player->health = 100;
        player->attack = 15;
        player->defense = 5;
        player->potions = 2;
    } else if (strcmp(player->classType, "Mage") == 0) {
        player->health = 70;
        player->attack = 25;
        player->defense = 3;
        player->potions = 3;
    } else if (strcmp(player->classType, "Rogue") == 0) {
        player->health = 85;
        player->attack = 20;
        player->defense = 4;
        player->potions = 2;
    } else {
        printf("Invalid class! Defaulting to Warrior.\n");
        player->health = 100;
        player->attack = 15;
        player->defense = 5;
        player->potions = 2;
        strcpy(player->classType, "Warrior");
    }

    printf("\nWelcome, %s the %s! Your adventure begins...\n\n", player->name, player->classType);
}

// Introductory story
void showIntro() {
    printf("The kingdom of Eloria is in peril.\n");
    printf("A dark sorcerer has cast a curse on the land, and only you can stop him.\n");
    printf("Your journey begins as you enter the Enchanted Forest...\n\n");
}

// First encounter: Goblin
void encounterGoblin(Character *player) {
    printf("You encounter a wild Goblin in the forest!\n");
    combat(player, "Goblin", 40, 10);
}

// Final encounter: Sorcerer
void encounterSorcerer(Character *player) {
    printf("You have reached the Dark Tower, where the sorcerer resides.\n");
    printf("The sorcerer steps forward, ready to engage in battle!\n");
    combat(player, "Dark Sorcerer", 80, 20);
}

// Turn-based Combat system
void combat(Character *player, const char *enemy, int enemyHealth, int enemyAttack) {
    while (player->health > 0 && enemyHealth > 0) {
        // Player's turn
        int action = playerTurn(player, enemy, &enemyHealth);
        if (action == 0) return; // Exit if the player decides to flee

        if (enemyHealth <= 0) {
            printf("You defeated the %s!\n\n", enemy);
            return;
        }

        // Enemy's turn
        enemyTurn(player, enemy, enemyAttack);

        if (player->health <= 0) {
            printf("You were defeated by the %s...\n\n", enemy);
            return;
        }

        printf("\nYour health: %d, %s's health: %d\n", player->health, enemy, enemyHealth);
    }
}

// Player's turn with interactive menu
int playerTurn(Character *player, const char *enemy, int *enemyHealth) {
    int choice;
    printf("\nIt's your turn! Choose an action:\n");
    printf("1. Attack\n2. Defend\n3. Use Potion (%d left)\n4. Flee\n", player->potions);
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Attack
            printf("%s attacks the %s!\n", player->name, enemy);
            *enemyHealth -= player->attack;
            printf("You dealt %d damage to the %s.\n", player->attack, enemy);
            break;
        case 2: // Defend
            printf("%s braces for an attack, reducing incoming damage!\n", player->name);
            player->defense *= 2; // Temporary defense boost
            break;
        case 3: // Use Potion
            if (player->potions > 0) {
                player->health += 20;
                player->potions--;
                printf("You used a potion and regained 20 health. Your health is now %d.\n", player->health);
            } else {
                printf("You are out of potions!\n");
            }
            break;
        case 4: // Flee
            printf("You fled from the battle!\n");
            return 0; // Return 0 to indicate the player fled
        default:
            printf("Invalid choice! You lose your turn.\n");
            break;
    }

    return 1; // Return 1 to indicate the player continues the fight
}

// Enemy's turn
void enemyTurn(Character *player, const char *enemy, int enemyAttack) {
    int damage = enemyAttack - player->defense;
    if (damage < 0) damage = 0;

    printf("The %s attacks!\n", enemy);
    player->health -= damage;
    printf("The %s dealt %d damage to you.\n", enemy, damage);

    // Reset defense after defending
    if (player->defense > 5) {
        player->defense /= 2; // Revert defense to normal
    }
}

// Rest to regain health
void rest(Character *player) {
    printf("After the battle, you rest and regain some health.\n");
    player->health += 20;
    printf("Your health is now %d.\n", player->health);
}
