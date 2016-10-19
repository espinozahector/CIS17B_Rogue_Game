# CIS17B_Rogue_Game
RCC Fall 2016 

Checklist
===============================
* [X]Item class
* [X]Inv class
* [X]Character class
* [ ]Player class
* [ ]Student classes
* [ ]Enemy classes

Game Characters and Items
===============================
Character goals
-------------------------------
Player

-A functioning class that allows players to interact with their environment.

-Players should be able to:

	*Move
	*Attack
	*Alternative attack
	*Take & equip items
	*Get experience
	*Level up
-Mechanics:

	*Contains coordinates for player positioning
	*Retrieves experience from enemy object
  	*Player class can be inherited to create occupation types
  	*Renders object in class
	
-Occupations:
	
	*Music Major: High single target damage ranged class
		- Skills: 
	*Jock: Melee tank class
		- Skills:  
	*Cs Major: AOE Mage class
		- Skills:

Enemy

-The enemy class for the player to combat against.

-Enemies should be able to:

	*Move through an obstacle filled environment.
	*Track player movement
	*Attack the player(with two attacks)
	*Drop items
	*Grant experience
	*Scale in difficulty based on player level
-Mechanics:

	*Enemy class can be inherited to generate enemy types
  	*Renders object in class
	~~This can be polymorphed for different enemy types

Items

-Item class contains the values and images for item information

-Item Stats:

	*Item ID#
  	*Name
	*Damage
	*Armor
	*Crit
-Mechanics:

	*Holds x and y coordinates for spawn positioning
  	*Contains item image

Inventory

-Inventory class stores Item information

-Mechanics:

	*Declarable size for multifunctionality
	*To be used for Player inventory as well as enemy and chest drops.
	*Generate a random inventory of items
	~~Items scale along with level
	~~Generates suffixes and prefixes from a text file to append to the name
  	~~Generates weapon or clothing name based on player class.
	
===============================





