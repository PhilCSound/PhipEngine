#pragma once
#include <string>
#include <memory>

//Entitys just constain a pointer to all Component types, but only one of each.
class Entity
{
public:
	
	//Member Functions
	const size_t GetID()				{ return ID; }
	const std::string GetTag()			{ return Tag; }
	const bool FlaggedForDestruction()	{ return DestroyFlag; }
	void FlagForDestruction()			{ DestroyFlag = true; }

private:

	//Member Functions
	friend class EntityManager;				//By making Entity manager a friend, we stop making entitys outside manager.
	Entity(size_t _id, const std::string& _tag) {}	

	//Member Variables
	const size_t ID = 0;				//ID is a unique identifier for an entity.
	const std::string Tag = "Default";	//Tag is a string that will allow us to group similar obj's together.
	bool DestroyFlag = false;			//DestroyFlag will let us flag entitys for destroying later.

};