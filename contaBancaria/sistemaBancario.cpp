#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::getline;

#include <cstdlib>
using std::system;

#include <iomanip>
using std::setw;

#include "sistemaBancario.h"
#include "user.h"

int Sistema::menu() const
{
	int choice = 0;
	while(choice < 1 && choice > 3)
	{
		system("cls");
		cout << "-----------------\n" << "1 - Entrar\n" << "2 - Cadastrar-se\n" << "3 - Sair\n" << "-----------------" << endl;
		cout << "@>> ";
		cin >> choice;
	}
	return choice;
}

bool Sistema::menuLogin() const
{
	char password[20], cpf[13];
	system("cls");
	cout << "Digite o seu CPF: " << endl;
	cout << "@>> ";
	cin >> setw(13) >> cpf;
	if(!autentication(cpf))
	{
		cout << "CPF errado, ou não cadastrado..." << endl;
		getline(cin, "");
		return false;
	}
	
	system("cls");
	cout << "Digite a sua senha: " << endl;
	cout << "@>> ";
	cin >> setw(20) >> password;
	if(!autentication(password, 1))
	{
		cout << "Senha errada, ou não cadastrado..." << endl;
		getline(cin, "");
		return false;
	}
	
	return true;
}

int Sistema::menuConta() const
{
	int choice = 0;
	while(choice < 1 && choice > 5)
	{
		system("cls");
		cout << "-----------------\n" << "1 - Mostrar Saldo\n" << "2 - Extrato\n" << "3 - Sacar\n" << "4 - Depositar\n" << "5 - Transferir\n" << "-----------------" << endl;
		cout << "@>> ";
		cin >> choice;
	}
	return choice;
}

void Sistema::showSal(User & user)
{
	system("cls");
	cout << "Saldo na Conta: R$ " << user.getSal() << ".00" << endl;
	getline(cin, "");
}

void Sistema::extrato(User & user)
{
	system("cls");
	cout << "Extrato:" << endl;
	cout << "-----------------\n";
	cout << user;
	getline(cin, "");
}

void Sistema::saque(User & user)
{
	int value = 0;
	system("cls");
	cout << "Saque:" << endl;
	cout << "-----------------\n";
	cout << "Digite o valor para sacar:" << endl;
	cout << "@>> ";
	cin >> value;
	(value < 0 ? value = value *(-1) : value = value);
	if(value > user.getSal())
	{
		cout << "Você sacou R$ " << user.getSal() << ".00" << endl;
		user.setSal( 0 );
	}
	cout << "Você sacou R$ " << value << ".00" << endl;
	user.setSal( user.getSal() - value );
	getline(cin, "");
}

void Sistema::deposito(User & user)
{
	int value = 0;
	system("cls");
	cout << "Deposito:" << endl;
	cout << "-----------------\n";
	cout << "Digite o valor para depositar:" << endl;
	cout << "@>> ";
	cin >> value;
	(value < 0 ? value = value * (-1) : value = value);
	cout << "Você depositou R$ " << value << ".00" << endl;
	user.setSal( user.getSal() + value );
	getline(cin, "");
}

void Sistema::transferir( User & user )
{
	int value = 0;
	char cpf[13];
	system("cls");
	cout << "Transferir:" << endl;
	cout << "-----------------\n";
	cout << "Digite o CPF da pessoa que deseja transferir:" << endl;
	cout << "@>> ";
	cin >> setw(13) >> cpf;
	if(!autentication(cpf))
	{
		cout << "CPF errado, ou não cadastrado..." << endl;
		getline(cin, "");
		return false;
	}
	cout << "Digite o valor para transferir: " << endl;
	cout << "@>> ";
	cin >> value;
	
}


