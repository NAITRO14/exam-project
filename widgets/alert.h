#pragma once 
#include "core/QtIncludes.h"
#include "core/BaseIncludes.h"

class ErrorFrame : public QFrame
{
    Q_OBJECT
public:
    explicit ErrorFrame(QWidget* parent = nullptr);
    void setText(const QString& text);
    void setSize(int width, int height);
    void setFontSize(int size);

private:
    QLabel* label;
};