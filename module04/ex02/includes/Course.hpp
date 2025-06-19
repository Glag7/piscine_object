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
		Professor*			responsable;
		std::set<Student*>	students;
		Classroom			*classroom;

	public:
		Course(const std::string &name);
		
		const std::string	&getName() const {return name;}
		Classroom			*getRoom() const {return classroom;}

		void	assign(Professor* professor);
		void	subscribe(Student* student);
		void	setClassroom(Classroom *c);
};

#endif
