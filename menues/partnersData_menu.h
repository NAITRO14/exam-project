#pragma once
#include "core/QtIncludes.h"
#include "core/BaseIncludes.h"
#include "managers/menuManager.h"
#include "managers/dataManager.h"

class partnersData_menu : public QWidget
{
	Q_OBJECT
public:
	partnersData_menu(QWidget* parent);
private:
	QLineEdit* age;
	QLineEdit* sex;
	QLineEdit* city;

	QPushButton* fixate;
	QPushButton* back;

	void clear_fields();

protected:
	void resizeEvent(QResizeEvent* event); 
};

