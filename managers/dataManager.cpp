#include "managers/dataManager.h"

dataManager& dataManager::getManager()
{
	static dataManager dMng; // создать единственный менеджер
	return dMng;
}

map<int, user> dataManager::get_users()
{
	return *users;
}

void dataManager::set_users(map<int, user>& u)
{
	for (auto it = u.begin(); it != u.end(); ++it)
	{
		users->insert(*it);
	}

}

bool dataManager::check_login(QString l)
{// истина, если уже есть; ложь, если еще нет
	for (auto it = users->begin(); it != users->end(); ++it)
	{
		if (it->second.getLogin() == l)
		{
			return false;
		}
	}

	return true;
}

