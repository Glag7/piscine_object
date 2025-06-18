#include <iostream>
#include "Singleton.hpp"
#include "Student.hpp"
#include "Staff.hpp"
#include "Course.hpp"
#include "Classroom.hpp"

#include <map>

int main()
{
	std::vector<Student>	&studentList = SVector<Student>::getInstance();
	std::vector<Staff>		&staffList = SVector<Staff>::getInstance();
	std::vector<Course>		&courseList = SVector<Course>::getInstance();
	std::vector<Room>		&roomList = SVector<Room>::getInstance();

	studentList.push_back(Student("amog"));
	staffList.push_back(Staff("us"));
	courseList.push_back(Course("impostor"));
	roomList.push_back(Classroom());
	std::cout << SVector<Student>::getInstance()[0].getName() << "\n";
	std::cout << SVector<Staff>::getInstance()[0].getName() << "\n";
	std::cout << SVector<Course>::getInstance()[0].getName() << "\n";
	std::cout << SVector<Room>::getInstance()[0].getId() << "\n";
}
