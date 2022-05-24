#include "Cake.hpp"

#include<iostream>



Cake::Cake():x(0)
{
}
Cake::Cake(int x)
{
	this->x = x;
}
Cake::~Cake()
{
}

AppleCake::AppleCake() :y(0)
{
}
AppleCake::AppleCake(int y)
{
	this->y = y;
}
AppleCake::~AppleCake()
{
}