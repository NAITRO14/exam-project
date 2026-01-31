#pragma once
#include "core/QtIncludes.h"
#include "core/BaseIncludes.h"

class menuManager : QObject
{
	Q_OBJECT
private:
	QStackedWidget* menues;
	menuManager() : menues(new QStackedWidget()) {};
	menuManager(const menuManager&) = delete;

public:
	static menuManager& getManager();

	//настройки менеджера
	void add_menu(QWidget* w);
	QStackedWidget* getStack();

	//переключатели меню
	void auth_menue();
	void resister();
	void login();


};

