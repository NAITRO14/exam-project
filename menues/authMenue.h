#pragma once
#include "core/BaseIncludes.h"
#include "core/QtIncludes.h"
#include "managers/menuManager.h"

class authMenue : public QWidget
{
	Q_OBJECT

private:
	QPushButton* reg;
	QPushButton* log;

public:
	authMenue(QWidget* parent = nullptr);

protected:
	void resizeEvent(QResizeEvent* event) override;
};


