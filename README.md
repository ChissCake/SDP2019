# SDP2019
Student Development Project
The game has many functions but relies on class/object systems to run. As well as many user functions.

The Player class/object has variables that track the health, max health, level, experience points, level up to cap, the stats – which have been divided into health, strength, defense, and speed, the number of health potions, and number kills assigned to the object. The member functions of this class include getter and setter functions for each variable, but also a level up function which interacts with the experience, exp cap, stats, and level, to increase the stats of the player object every time the level up cap is reached and reset with a new level cap each level. There is also a function that can adjust the value individual skills by input so that there is variety and customizability.

The Enemy class uses variables to track the health, name,  statistics, unique dialogue, and experience that’s given to the player when the enemy dies for the enemy object. This class is limited to setters and getters, but also has a function which decreases the health of the enemy when called upon. The Enemy class also relies upon another function which randomly picks an enemy from predefined enemies, and creates a new enemy object which the user fights.

The NPC class is more simple than the other 2 class systems. It’s variables keep track of the name and the dialogue assigned to the NPCs, and only has getters and setters for its member functions.

In addition to class systems, the program also relies heavily on user-created functions that allow the game to run and have the objects interact with one another.

The Random Encounter function has 2 variables. a variable to store a random value and an arbitrary variable to store the value of another user function. The function uses the random value to determine whether or not an enemy appears by using the combat function. The combat function returns a value, and that value is in turn returned by the Random Encounter function. If the function returns a 0, the player is not dead, and if the function returns a 1, the player has run out of health and died, triggering the game_end function and sending the user back to the main menu.

The combat function is a function that relies on the enemy pick function which randomly generates an enemy which the player fights against, the player turn function, the enemy turn function, and a tick system that’s reliant on the user’s and enemy’s speed stat, and returns that value to the random encounter function. The function uses a for loop to initialize a counter. The player and enemy attack every time that the tick aligns with a value created by 25 subtracted by the speed stat. When it aligns it calls the player turn function or the enemy turn function. Based on the return value, the combat function continues until the player flees, dies, or kills the enemy at which point the exp from the enemy is given to the player. When any of the outcomes occur, it returns an integer value.

The player turn function gives the player four options, each of which consumes a turn. The player can choose to attack, which inflicts damage upon the enemy, defense, which reduces damage taken by the enemy next turn by raising the defense stat in the combat function, use a potion which decreases the number of potions and increases the user’s health by 4, or attempt to flee. If the player’s speed is twice that of the enemy’s, then the player can automatically flee. However, if it is greater than the enemy speed, but not by twice, then the player has a 66%(2/3) chance to flee. If the player’s speed is less than the enemy’s speed, the player has a 16%(1/6) chance to flee. If the user flees or kills the enemy, the function returns 3 and 1 respectively. However, if none of these conditions are fulfilled, then the function returns a 0. If the player chose to defend, the function returns a 2. This function utilizes ICONS to determine user input.

The enemy turn function randomly chooses to heal or attack. If the enemy’s health is below 10, then the enemy has a 25% chance to heal 4 health. However, the Enemy can still choose to attack. The attack damage is universally controlled by the object’s strength stat. The damage is calculated by the defending defense stat subtracted by the attacking strength stat.  If the player dies, then the function returns a 5. If the player lives, the function returns a 4.

The pick Enemy function chooses between different predesigned enemies and generates an enemy object with the randomly selected stats. The variables stored are the name, stats, and unique dialogue assigned to the predesigned enemies.

The movement function prompts the user to pick one of 4 directions to move in based on the input parameters. Based on the direction, the function returns a character which is the first letter of the cardinal direction that was chosen. This function utilizes ICONS to determine user input.

The player action function prompts the user to interact with an NPC if there is one present, open the in-game menu, or to use the movement function which determines where the player then decides to move. This function utilizes ICONS to determine user input.

The in-game menu function displays all the statistics that are assigned to the player, and either resume or quit to the main menu based on the user’s input. This function utilizes ICONS to determine user input.

The game function is the main menu which uses ICONS to determine user input whether to start a new game, see the statistics, or see the credits for the game.

The gameplay function uses the return values of the movement function and a switch case to determine which room the user then enters.

The game over function displays a game over message if the user dies or reaches the end of the game.

All the room functions are representations of the physical rooms that the user explores. They all call upon the player action function and movement function to determine the return value of the movement function and then returns a value to the gameplay function.
