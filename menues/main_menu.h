#pragma once
#include "core/QtIncludes.h"
#include "core/BaseIncludes.h"
#include "managers/menuManager.h"
#include "managers/dataManager.h"


class main_menu : public QWidget
{
	Q_OBJECT
public:
	main_menu(QWidget* parent);

private:
	QPushButton* find;
	QPushButton* fill;
	QPushButton* rules;
	QPushButton* quit;

	

protected:
	void resizeEvent(QResizeEvent* event) override;
};

