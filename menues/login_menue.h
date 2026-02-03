#pragma once
#include "core/QtIncludes.h"
#include "core/BaseIncludes.h"
#include "managers/menuManager.h"
#include "managers/dataManager.h"
#include "widgets/alert.h"

class login_menue : public QWidget
{
	Q_OBJECT
private:
	QLineEdit* user_login;
	QLineEdit* user_pass;

	QPushButton* log_in;
	QPushButton* back;

	ErrorFrame* incorrect_input;
public:
	login_menue(QWidget* parent = nullptr);
	bool login(QString l, QString p);
	void clear_fields();


protected:
	void resizeEvent(QResizeEvent* event) override;
};
