#include <iostream>
using namespace std;

#include "user.h"

User::User(char & n, char & telefone, char & cpff, char & senha)
	: nome(n), tel(telefone), cpf(cpff), password(senha)
{
	setSal( 0 );
}

User::~User()
{
	cout << "Conta do usuario apagada" << endl;
}


