#include <iostream>
#include <set>
#include "Singleton.hpp"
#include "Student.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include "Form.hpp"
#include "Forms.hpp"
#include "Headmaster.hpp"
#include "Secretary.hpp"
#include "Professor.hpp"
#include "SecretarialOffice.hpp"
#include "HeadmasterOffice.hpp"

int main()
{
	Headmaster				&headmaster = Singleton<Headmaster>::getInstance();
	Secretary				&secretary = Singleton<Secretary>::getInstance();
	std::set<Student *>		&studentList = SSet<Student *>::getInstance();
	std::set<Professor *>	&profList = SSet<Professor *>::getInstance();
	std::set<Course *>		&courseList = SSet<Course *>::getInstance();
	std::set<Room *>		&roomList = SSet<Room *>::getInstance();
	
	roomList.insert(new SecretarialOffice);
	roomList.insert(new HeadmasterOffice);
	for (Room *r : roomList)
	{
		headmaster.changeRoom(r);
		secretary.changeRoom(r);
	}
	studentList.insert(new Student("s1"));
	studentList.insert(new Student("s2"));
	studentList.insert(new Student("s3"));
	profList.insert(new Professor("p1"));
	profList.insert(new Professor("p2"));
	std::cout << "\n";

	headmaster.attendClasses();
	std::cout << "\n";
	headmaster.attendClasses();
	std::cout << "\n";
	headmaster.attendClasses();
	std::cout << "\n";
	headmaster.attendClasses();
	std::cout << "\n";
	headmaster.attendClasses();
	std::cout << "\n";

	for (Student *student : studentList)
		delete student;
	for (Professor *prof : profList)
		delete prof;
	for (Course *course : courseList)
		delete course;
	for (Room *room : roomList)
		delete room;
}
