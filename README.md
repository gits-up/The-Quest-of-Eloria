# The-Quest-of-Eloria
A text-based RPG game written in C. Includes character creation, a story-based setting, simple combat mechanics, and some decision-making to guide the player through a storyline.
# Storyline:
You are a young adventurer in the land of Eloria, a kingdom threatened by a dark sorcerer. The king has summoned heroes from across the realm to embark on a quest to defeat this evil. Your journey will take you through enchanted forests, ancient ruins, and treacherous dungeons.
# Main Features:
- Character creation (choose your name and class)
- Simple combat system (based on attack and health stats)
- Story progression with branching paths
# Key Features:
- **Character Creation:** The player can choose a name and class, which affects health and attack values.
- **Combat System:** The player fights enemies by reducing their health with attacks, and enemies attack back.
- **Resting:** After defeating the goblin, the player rests and regains health before facing the final boss.
- **Storyline:** The game progresses with narrative elements and battles, culminating in a final battle with the sorcerer.
# Key Features of Turn-based Combat:
- **Player's Turn Choices:** The player now chooses between attacking, defending, using a potion, or fleeing each turn:
  - **Attack:** Standard attack dealing damage to the enemy.
  - **Defend:** Temporarily boosts the player's defense to reduce damage from the next attack.
  - **Use Potion:** Heals the player if they have potions remaining.
  - **Flee:** The player can flee from battle and skip the encounter.
- **Enemy Turn:** After the player acts, the enemy attacks back, and the player’s health is reduced based on the enemy’s attack power and the player’s defense.
- **Interactive Decision-Making:** Each turn, the player must make decisions, making the combat system more engaging.
# To Compile and Run:
- Save the code to a file (e.g., rpg_game.c)
- Compile the program using a C compiler like GCC:
`gcc rpg_game.c -o rpg_game`
- Run the game:
  `./rpg_game`
  # Note:
  Currently there are two enemies: a goblin and the dark sorcerer(final boss), feel free to update more enemies!

  

 
