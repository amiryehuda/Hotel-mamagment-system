#include "Room.h"

Room* CreateNewRoom(int _number, float _cost, int _available, const char* _type)
{
	Room* temp = (Room*)malloc(sizeof(Room));
	if (!temp)
	{
		free(temp);
		return NULL;
	}
	temp->number = _number;
	temp->cost_for_night = _cost;
	temp->available = _available;

	int sizeoftype = strlen(_type);
	temp->type = (char*)malloc((sizeoftype * sizeof(char)) + 1);
	if (!temp->type)
	{
		free(temp->type);
		free(temp);
		return NULL;
	}
	strcpy(temp->type, _type);
	
	return temp;
}

Room* DuplicateRoom(const Room* source)
{
	Room* temp = (Room*)malloc(sizeof(Room));
	if (!temp)
	{
		free(temp);
		return NULL;
	}
	
	temp->number = source->number;
	temp->cost_for_night = source->cost_for_night;
	temp->available = source->available;

	int sizeoftype = strlen(source->type);
	temp->type = (char*)malloc((sizeoftype * sizeof(char)) + 1);
	if (!temp->type)
	{
		free(temp->type);
		free(temp);
		return NULL;
	}
	strcpy(temp->type, source->type);

	return temp;
}

void FreeRoom(Room* rm)
{
	free(rm->type);
	free(rm);
}