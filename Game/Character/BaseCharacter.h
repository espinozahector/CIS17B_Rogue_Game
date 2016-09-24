// programmer(s): Curt Burdette

#ifndef BASECHARACTER_H
#define BASECHARACTER_H

class BaseCharacter
{
private:
	
	int hitPoints;
	int attackDamage;
	int armorRating;
	float critChance;
	const float critMultiplier = 1.2;

	/*
	inclusion of crit variables in the base class would depend
	on whether or not player character had crits.  With a hack
	n slash this seems odd.  May be better to have a second,
	charged attack.  This merits some dicussion imo.

	critMultiplier is not necessary as a variable in a scenario
	with static crit multipliers, but I included it to make it
	easier to change, and also if we decide at some point to
	have variable multipliers
	*/

public:
	
	BaseCharacter();
	~BaseCharacter();
	void setHitPoints(int);
	void getHitPoints();
	void setAttackDamage(int);
	void getAttackDamage();
	void setArmorRating(int);
	void getArmorRating();
	bool isDead() { return hitPoints >= 0; };
	void setCritChance(float);
	void getCritChance();

};
#endif // !BASECHARACTER_H

