#include "authMenue.h"

authMenue::authMenue(QWidget* parent) : QWidget(parent)
{
	reg = new QPushButton(this);
	reg->setFont(QFont("Calibri", 24, QFont::Bold));
	reg->setText("Регистрация");
	connect(reg, &QPushButton::clicked, []() {
		menuManager::getManager().resister();
		});

	log = new QPushButton(this);
	log->setFont(QFont("Calibri", 24, QFont::Bold));
	log->setText("Вход");
	connect(log, &QPushButton::clicked, []() {
		menuManager::getManager().login();
		});

}

void authMenue::resizeEvent(QResizeEvent* event)
{
	reg->move(width() * 0.035, height() * 0.655);
	reg->setFixedSize(width() * 0.319, height() * 0.14);
	

	log->move(width() * 0.646, height() * 0.655);
	log->setFixedSize(width() * 0.319, height() * 0.14);
	

	QWidget::resizeEvent(event);
}
