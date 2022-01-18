#pragma once
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <map>
#include "Entity.h"

typedef std::vector<std::shared_ptr<Entity>> EntityVector;
typedef std::map<std::string, EntityVector> EntityMap;

class EntityManager
{
public:
	
	//Member Functions
	~EntityManager() {}
	std::shared_ptr<Entity> AddEntity(const std::string _tag);
	EntityVector& GetEntities();
	EntityVector& GetEntities(const std::string _tag);
	void Update();

private: 
	
	//Member Functions
	friend class PhipEngine;
	EntityManager() {}
	void AddAllEntities();	//This function adds all entities in the entities to add to avoid iterator invalidation 
	void DestroyFlaggedEntities(EntityVector& _vec);

	//Member Variables
	EntityVector VectorOfEntities;
	EntityVector EntitiesToAdd ;
	EntityMap MapOfEntities;
	size_t TotalEntities = 0;
};