#include "fillProfil_menue.h"

fillProfil_menue::fillProfil_menue(QWidget* parent)
{
	finish_reg = new QPushButton(this);
	finish_reg->setFont(QFont("Calibri", 20, QFont::Bold));
	finish_reg->setText("Зарегистрироваться");
	connect(finish_reg, &QPushButton::clicked, [this]() {

		//хотябы одно поле пустое
		if (fname_line->text().isEmpty() ||
			lname_line->text().isEmpty() ||
			age->text().isEmpty() ||
			sex->text().isEmpty() ||
			city->text().isEmpty() ||
			int1->text().isEmpty() ||
			int2->text().isEmpty() ||
			int3->text().isEmpty())
		{
			QMessageBox::warning(this, "Ошибка", "Не все поля были заполнены!");
			return;
		}

		bool s = 0;
		if (sex->text().toLower() == "муж" or sex->text().toLower() == "жен")
		{
			if (sex->text().toLower() == "муж")s = 0;
			if (sex->text().toLower() == "жен")s = 1;
		}
		else
		{
			cerr << "Некорректный пол!" << endl;
			QMessageBox::critical(this, "Ошибка!", "Пол введен неверно! Сравнитесь с примером.");
			sex->clear();
			return;
		}
		

		bool check_a;
		int a = age->text().toInt(&check_a);

		if (!check_a)
		{
			cerr << "Ошибка при вводе возраста!" << endl;
			QMessageBox::critical(this, "Ошибка!", "Проверье поле возраста, допускаются только цифры.");
			age->clear();
			return;
		}
		else
		{
			if (a < 14 or a > 100)
			{
				cerr << "Некорректный возраст!" << endl;
				QMessageBox::critical(this, "Ошибка!", "В таком возрасте нельзя зарегистрироваться.");
				age->clear();
				return;
			}
		}
		
		new_user(fname_line->text(), lname_line->text(), 
			a, s, city->text(), int1->text(), int2->text(), int3->text());

		menuManager::getManager().main_menu();
		});

	back = new QPushButton(this);
	back->setText("Отмена");
	back->setFont(QFont("Calibri", 16, QFont::Bold));
	connect(back, &QPushButton::clicked, [this]()
		{
			menuManager::getManager().auth_menue();
			clear_fields();
		});
	


	fname_line = new QLineEdit(this);
	fname_line->setPlaceholderText("Имя");
	fname_line->setFont(QFont("Calibri", 20, QFont::Bold));

	lname_line = new QLineEdit(this);
	lname_line->setPlaceholderText("Фамилия");
	lname_line->setFont(QFont("Calibri", 20, QFont::Bold));

	age = new QLineEdit(this);
	age->setPlaceholderText("Возраст");
	age->setFont(QFont("Calibri", 20, QFont::Bold));

	sex = new QLineEdit(this);
	sex->setPlaceholderText("Пол(муж/жен)");
	sex->setFont(QFont("Calibri", 20, QFont::Bold));

	city = new QLineEdit(this);
	city->setPlaceholderText("Город");
	city->setFont(QFont("Calibri", 20, QFont::Bold));


	int1 = new QLineEdit(this);
	int1->setPlaceholderText("Интерес 1");
	int1->setFont(QFont("Calibri", 20, QFont::Bold));

	int2 = new QLineEdit(this);
	int2->setPlaceholderText("Интерес 2");
	int2->setFont(QFont("Calibri", 20, QFont::Bold));

	int3 = new QLineEdit(this);
	int3->setPlaceholderText("Интерес 3");
	int3->setFont(QFont("Calibri", 20, QFont::Bold));

}

void fillProfil_menue::clear_fields()
{
	fname_line->clear();
	lname_line->clear();
	age->clear();
	sex->clear();
	city->clear();

	int1->clear();
	int2->clear();
	int3->clear();
}

void fillProfil_menue::new_user(QString fn, QString ln, int a, bool s, QString c, QString i1, QString i2, QString i3)
{
	QString pas, log; QVector<QString> tmp_int = { i1, i2, i3 };
	pas = dataManager::getManager().get_tmp_pass();
	log = dataManager::getManager().get_tmp_login();
	if (pas == "none" or log == "none")cerr << "Ошибка при получении данных логина и пароля" << endl, exit(1);

	user tmp_user(fn, ln, a, s, c, log, pas);
	tmp_user.addInterests(tmp_int);
		
	dataManager::getManager().add_new_user(tmp_user);
}

void fillProfil_menue::resizeEvent(QResizeEvent* event)
{
	finish_reg->move(width() * 0.343, height() * 0.8167);
	finish_reg->setFixedSize(width() * 0.3125, height() * 0.075);

	back->move(width() * 0.035, height() * 0.863);
	back->setFixedSize(width() * 0.16625, height() * 0.09);


	fname_line->move(width() * 0.0625, height() * 0.117);
	fname_line->setFixedSize(width() * 0.3375, height() * 0.0667);

	lname_line->move(width() * 0.0625, height() * 0.283);
	lname_line->setFixedSize(width() * 0.3375, height() * 0.0667);

	age->move(width() * 0.0625, height() * 0.45);
	age->setFixedSize(width() * 0.3375, height() * 0.0667);

	sex->move(width() * 0.0625, height() * 0.617);
	sex->setFixedSize(width() * 0.3375, height() * 0.0667);

	city->move(width() * 0.6, height() * 0.1167);
	city->setFixedSize(width() * 0.3375, height() * 0.0667);


	int1->move(width() * 0.6, height() * 0.2167);
	int1->setFixedSize(width() * 0.3375, height() * 0.0667);

	int2->move(width() * 0.6, height() * 0.3);
	int2->setFixedSize(width() * 0.3375, height() * 0.0667);

	int3->move(width() * 0.6, height() * 0.383);
	int3->setFixedSize(width() * 0.3375, height() * 0.0667);

	QWidget::resizeEvent(event);
}
