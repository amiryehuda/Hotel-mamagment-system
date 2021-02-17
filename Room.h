#pragma once
#ifndef ROOM_H
#define ROOM_H
//-----------------------------------------------------------------------------------------------//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-----------------------------------------------------------------------------------------------//
typedef struct Room
{
	int		number; 			//the room number
	float	cost_for_night; 	//how much does the room cost per night?
	int		available;			//is the room available now?
	char* type;				//room type - free text
} Room;
//-----------------------------------------------------------------------------------------------//
Room* CreateNewRoom(int _number, float _cost, int _available, const char* _type);
Room* DuplicateRoom(const Room* source);
void	FreeRoom(Room* rm);
//-----------------------------------------------------------------------------------------------//
void printRoom(Room* r);

#endif 