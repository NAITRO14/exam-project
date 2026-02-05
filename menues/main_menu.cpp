#include "main_menu.h"

main_menu::main_menu(QWidget* parent) : QWidget(parent)
{
	find = new QPushButton(this);
	find->setText("Найти партнера");
	find->setFont(QFont("Calibri", 20, QFont::Bold));
	connect(find, &QPushButton::clicked, []()
		{
			system("cls");
			user* cur = dataManager::getManager().get_current_user();
			user* best = dataManager::getManager().find_best_partner(*cur);

			if (best == nullptr)
			{
				cout << "=====================" << endl;
				cout << "Партнер не найден" << endl;
				cout << "=====================" << endl;
				return;
			}
			cout << "=====================" << endl;
			best->print();
			best->print_int();
			cout << "=====================" << endl;

		});

	fill = new QPushButton(this);
	fill->setText("Анкета партнера");
	fill->setFont(QFont("Calibri", 20, QFont::Bold));
	connect(fill, &QPushButton::clicked, []()
		{
			menuManager::getManager().partner_form();
		});

	rules = new QPushButton(this);
	rules->setText("Как пользоваться?");
	rules->setFont(QFont("Calibri", 20, QFont::Bold));

	quit = new QPushButton(this);
	quit->setText("Выход");
	quit->setFont(QFont("Calibri", 20, QFont::Bold));
	connect(quit, &QPushButton::clicked, []() {
		exit(0);
		});
}

void main_menu::resizeEvent(QResizeEvent* event)
{
	find->move(width() * 0.05, height() * 0.1167);
	find->setFixedSize(width() * 0.3125, height() * 0.083);

	fill->move(width() * 0.05, height() * 0.283);
	fill->setFixedSize(width() * 0.3125, height() * 0.083);

	rules->move(width() * 0.05, height() * 0.45);
	rules->setFixedSize(width() * 0.3125, height() * 0.083);

	quit->move(width() * 0.05, height() * 0.6167);
	quit->setFixedSize(width() * 0.3125, height() * 0.083);

	QWidget::resizeEvent(event);
}
