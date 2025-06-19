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



	try
	{
		//headmaster.signForm(nullptr);
		Form	*form = secretary.createForm(FormType::NeedMoreClassroom);
		headmaster.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	
	roomList.insert(new SecretarialOffice);
	roomList.insert(new HeadmasterOffice);
	for (Room *r : roomList)
	{
			headmaster.changeRoom(r);
			secretary.changeRoom(r);
	}
	for (Room *r : roomList)
		r->printOccupants();
	
	Form	*form = secretary.createForm(FormType::NeedMoreClassroom);

	try
	{
		form->execute();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	headmaster.signForm(form);
	form->execute();

	form = secretary.createForm(FormType::NeedCourseCreation);
	
	headmaster.receiveForm(form);
	try
	{
		headmaster.signAllForms();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	for (Room *room : roomList)
	{
		try
		{
			dynamic_cast<NeedCourseCreationForm *>(form)->fill(dynamic_cast<Classroom *>(room), "wow");
			break;
		}
		catch (std::exception &e)
		{
		}
	}
	headmaster.signAllForms();
	form->execute();

	


	for (Student *student : studentList)
		delete student;
	for (Professor *prof : profList)
		delete prof;
	for (Course *course : courseList)
		delete course;
	for (Room *room : roomList)
		delete room;
}
