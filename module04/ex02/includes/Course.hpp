#ifndef COURSE_HPP
# define COURSE_HPP

#include <string>
#include <vector>

class Student;
class Professor;

class Course
{
	private:
		std::string				_name;
		Professor*				_responsable;
		std::vector<Student*>	_students;
		int						_numberOfClassToGraduate;
		int						_maximumNumberOfStudent;

	public:
		Course(const std::string &name);
		
		const std::string	&getName() {return _name;}

		void	assign(Professor* professor);
		void	subscribe(Student* student);
};

#endif
