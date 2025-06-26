#include <iostream>
#include <stdexcept>
#include "Course.hpp"
#include "Student.hpp"
#include "Professor.hpp"

Course::Course(const std::string &name) :
	name(name),
	responsable(nullptr)
{
	std::cout << "Course " << name << " created\n";
}

void	Course::assign(Professor* professor)
{
	if (professor != nullptr)
		std::cout << "Course " << name << " was joined by professor " << professor->getName() << "\n";
	responsable = professor;
}

void	Course::subscribe(Student* student)
{
	if (student == nullptr)
		throw std::logic_error("...");
	std::cout << "Course " << name << " was joined by student " << student->getName() << "\n";
	students.insert(student);
}

void	Course::unsubscribe(Student* student)
{
	auto it = students.find(student);

	if (it == students.end())
		throw std::logic_error("...");
	std::cout << "Course " << name << " was left by student " << student->getName() << "\n";
	students.erase(it);
}

void	Course::moveStudents(Classroom *c)
{
	for (Student *s : students)
		s->attendClass(c);
}
