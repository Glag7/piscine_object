#include "Room.hpp"

long long	Room::globalId = 0;

Room::Room() : id(Room::globalId++)
{
}
