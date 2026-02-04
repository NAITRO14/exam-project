#pragma once
#include "core/BaseIncludes.h"
#include "core/QtIncludes.h"
#include "user_card.h"
#include "managers/dataManager.h"

class result_menu : public QWidget {
    Q_OBJECT
public:
    result_menu(QWidget* parent, QString* _n, QString* _a, QString* _s, QString* _int);
    void set_data();


private:
    QFrame* back_frame;
    QLabel* name;
    QLabel* age;
    QLabel* gender;
    QLabel* interests;

private:

protected:
    void resizeEvent(QResizeEvent* event) override;
};
