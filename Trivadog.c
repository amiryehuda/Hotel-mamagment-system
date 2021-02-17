// Name: Amir Yehuda  ID:307966499

#include "Trivadog.h"

Trivadog* AddHostel(Trivadog* td, const Hostel* ht)
{
	// if trivadog -> NULL
	if (td == NULL)
	{
		Trivadog* newTrivadog = (Trivadog*)malloc(sizeof(Trivadog));
		if (!newTrivadog)
		{
			free(newTrivadog);
			return NULL;
		}
		newTrivadog->hostels = (Hostel**)malloc(sizeof(Hostel*));
		if (!newTrivadog->hostels)
		{
			free(newTrivadog->hostels);
			free(newTrivadog);
			return NULL;
		}
		newTrivadog->hostels[0] = DuplicateHostel(ht);

		newTrivadog->num_of_hostels = 1;

		return newTrivadog;
	}

	// if trivadog exist and the room exist

	for (int i = 0; i < td->num_of_hostels; i++)
	{
		if (strcmp(td->hostels[i]->hostel_name, ht->hostel_name) == 0)
		{
			return td;
		}
	}

	// if trivadog exist and the room not exist

	td->num_of_hostels += 1;

	td->hostels = (Hostel**)realloc(td->hostels, td->num_of_hostels * sizeof(Hostel*));
	if (!td->hostels)
	{
		free(td->hostels);
		return NULL;
	}
	td->hostels[td->num_of_hostels - 1] = DuplicateHostel(ht);

	return td;

}

void FreeTrivadog(Trivadog* td)
{
	for (int i = 0; i < td->num_of_hostels; i++)
		FreeHostel(td->hostels[i]);
	free(td);
}

int	GetTotalAvailableRooms(Trivadog* td, const char* type)
{
	int count = 0;
	for (int i = 0; i < td->num_of_hostels; i++)
	{
		for (int j = 0; j < td->hostels[i]->num_of_rooms; j++)
		{
			if (strcmp(td->hostels[i]->rooms[j]->type, type) == 0)
			{
				count++;
			}
		}
	}
	return count;
}

int* GetTotalAvailableRoomsInArr(Trivadog* td, char** arr_type, int size)
{
	int* availableArr = (int*)malloc(size * sizeof(int));
	if (!availableArr)
	{
		free(availableArr);
		return NULL;
	}

	for (int i = 0; i < size; i++)
	{
		availableArr[i] = GetTotalAvailableRooms(td, arr_type[i]);
	}

	return availableArr;
}

void SortByName(Trivadog* td)
{
	Hostel* temp = (Hostel*)malloc(sizeof(Hostel));
	if (!temp)
	{
		free(temp);
		return NULL;
	}

	for (int i = td->num_of_hostels; i > 0; i--)
	{
		for (int k = 0; k < i - 1; k++)
		{
			if (strcmp(td->hostels[k]->hostel_name, td->hostels[k + 1]->hostel_name) > 0)
			{
				Hostel* temp = DuplicateHostel(td->hostels[k]);
				td->hostels[k] = DuplicateHostel(td->hostels[k + 1]);
				td->hostels[k + 1] = DuplicateHostel(temp);
			} 
		}
	}
}

void SortByRate(Trivadog* td)
{
	Hostel* temp = (Hostel*)malloc(sizeof(Hostel));
	if (!temp)
	{
		free(temp);
		return NULL;
	}

	for (int i = 0; i < td->num_of_hostels - 1; i++)
	{
		for (int k = i + 1; k < td->num_of_hostels; k++)
		{
			if (td->hostels[i]->rate < td->hostels[k]->rate)
			{
				temp = DuplicateHostel(td->hostels[i]);
				td->hostels[i] = DuplicateHostel(td->hostels[k]);
				td->hostels[k] = DuplicateHostel(temp);
			}
		}
	}
}