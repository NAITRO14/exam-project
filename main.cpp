#include "core/BaseIncludes.h"
#include "core/QtIncludes.h"
#include "user_class.h"
#include "menues/authMenue.h"
#include "managers/menuManager.h"
#include "menues/register_menue.h"
#include "managers/dataManager.h"
#include "menues/fillProfil_menue.h"
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
void check_base(map<int, user>& users)
{
    QFile checkFile("appData/users.txt");
    if (!checkFile.exists()) {
        // checkFile.close();  ❌ УБРАНО - файл не открыт!
        create_base(users);

        // Запись users.txt
        QFile file1("appData/users.txt");
        if (file1.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out1(&file1);
            for (auto it = users.begin(); it != users.end(); ++it) {
                out1 << it->second.getFname() << " "
                    << it->second.getLname() << " "
                    << it->second.getSex() << " "
                    << it->second.getAge() << " "
                    << it->second.getID() << " "
                    << it->second.getCity() << " "
                    << it->second.getLogin() << " "
                    << it->second.getPass() << "\n";
            }
            file1.close();
        }

        // Запись users_interests.txt
        QFile file2("appData/users_interests.txt");
        if (file2.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out2(&file2);
            for (auto it = users.begin(); it != users.end(); ++it) {
                out2 << it->second.getID() << " ";
                for (auto it2 : it->second.getInterests()) {
                    out2 << it2 << " ";
                }
                out2 << "\n";
            }
            file2.close();
        }
    }
    else {
        QFile file1("appData/users.txt");
        if (file1.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in1(&file1);
            while (!in1.atEnd()) {
                QString line = in1.readLine();
                QStringList parts = line.split(" ", Qt::SkipEmptyParts);

                if (parts.size() >= 8) {
                    QString fname = parts[0];
                    QString lname = parts[1];
                    bool sex = parts[2].toInt();
                    int age = parts[3].toInt();
                    int ID = parts[4].toInt();
                    QString city = parts[5];
                    QString login = parts[6];
                    QString pass = parts[7];

                    user tmp_user(fname, lname, age, sex, city, login, pass);
                    tmp_user.setID(ID);
                    tmp_user.print();
                    users.emplace(ID, tmp_user);
                }
            }
            file1.close();
        }

        QFile file2("appData/users_interests.txt");
        if (file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in2(&file2);
            while (!in2.atEnd()) {
                QString line = in2.readLine();
                QStringList parts = line.split(" ", Qt::SkipEmptyParts);

                if (parts.size() >= 2 && users.find(parts[0].toInt()) != users.end()) {
                    int ID = parts[0].toInt();
                    QVector<QString> interests;
                    for (int i = 1; i < parts.size(); ++i) {
                        interests.append(parts[i]);
                    }
                    users[ID].addInterests(interests);
                }
            }
            file2.close();
        }
    }
    
}
void congigurate_app(QMainWindow* window)
{
    window->setMinimumSize(800, 600);
    window->setCentralWidget(menuManager::getManager().getStack());
    menuManager::getManager().add_menu(new authMenue(nullptr));
    menuManager::getManager().add_menu(new regMenue(nullptr));
    menuManager::getManager().add_menu(new fillProfil_menue(nullptr));
}

int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    map<int, user> users;
    check_base(users);
    dataManager::getManager().set_users(users);

    QApplication app(argc, argv);
    QMainWindow* window = new QMainWindow;

    congigurate_app(window);
   
    window->show();
    return app.exec();
}
