#pragma once
#include "core/QtIncludes.h"
#include "core/BaseIncludes.h"
#include "user_class.h"
#include <qstring.h>

class dataManager : QObject
{
	Q_OBJECT
private:
	map<int, user>* users;
	QString tmp_pas, tmp_login; // временно хранят данные о регистрируемом пользователе
    user* current_user;

	dataManager() : users(new map<int, user>()), tmp_pas("none"), tmp_login("none") {}
	dataManager(const dataManager&) = delete;

public:
	static dataManager& getManager();
	//GETTERS
	map<int, user> get_users();

    QString get_tmp_login()
    {
        return tmp_login;
    }
    QString get_tmp_pass()
    {
        return tmp_pas;
    }

    int get_size_users()
    {
        return users->size();
    }

	//SETTERS
	void set_users(map<int, user>& u);

    void save_pas(QString p)
    {
        if (tmp_pas != "none")tmp_pas = "none";
        tmp_pas = p;
    }
    void save_log(QString l)
    {
        if (tmp_login != "none")tmp_login = "none";
        tmp_login = l;
    }

    void print_toConsole()
    {
        cout << "================" << endl;
        for (auto it = users->begin(); it != users->end(); ++it)
        {
            it->second.print();
            it->second.print_partner();
            cout << "====================" << endl;
        }
    }

public:// фунции работы с данными
	bool check_login(QString l);
	void add_new_user(user& u);
    void create_base();
    void check_base();
    void updateData_inFile();
    void set_current_user(user& u);
    void update_preferences(int age, int sex, QString city);
    void print_cur_user();

    bool try_to_log_in(QString l, QString pass);

	

};