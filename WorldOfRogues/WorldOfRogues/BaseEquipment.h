#pragma once
#include <string>
class Helmet;
class Platebody;
class Platelegs;
class Shield;
class Weapon;
class BaseEquipment
{
public:
	BaseEquipment(void);

	void setHelmet(Helmet* helmet);
	void setPlatebody(Platebody* platebody);
	void setPlatelegs(Platelegs* platelegs);
	void setShield(Shield* shield);
	void setWeapon(Weapon* weapon);

	Helmet* getHelmet();
	Platebody* getPlatebody();
	Platelegs* getPlatelegs();
	Shield* getShield();
	Weapon* getWeapon();

	std::string toString();

	~BaseEquipment(void);

private:
	Helmet* helmet;
	Platebody* platebody;
	Platelegs* platelegs;
	Shield* shield;

	Weapon* weapon;

};

