#define _CRT_SECURE_NO_WARNINGS
#include "Hostel.h"

Hostel* AddRoom(Hostel* ht, const  Room* room)
{
	//The room does not exist
	if (ht == NULL)
	{
		Hostel* newHostel = (Hostel*)malloc(sizeof(Hostel));
		if (!newHostel)
		{
			free(newHostel);
			return NULL;
		}

		newHostel->rooms = (Room**)malloc(sizeof(Room*));
		if (!newHostel->rooms)
		{
			free(newHostel->rooms);
			free(newHostel);
			return NULL;
		}
		
		newHostel->rooms[0] = DuplicateRoom(room);


		newHostel->hostel_name = (char*)malloc((strlen("Unknown Hostel") * sizeof(char)) + 1);          //strlen("Unknown Hostel")
		if (!newHostel->hostel_name)
		{
			free(newHostel->hostel_name);
			free(newHostel->rooms);
			free(newHostel);
			return NULL;
		}
		strcpy(newHostel->hostel_name, "Unknown Hostel");
		newHostel->rate = 0;
		newHostel->num_of_rooms = 1;

		return newHostel;
	}

	//Room number is the same

	int i;
	for (i = 0; i < ht->num_of_rooms; i++)
	{
		if (ht->rooms[i]->number == room->number)
		{
			ht->rooms[i] = DuplicateRoom(room);
			return ht;
		}
	}

	//Room number not found
	ht->num_of_rooms += 1;

	ht->rooms = (Room**)realloc(ht->rooms, ((ht->num_of_rooms) * sizeof(Room*)));
	if (!ht->rooms)
	{
		free(ht->rooms);
		return NULL;
	}

	ht->rooms[ht->num_of_rooms - 1] = DuplicateRoom(room);
	
	return ht;
}

Hostel* DuplicateHostel(const Hostel* source)
{
	Hostel* tempHostel = (Hostel*)malloc(sizeof(Hostel));
	if (!tempHostel)
	{
		free(tempHostel);
		return NULL;
	}
	tempHostel->rooms = (Room**)malloc(source->num_of_rooms * sizeof(Room*));
	if (!tempHostel->rooms)
	{
		free(tempHostel->rooms);
		free(tempHostel);
		return NULL;
	}

	tempHostel->hostel_name = (char*)malloc((strlen(source->hostel_name) * sizeof(char)) + 1); 
	if (!tempHostel->hostel_name)
	{
		free(tempHostel->hostel_name);
		free(tempHostel->rooms);
		free(tempHostel);
		return NULL;
	}
	strcpy(tempHostel->hostel_name, source->hostel_name); //copy hostel name
	//tempHostel->hostel_name = _strdup(source->hostel_name); 

	for (int i = 0; i < source->num_of_rooms; i++) //copy all rooms
	{
		tempHostel->rooms[i] = DuplicateRoom(source->rooms[i]);
	}

	tempHostel->num_of_rooms = source->num_of_rooms;
	tempHostel->rate = source->rate;

	return tempHostel;
}

int	GetAvailableRooms(const Hostel* ht, const char* type)
{
	int count = 0;
	for (int i = 0; i < ht->num_of_rooms; i++)
	{
		if ((ht->rooms[i]->type == type)&&(ht->rooms[i]->available == 1))
		{
			count++;
		}
	}
	return count;
}

void FreeHostel(Hostel* ht)
{

	for (int i = 0; i < ht->num_of_rooms; i++)
	{
		FreeRoom(ht->rooms[i]);
	}
	free(ht->rooms);
	free(ht->hostel_name);
	free(ht);
}