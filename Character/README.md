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
	
	*Music Major: Triangle instrument
		- Role: AOE Damage class
		- Attack1: Throws metal rod projectile (Bullet projectile)
		- Attack2: Play triangle (Sends out a sound AOE attack)
	*Jock: Football/Baseball player
		- Role: Melee class
		- Attack1: Swing bat
		- Attack2: Charge enemies with tackle dummy
	*Cs Major: Programmer
		- Role: High single point damage class
		- Attack1: Syntax Error (Coded Bullet projectile)
		- Attack2: Logic Error (Whips mouse in a line directly ahead of him)

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
		-1=empty
		0=head
		1=torso
		2=legs
		3=feet
		4=left weapon
		5=right weapon
  	*Name
	*Damage
	*Armor
	*Crit
-Mechanics:

	*Holds x and y coordinates for spawn positioning
  	*Contains item image
	
-Items:

	*Music Major
		- 0 = Marching cap
		- 1 = Uniform
		- 2 = Slacks
		- 3 = Fancy shoes
		- 4 = Metal rod
		- 5 = Triangle
	*Jock
		- 0 = Helmet
		- 1 = Padded Jersey
		- 2 = Thigh pads
		- 3 = Cleats
		- 4 = Bat
		- 5 = Tackle Dummy
	*Programmer
		- 0 = Glasses
		- 1 = Hoodie
		- 2 = Jeans
		- 3 = Sneakers
		- 4 = Computer
		- 5 = Mouse
		

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





