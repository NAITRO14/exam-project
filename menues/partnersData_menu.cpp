#include "partnersData_menu.h"

partnersData_menu::partnersData_menu(QWidget* parent) : QWidget(parent)
{
	age = new QLineEdit(this);
	age->setPlaceholderText("Примерный возраст");
	age->setFont(QFont("Calibri", 24, QFont::Bold));

	sex = new QLineEdit(this);
	sex->setPlaceholderText("Пол");
	sex->setFont(QFont("Calibri", 24, QFont::Bold));

	city = new QLineEdit(this);
	city->setPlaceholderText("Город");
	city->setFont(QFont("Calibri", 24, QFont::Bold));

	fixate = new QPushButton(this);
	fixate->setText("Зафиксировать");
	fixate->setFont(QFont("Calibri", 22, QFont::Bold));
	connect(fixate, &QPushButton::clicked, [this]()
		{
			bool check_a;
			int a = age->text().toInt(&check_a);
			

			if (!check_a)
			{
				if (age->text().isEmpty())
				{
					a = -1;
				}
				else
				{
					cerr << "Ошибка при вводе возраста!" << endl;
					QMessageBox::critical(this, "Ошибка!", "Проверье поле возраста, допускаются только цифры.");
					age->clear();
					return;
				}
				
			}
			else
			{
				if(a == -1)
				if (a < 14 or a > 100)
				{
					cerr << "Некорректный возраст!" << endl;
					QMessageBox::critical(this, "Ошибка!", "В таком возрасте нельзя зарегистрироваться.");
					age->clear();
					return;
				}
			}


			int s = 0;
			if (sex->text().toLower() == "муж" or sex->text().toLower() == "жен" or sex->text().isEmpty())
			{
				if (sex->text().toLower() == "муж")s = 0;
				if (sex->text().toLower() == "жен")s = 1;
				if (sex->text().isEmpty())s = 2;
			}
			else
			{
				cerr << "Некорректный пол!" << endl;
				QMessageBox::critical(this, "Ошибка!", "Пол введен неверно! Сравнитесь с примером.");
				sex->clear();
				return;
			}


			dataManager::getManager().update_preferences(a, s, city->text());
			dataManager::getManager().print_toConsole();
		});

	back = new QPushButton(this);
	back->setText("Назад");
	back->setFont(QFont("Calibri", 16, QFont::Bold));
	connect(back, &QPushButton::clicked, [this]()
		{
			menuManager::getManager().main_menu();
			clear_fields();
		});
}

void partnersData_menu::clear_fields()
{
	age->clear();
	sex->clear();
	city->clear();
}

void partnersData_menu::resizeEvent(QResizeEvent* event)
{
	age->move(width() * 0.28125, height() * 0.133);
	age->setFixedSize(width() * 0.4375, height() * 0.083);

	sex->move(width() * 0.28125, height() * 0.25);
	sex->setFixedSize(width() * 0.4375, height() * 0.083);

	city->move(width() * 0.28125, height() * 0.367);
	city->setFixedSize(width() * 0.4375, height() * 0.083);

	fixate->move(width() * 0.3275, height() * 0.525);
	fixate->setFixedSize(width() * 0.34375, height() * 0.083);

	back->move(width() * 0.035, height() * 0.863);
	back->setFixedSize(width() * 0.16625, height() * 0.09);

	QWidget::resizeEvent(event);
}
