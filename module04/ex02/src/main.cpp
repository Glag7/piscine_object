#include <iostream>
#include <set>
#include "Singleton.hpp"
#include "Student.hpp"
#include "Staff.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include "Forms.hpp"
#include "Headmaster.hpp"
#include "Secretary.hpp"

int main()
{
	std::set<Student *>		&studentList = SSet<Student *>::getInstance();
	std::set<Staff *>		&staffList = SSet<Staff *>::getInstance();
	std::set<Course *>		&courseList = SSet<Course *>::getInstance();
	std::set<Room *>		&roomList = SSet<Room *>::getInstance();

	for (Student *student : studentList)
		delete student;
	for (Staff *staff : staffList)
		delete staff;
	for (Course *course : courseList)
		delete course;
	for (Room *room : roomList)
		delete room;
}
