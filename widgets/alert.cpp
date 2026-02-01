#include "alert.h"

ErrorFrame::ErrorFrame(QWidget* parent) : QFrame(parent)
{
    setFrameStyle(QFrame::Box | QFrame::Raised);
    setLineWidth(2);

    label = new QLabel(this);
    label->setAlignment(Qt::AlignCenter);
    label->setWordWrap(true); 

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(label);
    /*layout->setContentsMargins(20, 20, 20, 20);*/
    setLayout(layout);

    setStyleSheet("QFrame { background-color: rgb(250, 115, 115); }"
        "QLabel { color: white; font-size: 24px; font-weight: bold; }");
}

void ErrorFrame::setText(const QString& text)
{
    label->setText(text);
}

void ErrorFrame::setSize(int width, int height)
{
    resize(width, height);
}

void ErrorFrame::setFontSize(int size)
{
    QFont font = label->font();
    font.setPointSize(size);  
    label->setFont(font);
}