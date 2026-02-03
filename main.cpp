#include "core/BaseIncludes.h"
#include "core/QtIncludes.h"
#include "user_class.h"
#include "menues/authMenue.h"
#include "managers/menuManager.h"
#include "menues/register_menue.h"
#include "managers/dataManager.h"
#include "menues/fillProfil_menue.h"
#include "menues/main_menu.h"
#include "menues/partnersData_menu.h"
#include "menues/login_menue.h"


int user::total_users = 0;

void congigurate_app(QMainWindow* window)
{
    window->setMinimumSize(800, 600);
    window->setCentralWidget(menuManager::getManager().getStack());

    menuManager::getManager().add_menu(new authMenue(nullptr));
    menuManager::getManager().add_menu(new regMenue(nullptr));
    menuManager::getManager().add_menu(new fillProfil_menue(nullptr));
    menuManager::getManager().add_menu(new main_menu(nullptr));
    menuManager::getManager().add_menu(new partnersData_menu(nullptr));
    menuManager::getManager().add_menu(new login_menue(nullptr));
}

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    dataManager::getManager().check_base();
    
    QApplication app(argc, argv);
    QMainWindow* window = new QMainWindow;
   
    congigurate_app(window);

    window->show();
    return app.exec();
}
