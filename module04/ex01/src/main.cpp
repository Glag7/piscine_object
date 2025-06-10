#include <iostream>
#include "Singleton.hpp"
#include "Student.hpp"
#include "Staff.hpp"
#include "Course.hpp"
#include "Classroom.hpp"

#include <map>

int main()
{
	std::vector<Student>	&studentList = Singleton<std::vector<Student>>::getInstance();
	std::vector<Staff>		&staffList = Singleton<std::vector<Staff>>::getInstance();
	std::vector<Course>		&courseList = Singleton<std::vector<Course>>::getInstance();
	std::vector<Room>		&roomList = Singleton<std::vector<Room>>::getInstance();

	studentList.push_back(Student("amog"));
	staffList.push_back(Staff("us"));
	courseList.push_back(Course("impostor"));
	roomList.push_back(Classroom());
	std::cout << Singleton<std::vector<Student>>::getInstance()[0].getName() << "\n";
	std::cout << Singleton<std::vector<Staff>>::getInstance()[0].getName() << "\n";
	std::cout << Singleton<std::vector<Course>>::getInstance()[0].getName() << "\n";
	std::cout << Singleton<std::vector<Room>>::getInstance()[0].getId() << "\n";
}
