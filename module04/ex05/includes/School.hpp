#ifndef SCHOOL_HPP
# define SCHOOL_HPP

#include <vector>
#include <set>
#include "Singleton.hpp"
#include "Student.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include "Form.hpp"
#include "Headmaster.hpp"
#include "Secretary.hpp"
#include "Professor.hpp"
#include "SecretarialOffice.hpp"
#include "HeadmasterOffice.hpp"
#include "Bell.hpp"
#include "Courtyard.hpp"
#include "StaffRestroom.hpp"

class School
{
	private:
		Headmaster									&headmaster;
		Secretary									&secretary;
		std::set<Student *>							&studentList;
		std::set<Professor *>						&profList;
		std::set<Course *>							&courseList; 
		std::set<Room *>							&roomList;
		std::vector<std::pair<Student *, Course *>>	grad;

	public:
		School();
		~School();

		void						runDayRoutine();
		void						launchClasses();
		void						requestRingBell(Event e);
		void						recruteProfessor(const std::string &s);
		void						recruteStudent(const std::string &s);
		Course						*getCourse(const std::string &s);
		std::vector<Student *>		getStudents();
		std::vector<Professor *>	getProfessors();
		Headmaster					*getHeadmaster();
		Secretary					*getSecretary();
		void						graduationCeremony();
		void						addGrad(Student *s, Course *c);
};

#endif
