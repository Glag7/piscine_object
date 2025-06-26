#ifndef COURSE_HPP
# define COURSE_HPP

#include <string>
#include <set>

class Student;
class Professor;
class Classroom;

class Course
{
	private:
		std::string			name;
		Professor			*responsable;
		std::set<Student *>	students;

	public:
		Course(const std::string &name);
		
		const std::string	&getName() const {return name;}
		bool				hasTeacher() const {return responsable != nullptr;}
		bool				isFull() const {return students.size() >= 2;}
		unsigned			getReqAttendance() const {return 3;}
		std::set<Student *>	&getStudents() {return students;}

		void	assign(Professor* professor);
		void	subscribe(Student* student);
		void	moveStudents(Classroom *c);
};

#endif
