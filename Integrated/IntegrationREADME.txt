Integration V_1 Notes
---------------------

All character classes from the character team have been moved over to map.

Player and PJock classes from character team have been integrated into the
	map team's Player class to form a single class.  This class is now
	a sub-class of character team's Character class.

Character team Inventory and Item classes have not been moved over to the
	integrated form.  All references to them in the character classes
	have been commented out.  Once/if the Inventory and Item classes
 	are serviceable, it should be easy to move them over and take the
        relevant character class code out of comment.

Character enemy classes are currently non-functioning.  Spawning of enemies
	needs to be moved over to the Game and Room objects.

I have added two slots to StatChild: updateStats and updateDisplay. These
	need some updating.  One is intended to update stats that will
	change constantly like health and xp.  The other is for stats that
	should change only when levelling. Currently they're mixed together.

Those slots' paired signals have been added to Player.  They are playToStat
 	and playLvlUpdate.  The Player class and StatChild are now connected.
	All updating currently taking place is for test purposes only and
	will need to be changed for actual gameplay.  Test code is marked
	clearly in comments.

The test button and test code have been removed from the StatChild object.

On my end, the game crashes any time the player attempts to enter a door.  I
	don't know if I did anything to make matters worse, but the problem
	existed before I made any changes.
	