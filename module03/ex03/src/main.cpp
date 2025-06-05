#include <iostream>
#include "EmployeeManager.hpp"
#include "Apprentice.hpp"
#include "ContractEmployee.hpp"
#include "TempWorker.hpp"

int	main()
{
	EmployeeManager		overseer;
	Apprentice			bob("bob", 10);
	ContractEmployee	pedro("pedro", 20);
	TempWorker			joe("joe", 30);

	overseer.addEmployee(&bob);
	overseer.addEmployee(&pedro);
	overseer.addEmployee(&joe);
	overseer.executeWorkDay();
	overseer.calculatePayroll();
	std::cout << "\n";
	joe.addWorkedHours(8);
	pedro.addUnworkedHours(8);
	bob.addWorkedHours(8);
	overseer.executeWorkDay();
	overseer.calculatePayroll();
	std::cout << "\n";
	joe.addWorkedHours(0);
	pedro.addUnworkedHours(1);
	bob.addUnworkedHours(3);
	overseer.executeWorkDay();
	overseer.calculatePayroll();
	std::cout << "\n";
	overseer.removeEmployee(&joe);
	overseer.executeWorkDay();
	overseer.calculatePayroll();
}
