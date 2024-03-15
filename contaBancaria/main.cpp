#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

#include "sistemaBancario.h"
#include "user.h"

int main()
{
	Sistema sistema;
//	User user1("David", "1171231", "999", "7638920536");
//	cout << user1.getName() << " " << user1.getTel() << " " << user1.getCpf() << " " << user1.getPassword() << " " << user1.getSal() << endl;
//	sistema.inserirUser(user1);
//	int a;
//	cin >> a;
	int menu = sistema.menu();
	cout << "\n" << menu << endl;
	if(menu == 1)
	{
		User *account;
		if(sistema.menuLogin(&account))
		{
			int option = 0;
			while(option != 6)
			{
				int option = sistema.menuConta();
				if(option == 1) sistema.showSal(*account);
				else if(option == 2) sistema.extrato(*account);
				else if(option == 3) sistema.saque(*account);
				else if(option == 4) sistema.deposito(*account);
				else if(option == 5) sistema.transferir(*account);
			}
		}
	}
	else if(menu == 2)
		sistema.cadastro();
	return 1;
}
