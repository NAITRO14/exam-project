#pragma once
#include "core/QtIncludes.h"
#include "core/BaseIncludes.h"
#include "managers/menuManager.h"
#include "managers/dataManager.h"
#include "user_class.h"

class fillProfil_menue : public QWidget
{
	Q_OBJECT

private:
	QLineEdit* fname_line;
	QLineEdit* lname_line;
	QLineEdit* age;
	QLineEdit* sex;
	QLineEdit* city;

	QLineEdit* int1;
	QLineEdit* int2;
	QLineEdit* int3;

	QPushButton* finish_reg;
	QPushButton* back;


public:
	fillProfil_menue(QWidget* parent = nullptr);

	void clear_fields();
	void new_user(QString fn, QString ln, int a, bool s, QString c, QString i1, QString i2, QString i3);

protected:
	void resizeEvent(QResizeEvent* event) override;
};

