#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define character stats
typedef struct {
    char name[30];
    int health;
    int attack;
    char classType[20];
} Character;

// Function prototypes
void createCharacter(Character *player);
void showIntro();
void encounterGoblin(Character *player);
void encounterSorcerer(Character *player);
void combat(Character *player, const char *enemy, int enemyHealth, int enemyAttack);
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
    } else if (strcmp(player->classType, "Mage") == 0) {
        player->health = 70;
        player->attack = 25;
    } else if (strcmp(player->classType, "Rogue") == 0) {
        player->health = 85;
        player->attack = 20;
    } else {
        printf("Invalid class! Defaulting to Warrior.\n");
        player->health = 100;
        player->attack = 15;
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

// Combat system
void combat(Character *player, const char *enemy, int enemyHealth, int enemyAttack) {
    while (player->health > 0 && enemyHealth > 0) {
        // Player's attack
        printf("%s attacks the %s!\n", player->name, enemy);
        enemyHealth -= player->attack;
        if (enemyHealth <= 0) {
            printf("You defeated the %s!\n\n", enemy);
            return;
        }

        // Enemy's attack
        printf("The %s strikes back!\n", enemy);
        player->health -= enemyAttack;
        if (player->health <= 0) {
            printf("You were defeated by the %s...\n\n", enemy);
            return;
        }

        printf("Your health: %d, %s's health: %d\n", player->health, enemy, enemyHealth);
    }
}

// Rest to regain health
void rest(Character *player) {
    printf("After the battle, you rest and regain some health.\n");
    player->health += 20;
    printf("Your health is now %d.\n", player->health);
}

