#pragma once
#include "core/QtIncludes.h"
#include "core/BaseIncludes.h"
#include "managers/menuManager.h"

class regMenue : public QWidget
{
	Q_OBJECT
private:
	QLineEdit* user_login;
	QLineEdit* user_pass;

	QPushButton* reg;
	QPushButton* back;

public:
	regMenue(QWidget* parent = nullptr);
protected:
	void resizeEvent(QResizeEvent* event) override;
};