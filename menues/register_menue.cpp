#include "register_menue.h"



regMenue::regMenue(QWidget* parent) : QWidget(parent)
{
	user_login = new QLineEdit(this);
	user_login->setPlaceholderText("Введите логин");
	user_login->setFont(QFont("Calibri", 20, QFont::Bold));

	user_pass = new QLineEdit(this);
	user_pass->setPlaceholderText("Введите пароль");
	user_pass->setFont(QFont("Calibri", 20, QFont::Bold));
	
	reg = new QPushButton(this);
	reg->setText("Зарегистрироваться");
	reg->setFont(QFont("Calibri", 18, QFont::Bold));
	connect(reg, &QPushButton::clicked, [this]()
		{			
			if (register_(user_login->text(), user_pass->text()))
			{
				clear_fields();
			}
		});

	back = new QPushButton(this);
	back->setText("Назад");
	back->setFont(QFont("Calibri", 16, QFont::Bold));
	connect(back, &QPushButton::clicked, [this]()
		{
			menuManager::getManager().auth_menue();
			clear_fields();
		});

	cout << endl;
	map<int, user> us = dataManager::getManager().get_users();
	for (auto it = us.begin(); it != us.end(); ++it)
	{
		QTextStream out(stdout);
		out << it->second.getFname() << " " << it->second.getLname() << Qt::endl;
	}

	//ALERTS
	login_busy = new ErrorFrame(this);
	login_busy->setText("Логин уже занят!");
	login_busy->hide();

	incorrect_pass = new ErrorFrame(this);
	incorrect_pass->setText("Короткий пароль!");
	incorrect_pass->hide();

	incorrect_login = new ErrorFrame(this);
	incorrect_login->setText("Короткий логин!");
	incorrect_login->hide();


}

bool regMenue::register_(QString l, QString p)
{
	if (!dataManager::getManager().check_login(l))
	{
		cout << "Пользователь с таким логином уже есть" << endl;
		login_busy->show();
		QTimer::singleShot(2000, [e = login_busy]() { e->hide(); });
		return false;
	}
	if (l.isEmpty() or l.size() < 3)
	{
		cout << "Слишком короткий логин" << endl;
		incorrect_login->show();
		QTimer::singleShot(2000, [e = incorrect_login]() { e->hide(); });
		return false;
	}
	if (p.isEmpty() or p.size() < 5)
	{
		cout << "Слишком короткий пароль" << endl;
		incorrect_pass->show();
		QTimer::singleShot(2000, [e = incorrect_pass]() { e->hide(); });
		return false;
	}

	dataManager::getManager().save_log(l);
	dataManager::getManager().save_pas(p);

	menuManager::getManager().fillProfile();

	return true;
}

void regMenue::clear_fields()
{
	user_login->clear();
	user_pass->clear();
}

void regMenue::resizeEvent(QResizeEvent* event)
{
	user_login->move(width() * 0.30375, height() * 0.15);
	user_login->setFixedSize(width() * 0.39, height() * 0.09);

	user_pass->move(width() * 0.30374, height() * 0.33);
	user_pass->setFixedSize(width() * 0.39, height() * 0.09);

	reg->move(width() * 0.34, height() * 0.57);
	reg->setFixedSize(width() * 0.32, height() * 0.078);
	

	back->move(width() * 0.035, height() * 0.863);
	back->setFixedSize(width() * 0.16625, height() * 0.09);

	//ALERTS
	login_busy->move(width() * 0.3, height() * 0.785);
	login_busy->setFixedSize(width() * 0.4, height() * 0.1);

	incorrect_pass->move(width() * 0.3, height() * 0.785);
	incorrect_pass->setFixedSize(width() * 0.4, height() * 0.1);

	incorrect_login->move(width() * 0.3, height() * 0.785);
	incorrect_login->setFixedSize(width() * 0.4, height() * 0.1);

	QWidget::resizeEvent(event);
}


