#pragma once
#include "core/BaseIncludes.h"
#include "core/QtIncludes.h"

class user
{
	static int total_users;
	//ЛИЧНЫЕ ДАННЫЕ
	int ID;

	QString fname;
	QString lname;

	int age;
	bool sex;

	QString login;
	QString password;

	QString city;
	QVector<QString> interests;

	//ДАННЫЕ ПАРТНЕРА
	int p_age;
	int p_sex;
	QString p_city;

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

		p_age = -1;
		p_sex = 2;
		p_city = "none";

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

		p_age = -1;
		p_sex = 2;
		p_city = "none";
	}
	user()
	{

	}

	void print()
	{
		QTextStream out(stdout);
		out << "Имя: " << fname <<  " |Фамилия: " << lname << " |Возраст: " << age << " |Пол: " << sex << " |Логин: " << login << " |Пароль: " << password << Qt::endl;
	}
	void print_partner()
	{
		QTextStream out(stdout);
		out << "Пол: " << p_sex << " |Возраст: " << p_age << " |Город: " << p_city << Qt::endl;
	}
	void print_int()
	{
		QTextStream out(stdout);
		for (QString it : interests)
		{
			out << it << " ";
		}
		out << Qt::endl;
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

	QVector<QString> getInterests() const { return interests; }

	int getPAge() const { return p_age; }
	int getPSex() const { return p_sex; }
	QString getPCity() const { return p_city; }

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

	void setPAge(int age) { p_age = age; }
	void setPSex(int sex) { p_sex = sex; }
	void setPCity(const QString _city) { p_city = _city; }
	
};

