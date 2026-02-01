#pragma once
#include "core/BaseIncludes.h"
#include "core/QtIncludes.h"

class user
{
	static int total_users;
	int ID;

	QString fname;
	QString lname;

	int age;
	bool sex;

	QString login;
	QString password;

	QString city;
	QVector<QString> interests;
public:
	user(QString fn, QString ln, int _age, bool _sex, QString _city, QString _login, QString _pass)
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
	user(const user& u)
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

	void print()
	{
		QTextStream out(stdout);
		out << fname << " " << lname << " " << age << " " << sex << " " << ID << Qt::endl;
	}

	//GETTERS
	int getID() const { return ID; }
	int getAge() const { return age; }
	bool getSex() const { return sex; }

	QString getLogin() const { return login; }
	QString getPass() const { return password; }

	QString getFname() const { return fname; }
	QString getLname() const { return lname; }
	QString getCity() const { return city; }

	QVector<QString>& getInterests() { return interests; }

	//SETTERS
	void setID(int _id) { ID = _id; }
	void setAge(int _age) { age = _age; }
	void setSex(bool _sex) { sex = _sex; }

	void setFname(const QString& _fname) { fname = _fname; }
	void setLname(const QString& _lname) { lname = _lname; }
	void setLogin(const QString& _login) { login = _login; }
	void setPassword(const QString& _pass) { password = _pass; }
	void setCity(const QString& _city) { city = _city; }

	void addInterests(QVector<QString> ints) { for (auto& i : ints) interests.append(i); }



};

