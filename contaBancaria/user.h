#ifndef USER_H
#define USER_H

#include <iostream>
using std::ostream;

class User
{
friend ostream &operator<<(ostream &, const User &) const; // Serve para pegar o extrato
public:
	User(char &, char &, char &, char &);
	~User();
	
	// Functions set
	void setName( char &);
	void setTel( char &);
	void setCpf( char &);
	void setPassword( char & );
	void setSal( int );
	
	// Functions get
	char & getName() const;
	char & getTel() const;
	char & getCpf() const;
	char & getPassword() const;
	int getSal() const;
	
	
private:
	const char name[20];
	const char tel[12];
	const char cpf[13];
	const char password[20];
	int saldo;
};

#endif
