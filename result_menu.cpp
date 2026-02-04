#include "result_menu.h"

result_menu::result_menu(QWidget* parent, QString* _n, QString* _a, QString* _s, QString* _int) : QWidget(parent)
{

	back_frame = new QFrame(this);
	back_frame->setStyleSheet("QFrame {background-color: gray;}");

	name = new QLabel(this);
	name->setFont(QFont("Calibri", 24, QFont::Bold));

	age = new QLabel(this);
	age->setFont(QFont("Calibri", 24, QFont::Bold));

	gender = new QLabel(this);
	gender->setFont(QFont("Calibri", 24, QFont::Bold));

	interests = new QLabel(this);
	interests->setFont(QFont("Calibri", 24, QFont::Bold));


	set_data();
}

void result_menu::set_data()
{
	
}

void result_menu::resizeEvent(QResizeEvent* event)
{
	back_frame->move(width() * 0.04375, height() * 0.05);
	back_frame->setFixedSize(width() * 0.91625, height() * 0.8083);

	name->move(width() * 0.054, height() * 0.125);
	name->setFixedSize(width() * 0.4775, height() * 0.08);

	age->move(width() * 0.054, height() * 0.305);
	age->setFixedSize(width() * 0.4775, height() * 0.08);

	interests->move(width() * 0.054, height() * 0.465);
	interests->setFixedSize(width() * 0.4775, height() * 0.08);

	gender->move(width() * 0.54, height() * 0.113);
	gender->setFixedSize(width() * 0.4775, height() * 0.08);

	QWidget::resizeEvent(event);
}
