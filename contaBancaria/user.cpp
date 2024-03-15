#include <iostream>
#include <string>
using namespace std;

#include "user.h"

User::User(string n, string telefone, string cpff, string senha, int value )
	: name(n), tel(telefone), cpf(cpff), password(senha)
{
	setSal( value );
}

User::User() : name(" "), tel(" "), cpf("0"), password(" ")
{
	setSal( 0 );
}

User::~User()
{
	cout << "Conta do usuario apagada" << endl;
}

void User::setSal( int sal )
{
	saldo = sal;
}

string User::getName() const
{
	return name;
}

string User::getTel() const
{
	return tel;
}

string User::getCpf() const
{
	return cpf;
}

string User::getPassword() const
{
	return password;
}

int User::getSal() const
{
	return saldo;
}

ostream &operator<<(ostream & output, const User & user)
{
	return output;
}

