#pragma once
#include "core/QtIncludes.h"
#include "core/BaseIncludes.h"
#include "managers/menuManager.h"
#include "managers/dataManager.h"
#include "widgets/alert.h"

class regMenue : public QWidget
{
	Q_OBJECT
private:
	QLineEdit* user_login;
	QLineEdit* user_pass;

	QPushButton* reg;
	QPushButton* back;

	ErrorFrame* login_busy;
	ErrorFrame* incorrect_login;
	ErrorFrame* incorrect_pass;
public:
	regMenue(QWidget* parent = nullptr);
	bool register_(QString l, QString p);
	void clear_fields();


protected:
	void resizeEvent(QResizeEvent* event) override;
};

