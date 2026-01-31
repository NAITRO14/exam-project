#include "core/BaseIncludes.h"
#include "core/QtIncludes.h"
#include "user_class.h"
#include "menues/authMenue.h"
#include "managers/menuManager.h"
#include "menues/register_menue.h"
int user::total_users = 0;

void create_base(map<int, user>& users)
{
    users[1] = user("Иван", "Иванов", 25, false, "Москва", "ivan123", "qwerty1");
    users[2] = user("Мария", "Петрова", 30, true, "Санкт-Петербург", "maria30", "secret2");
    users[3] = user("Алексей", "Сидоров", 28, false, "Новосибирск", "alex28", "pass1234");
    users[4] = user("Елена", "Кузнецова", 32, true, "Екатеринбург", "elena32", "hello32");
    users[5] = user("Дмитрий", "Смирнов", 27, false, "Казань", "dmitry27", "admin27");
    users[6] = user("Анна", "Васильева", 29, true, "Нижний Новгород", "anna29", "lucky29");
    users[7] = user("Сергей", "Морозов", 34, false, "Челябинск", "sergey34", "user123");
    users[8] = user("Ольга", "Новикова", 26, true, "Самара", "olga26", "olga2026");
    users[9] = user("Михаил", "Федоров", 31, false, "Омск", "misha31", "mike31");
    users[10] = user("Наталья", "Козлова", 28, true, "Ростов-на-Дону", "natasha28", "nata2028");

    users[11] = user("Павел", "Белов", 35, false, "Уфа", "pavel35", "pash35");
    users[12] = user("Юлия", "Чернова", 24, true, "Красноярск", "yulya24", "july24");
    users[13] = user("Константин", "Дмитриев", 33, false, "Воронеж", "kostya33", "kosta33");
    users[14] = user("Вероника", "Шевченко", 29, true, "Пермь", "veronika29", "vera29");
    users[15] = user("Андрей", "Попов", 26, false, "Волгоград", "andrey26", "andy26");
    users[16] = user("Татьяна", "Соколова", 37, true, "Краснодар", "tanya37", "tata37");
    users[17] = user("Николай", "Михайлов", 42, false, "Тюмень", "nikolay42", "nik42");
    users[18] = user("Светлана", "Зайцева", 31, true, "Ижевск", "sveta31", "lana31");
    users[19] = user("Владимир", "Егоров", 39, false, "Барнаул", "vladimir39", "vova39");
    users[20] = user("Екатерина", "Павлова", 23, true, "Ульяновск", "katya23", "kate23");

}
void check_base(map<int, user>& users)
{
    ifstream check("appData/users.txt");
    if (!check)
    {
        check.close();
        create_base(users);

        ofstream f("appData/users.txt");
        if (!f)
        {
            cerr << " Ошибка создания файла базы данных!" << endl;
            exit(1);
        }

        for (auto it = users.begin(); it != users.end(); ++it)
        {
            user tmp_user(it->second);
            f << tmp_user.getFname() << " " << tmp_user.getLname() << " " << tmp_user.getSex() << " " << tmp_user.getAge() << " "
                << tmp_user.getID() << " " << tmp_user.getCity() << " " << tmp_user.getLogin() << " " << tmp_user.getPass() << endl;
        }
    }
    else
    {
        
        string fname, lname, city, pass, login;
        int age, ID;
        bool sex;
        while (check >> fname >> lname >> sex >> age >> ID >> city >> login >> pass)
        {
            user tmp_user(fname, lname, age, sex, city, login, pass);
            tmp_user.setID(ID);

            users.emplace(tmp_user.getID(), tmp_user);
        }
    }// имя -) фамилия -) возраст -) айди -) логин -) пароль
}

void congigurate_app(QMainWindow* window)
{
    window->setMinimumSize(800, 600);
    window->setCentralWidget(menuManager::getManager().getStack());
    menuManager::getManager().add_menu(new authMenue(nullptr));
    menuManager::getManager().add_menu(new regMenue(nullptr));
}

int main(int argc, char *argv[])
{
    map<int, user> users;
    check_base(users);

    QApplication app(argc, argv);
    QMainWindow* window = new QMainWindow;

    congigurate_app(window);
   
    window->show();
    return app.exec();
}
