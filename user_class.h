#pragma once
#include "core/BaseIncludes.h"

class user
{
	static int total_users;
	int ID;

	string fname;
	string lname;

	int age;
	bool sex;

	string login;
	string password;

	string city;
	vector<string> interests;
public:
	user(string fn, string ln, int _age, bool _sex, string _city, string _login, string _pass)
	{
		fname = fn;
		lname = ln;
		age = _age;
		sex = _sex;
		city = _city;

		ID = ++total_users;

		login = _login;
		password = _pass;

	}
	user(user& u)
	{
		fname = u.fname;
		lname = u.lname;
		age = u.age;
		sex = u.sex;
		city = u.city;
		login = u.login;
		password = u.password;
		ID = u.ID;
	}
	user()
	{

	}

	//GETTERS
	int getID() const { return ID; }
	int getAge() const { return age; }
	bool getSex() const { return sex; }

	string getLogin() const { return login; }
	string getPass() const { return password; }

	string getFname() const { return fname; }
	string getLname() const { return lname; }
	string getCity() const { return city; }

	vector<string> getInterests() const { return interests; }

	//SETTERS
	void setID(int _id) { ID = _id; }
	void setAge(int _age) { age = _age; }
	void setSex(bool _sex) { sex = _sex; }

	void setFname(const string& _fname) { fname = _fname; }
	void setLname(const string& _lname) { lname = _lname; }
	void setLogin(const string& _login) { login = _login; }
	void setPassword(const string& _pass) { password = _pass; }
	void setCity(const string& _city) { city = _city; }



};

