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
    users[6] = user("Анна", "Васильева", 29, true, "Нижний-Новгород", "anna29", "lucky29");
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

    users[1].addInterests({ "Футбол", "Музыка", "Фильмы" });
    users[2].addInterests({ "Книги", "Футбол", "Игры" });
    users[3].addInterests({ "Программирование", "Фильмы", "Спорт" });
    users[4].addInterests({ "Музыка", "Программирование", "Книги" });
    users[5].addInterests({ "Спорт", "Игры", "Кулинария" });
    users[6].addInterests({ "Футбол", "Спорт", "Танцы" });
    users[7].addInterests({ "Игры", "Фильмы", "Музыка" });
    users[8].addInterests({ "Книги", "Спорт", "Рисование" });
    users[9].addInterests({ "Программирование", "Игры", "Кулинария" });
    users[10].addInterests({ "Танцы", "Фильмы", "Книги" });

    users[11].addInterests({ "Спорт", "Музыка", "Рисование" });
    users[12].addInterests({ "Футбол", "Кулинария", "Игры" });
    users[13].addInterests({ "Программирование", "Танцы", "Спорт" });
    users[14].addInterests({ "Книги", "Фильмы", "Кулинария" });
    users[15].addInterests({ "Игры", "Рисование", "Музыка" });
    users[16].addInterests({ "Танцы", "Спорт", "Футбол" });
    users[17].addInterests({ "Шахматы", "Коллекционирование", "Астрономия" });  // ❌ Без пары
    users[18].addInterests({ "Книги", "Игры", "Футбол" });
    users[19].addInterests({ "Программирование", "Спорт", "Фильмы" });
    users[20].addInterests({ "Йога", "Виноделие", "Путешествия" }); // ❌ Без пары

}
void check_base(map<int, user>& users)// ОСНОВНАЯ ИНФОРМАЦИЯ О ЛЮДЯХ И ИХ ИНТЕРЕСЫ ЗАПИСЫВАЮТСЯ В РАЗНЫЕ ФАЙЛЫ
{
    ifstream check("appData/users.txt");
    if (!check)
    {
        check.close();
        create_base(users);

        ofstream f1("appData/users.txt");
        if (!f1)
        {
            cerr << " Ошибка создания файла базы данных!" << endl;
            exit(1);
        }
        ofstream f2("appData/users_interests.txt");
        if (!f2)
        {
            cerr << " Ошибка создания файла базы данных!" << endl;
            exit(1);
        }

        for (auto it = users.begin(); it != users.end(); ++it)
        {
            user tmp_user(it->second);
            f1 << tmp_user.getFname() << " " << tmp_user.getLname() << " " << tmp_user.getSex() << " " << tmp_user.getAge() << " "
                << tmp_user.getID() << " " << tmp_user.getCity() << " " << tmp_user.getLogin() << " " << tmp_user.getPass() << endl;
        }
        for (auto it = users.begin(); it != users.end(); ++it)
        {
            f2 << it->second.getID() << " ";
            for (auto it2 : it->second.getInterests())
            {
                f2 << it2 << " ";
            }
            f2 << endl;
        }

        f1.close();
        f2.close();
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

            tmp_user.print();

            users.emplace(tmp_user.getID(), tmp_user);
        }

        vector<string>interests = {"", "", ""};
        ifstream f("appData/users_interests.txt");
        if (!f)
        {
            cerr << "Ошибка чтений файла интересов" << endl;
            exit(1);
        }
        while (f >> ID >> interests[0] >> interests[1] >> interests[2])
        {
            users.find(ID)->second.addInterests(interests);
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
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    map<int, user> users;
    check_base(users);

    QApplication app(argc, argv);
    QMainWindow* window = new QMainWindow;

    congigurate_app(window);
   
    window->show();
    return app.exec();
}
