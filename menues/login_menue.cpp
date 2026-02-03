#include "login_menue.h"

login_menue::login_menue(QWidget* parent) : QWidget(parent)
{
	user_login = new QLineEdit(this);
	user_login->setPlaceholderText("Введите логин");
	user_login->setFont(QFont("Calibri", 20, QFont::Bold));

	user_pass = new QLineEdit(this);
	user_pass->setPlaceholderText("Введите пароль");
	user_pass->setFont(QFont("Calibri", 20, QFont::Bold));

	log_in = new QPushButton(this);
	log_in->setText("Войти");
	log_in->setFont(QFont("Calibri", 18, QFont::Bold));
	connect(log_in, &QPushButton::clicked, [this]()
		{
			if (login(user_login->text(), user_pass->text()))
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


	

	//ALERTS
	incorrect_input = new ErrorFrame(this);
	incorrect_input->setText("Неверный логин или пароль!");
	incorrect_input->hide();


}

bool login_menue::login(QString l, QString p)
{
	
	if (!dataManager::getManager().try_to_log_in(l, p))
	{
		incorrect_input->show();
		QTimer::singleShot(2000, [e = incorrect_input]() { e->hide(); });
		return false;
	}
	menuManager::getManager().main_menu();

	return true;
}

void login_menue::clear_fields()
{
	user_login->clear();
	user_pass->clear();
}

void login_menue::resizeEvent(QResizeEvent* event)
{
	user_login->move(width() * 0.30375, height() * 0.15);
	user_login->setFixedSize(width() * 0.39, height() * 0.09);

	user_pass->move(width() * 0.30374, height() * 0.33);
	user_pass->setFixedSize(width() * 0.39, height() * 0.09);

	log_in->move(width() * 0.34, height() * 0.57);
	log_in->setFixedSize(width() * 0.32, height() * 0.078);


	back->move(width() * 0.035, height() * 0.863);
	back->setFixedSize(width() * 0.16625, height() * 0.09);

	//ALERTS
	incorrect_input->move(width() * 0.3, height() * 0.785);
	incorrect_input->setFixedSize(width() * 0.4, height() * 0.1);

	QWidget::resizeEvent(event);
}