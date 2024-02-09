#ifndef SISTEMA_H
#define SISTEMA_H

#include "user.h"

class Sistema
{
public:
	int menu() const;
	
	// Entrar
	bool menuLogin() const;
	int menuConta() const;
	void showSal(User &) const;
	void extrato(User &) const;
	void saque(User &);
	void deposito(User &);
	bool transferir(User &);
	
	// Cadastro
	void cadastro();
	void inserirUser();
private:
	bool autentication(char &) const;
	bool autentication(char &, int) const;
	int insertValue();
};

#endif
