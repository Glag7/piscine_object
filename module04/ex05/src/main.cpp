#include <iostream>
#include "Singleton.hpp"
#include "School.hpp"

int main()
{
	School	&school = Singleton<School>::getInstance();
	std::cout << "\n";

	school.recruteStudent("s1");
	school.recruteStudent("s2");
	school.recruteStudent("s3");
	school.recruteProfessor("p1");
	school.recruteProfessor("p2");
	std::cout << "\n";
	school.runDayRoutine();
	school.graduationCeremony();
}
