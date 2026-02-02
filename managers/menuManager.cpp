#include "menuManager.h"

menuManager& menuManager::getManager()
{
	static menuManager mgr; // создать единственный менеджер
	return mgr;
}

void menuManager::add_menu(QWidget* w)
{
	menues->addWidget(w);
}

QStackedWidget* menuManager::getStack()
{
	return menues;
}

void menuManager::auth_menue()
{
	menues->setCurrentIndex(0);
}

void menuManager::resister()
{
	menues->setCurrentIndex(1);
}

void menuManager::login()
{
	menues->setCurrentIndex(10);
}

void menuManager::main_menu()
{
	menues->setCurrentIndex(3);
}

void menuManager::partner_form()
{
	menues->setCurrentIndex(4);
}

void menuManager::fillProfile()
{
	menues->setCurrentIndex(2);
}
