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
	menues->setCurrentIndex(2);
}
