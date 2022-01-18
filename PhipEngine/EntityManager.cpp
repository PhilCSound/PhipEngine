#include "EntityManager.h"

std::shared_ptr<Entity> EntityManager::AddEntity(const std::string _tag)
{
	//Creating entity and increasing the total entites made and all entity vector
	auto e = std::shared_ptr<Entity>(new Entity(TotalEntities, _tag));		//TODO: REVISIT LATER
	TotalEntities++;
	EntitiesToAdd.push_back(e);
	return e;
}

EntityVector & EntityManager::GetEntities()
{
	return VectorOfEntities;
}

EntityVector & EntityManager::GetEntities(const std::string _tag)
{
	if (MapOfEntities.count(_tag) == 0)
	{
		EntityVector _vec;
		return _vec;
	}

	return MapOfEntities.at(_tag);
}

void EntityManager::Update()
{
	DestroyFlaggedEntities(VectorOfEntities);
	for (auto& _v : MapOfEntities)
		DestroyFlaggedEntities(_v.second);
	AddAllEntities();
}

void EntityManager::AddAllEntities()
{
	//First we are adding the entities in the map, this allows Tag sorting
	for (auto &e : EntitiesToAdd)
	{
		std::string _tag = e->GetTag();
		//Next we check if the map key is empty (tag) and make a new vec for it if so
		if (MapOfEntities.count(_tag) == 0)
		{
			EntityVector _entityVec;
			//_entityVec.push_back(e);
			MapOfEntities.insert(std::make_pair(_tag, _entityVec));
		}
		//Otherwise the entity vec exists for the tag and we can just add it to that as well.
		else
		{
			MapOfEntities.at(_tag).push_back(e);
		}
	}
	//Now we just need to add entities to the VectorOfEntites and clear the add entities.
	VectorOfEntities.insert(VectorOfEntities.end(), EntitiesToAdd.begin(), EntitiesToAdd.end());
	EntitiesToAdd.clear();
}

void EntityManager::DestroyFlaggedEntities(EntityVector& _vec)
{
	_vec.erase(std::remove_if(_vec.begin(), _vec.end(),
		[](std::shared_ptr<Entity> const& _ptr) {	return _ptr->FlaggedForDestruction();	})	, _vec.end());
}
