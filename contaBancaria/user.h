#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User
{
friend ostream &operator<<(ostream &, const User &); // Serve para pegar o extrato
public:
	User( string , string , string , string, int );
	User();
	~User();
	
	// Functions set
//	void setName( char *);
//	void setTel( char *);
//	void setCpf( char *);
//	void setPassword( char * );
	void setSal( int );
	
	// Functions get
	string getName() const;
	string getTel() const;
	string getCpf() const;
	string getPassword() const;
	int getSal() const;
	
private:
	const string name;
	const string tel;
	const string cpf;
	const string password;
	int saldo;
};

#endif
