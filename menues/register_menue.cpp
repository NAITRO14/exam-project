#include "register_menue.h"

regMenue::regMenue(QWidget* parent)
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

	back = new QPushButton(this);
	back->setText("Назад");
	back->setFont(QFont("Calibri", 16, QFont::Bold));

}

void regMenue::resizeEvent(QResizeEvent* event)
{
	user_login->move(width() * 0.30375, height() * 0.15);
	user_login->setFixedSize(width() * 0.39, height() * 0.09);

	user_pass->move(width() * 0.30374, height() * 0.33);
	user_pass->setFixedSize(width() * 0.39, height() * 0.09);

	reg->move(width() * 0.34, height() * 0.57);
	reg->setFixedSize(width() * 0.32, height() * 0.078);
	connect(reg, &QPushButton::clicked, &register_);

	back->move(width() * 0.035, height() * 0.863);
	back->setFixedSize(width() * 0.16625, height() * 0.09);
	connect(back, &QPushButton::clicked, []()
		{
			menuManager::getManager().auth_menue();
		});

	QWidget::resizeEvent(event);
}

void register_()
{
	cout << "asd" << endl;
}
