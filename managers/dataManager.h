#pragma once
#include "core/QtIncludes.h"
#include "core/BaseIncludes.h"
#include "user_class.h"

class dataManager : QObject
{
	Q_OBJECT
private:
	map<int, user>* users;
	dataManager() : users(new map<int, user>()) {}
	dataManager(const dataManager&) = delete;

public:
	static dataManager& getManager();
	//GETTERS
	map<int, user> get_users();

	//SETTERS
	void set_users(map<int, user>& u);

public:// фунции работы с данными
	bool check_login(QString l);

};