#include <iostream>
#include "Course.hpp"

Course::Course(const std::string &name) : name(name)
{
	std::cout << "Course " << name << " created\n";
}
void	Course::assign(Professor* professor)
{
	responsable = professor;
}

void	Course::subscribe(Student* student)
{
	students.insert(student);
}

void	Course::setClassroom(Classroom *c)
{
	classroom = c;
}
