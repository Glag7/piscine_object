#include <iostream>
#include "School.hpp"

School::School() :
	headmaster(Singleton<Headmaster>::getInstance()),
	secretary(Singleton<Secretary>::getInstance()),
	studentList(SSet<Student *>::getInstance()),
	profList(SSet<Professor *>::getInstance()),
	courseList(SSet<Course *>::getInstance()),
	roomList(SSet<Room *>::getInstance())
{	
	roomList.insert(new SecretarialOffice);
	roomList.insert(new HeadmasterOffice);
	for (Room *r : roomList)
	{
		headmaster.changeRoom(r);
		secretary.changeRoom(r);
	}
	roomList.insert(new Courtyard);
	roomList.insert(new StaffRestroom);
}

School::~School()
{
	for (Student *student : studentList)
		delete student;
	for (Professor *prof : profList)
		delete prof;
	for (Course *course : courseList)
		delete course;
	for (Room *room : roomList)
		delete room;
}

void	School::runDayRoutine()
{
	launchClasses();
	std::cout << "\n";
	headmaster.notify(Event::StartPause);
	headmaster.notify(Event::EndPause);
	std::cout << "\n";
	launchClasses();
	std::cout << "\n";
	headmaster.notify(Event::StartPause);
	std::cout << "everyone is eating on the ground\n";
	headmaster.notify(Event::EndPause);
	std::cout << "\n";
	launchClasses();
	std::cout << "\n";
	headmaster.notify(Event::StartPause);
	headmaster.notify(Event::EndPause);
	std::cout << "\n";
	launchClasses();
	std::cout << "\n";
}

void	School::launchClasses()
{
	headmaster.attendClasses();
}

void	School::requestRingBell(Event e)
{
	headmaster.notify(e);
}

void	School::recruteProfessor(const std::string &s)
{
	profList.insert(new Professor(s));
}

void	School::recruteStudent(const std::string &s)
{
	studentList.insert(new Student(s));
}

Course	*School::getCourse(const std::string &s)
{
	for (Course* c : courseList)
	{
		if (c->getName() == s)
			return c;
	}
	return nullptr;
}

std::vector<Student *>	School::getStudents()
{
	return std::vector<Student *>(studentList.begin(), studentList.end());
}

std::vector<Professor *>	School::getProfessors()
{
	return std::vector<Professor *>(profList.begin(), profList.end());
}

Headmaster	*School::getHeadmaster()
{
	return &headmaster;
}

Secretary	*School::getSecretary()
{
	return &secretary;
}

void	School::graduationCeremony()
{
	for (auto g : grad)
	{
		std::cout << "Student " << g.first->getName() << " graduated course " << g.second->getName() << "\n";
	}
	grad.clear();
}

void	School::addGrad(Student *s, Course *c)
{
	grad.push_back(std::make_pair(s, c));
}
