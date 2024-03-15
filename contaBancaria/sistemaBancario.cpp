#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "sistemaBancario.h"
#include "user.h"

int Sistema::menu() const
{
	int choice = 0;
	while(choice < 1 || choice > 3)
	{
		system("cls");
		cout << "-----------------\n" << "1 - Entrar\n" << "2 - Cadastrar\n" << "3 - Sair\n" << "-----------------" << endl;
		cout << "@>> ";
		cin >> choice;
	}
	return choice;
}

bool Sistema::menuLogin(User ** account) const
{
	string password, cpf;
	system("cls");
	cout << "Digite o seu CPF: " << endl;
	cout << "@>> ";
	cin >> setw(13) >> cpf;
	User user = autenticationCPF(cpf);
	if(user.getCpf() == "0")
	{
		cout << "CPF errado, ou nao cadastrado..." << endl;
		{
			string temp;
			getline(cin, temp);
		}
		return false;
	}
	
	cout << "Digite a sua senha: " << endl;
	cout << "@>> ";
	cin >> setw(20) >> password;
	if(user.getPassword() == " ")
	{
		cout << "Senha errada, ou nao cadastrado..." << endl;
		{
			string temp;
			getline(cin, temp);
		}
		return false;
	}
	User *acc = new User(user);
	*account = acc; 
	return true;
}

void Sistema::cadastro()
{
	string name, tel, cpf, password;
	system("cls");
	cout << "Cadastro:" << endl;
	cout << "-----------------\n";
	cout << "Nome: " << endl;
	cout << "@>> ";
	cin >> setw(20) >> name;
	cout << "Telefone: " << endl;
	cout << "@>> ";
	cin >> setw(12) >> tel;
	cout << "CPF: " << endl;
	cout << "@>> ";
	cin >> setw(13) >> cpf;
	cout << "SENHA: " << endl;
	cout << "@>> ";
	cin >> setw(20) >> password;
	User cad(name, tel, cpf, password, 0);
	inserirUser(cad);
	cout << "Cadastro realizado com sucesso..." << endl;
	{
		string temp;
		getline(cin, temp);
	}
}

int Sistema::menuConta() const
{
	int choice = 0;
	while(choice < 1 || choice > 6)
	{
		system("cls");
		cout << "-----------------\n" << "1 - Mostrar Saldo\n" << "2 - Extrato\n" << "3 - Sacar\n" << "4 - Depositar\n" << "5 - Transferir\n" << "6 - Sair\n" << "-----------------" << endl;
		cout << "@>> ";
		cin >> choice;
	}
	return choice;
}

void Sistema::showSal(User & user) const 
{
	system("cls");
	cout << "Saldo na Conta: R$ " << user.getSal() << ".00" << endl;
	{
		string temp;
		getline(cin, temp);
		getline(cin, temp);
	}
}

void Sistema::extrato(User & user) const
{
	system("cls");
	cout << "Extrato:" << endl;
	cout << "-----------------\n";
	cout << user;
	{
		string temp;
		getline(cin, temp);
	}
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
	}else
	{
		cout << "Você sacou R$ " << value << ".00" << endl;
		user.setSal( user.getSal() - value );
	}
	{
		string temp;
		getline(cin, temp);
		getline(cin, temp);
	}
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
	{
		string temp;
		getline(cin, temp);
		getline(cin, temp);
	}
}

bool Sistema::transferir( User & user )
{
	int value = 0;
	char cpf[13];
	system("cls");
	cout << "Transferir:" << endl;
	cout << "-----------------\n";
	cout << "Digite o CPF da pessoa que deseja transferir:" << endl;
	cout << "@>> ";
	cin >> setw(13) >> cpf;
	User alvo = autenticationCPF(cpf);
	if(user.getCpf() == "0")
	{
		cout << "CPF errado, ou nao cadastrado..." << endl;
		{
			string temp;
			getline(cin, temp);
		}
		return false;
	}
	cout << "Digite o valor para transferir: " << endl;
	cout << "@>> ";
	cin >> value;
	
	// Fazer alguma coisa aqui...
	
	return true;
}



void Sistema::inserirUser(User & user)
{
	ofstream f;
	f.open("users.txt", ios::app);
	if(f.is_open())
	{
		f << user.getName() << " " << user.getTel() << " " << user.getCpf() << " " << user.getPassword() << " " << user.getSal() << endl;
	} else
		cerr << "Erro...";
	
	f.close();
}

User Sistema::autenticationCPF(string alvo) const
{
	ifstream file;
	file.open("users.txt");
	if(file.is_open())
	{
		string line;
		while(getline(file, line))
		{
			int posI, posF, item = 2;
			for(int i = 0; line[i] != '\0';i++)
			{
				if(item == 0)
				{
					item--;
					posI = i;
				}
				
				if(line[i] == ' ')
					item--;
					
				if(item == -2 || line[i+1] == '\0')
				{
					posF = i-1;
					break;
				}
			}	
			
			bool equal = true;
			int i = 0, f = alvo.size()-1;
			if(posF - posI != f)
				equal = false;
				
			while(posI != posF && equal)
			{
				if(line[posI] != alvo[i])
					equal = false;
				posI++;
				i++;
			}
			if(equal)
			{
				file.close();
				int posI = 0, posF = 0, j = 0;
				string info[5];
				for(int i = 0; line[i] != '\0'; i++ )
				{
					if(line[i] == ' ')
					{
						info[j] = subString(line, posI, posF);
						j++;
						posI = posF + 1;
					}
					posF++;
				}
				info[4] = subString(line, posI, posF);
				return User(info[0], info[1], info[2], info[3], atoi(info[4].c_str()));
			}
		}
		return User();
	} else
		cerr << "Erro...";
}

string Sistema::subString(string s, int i, int f) const
{
	string sub = "";
	for(;i < f; i++ )
	{
		sub += s[i];
	}
	return sub;
}

int Sistema::insertValue()
{	
}
