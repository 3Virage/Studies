#include <QApplication>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include<QPushButton>
#include "byteconverterclass.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
QWidget window;

QGridLayout* editLayout = new QGridLayout();
QVBoxLayout* mainLayout = new QVBoxLayout(&window);
QHBoxLayout* buttonLayout = new QHBoxLayout();

QLabel* label1 = new QLabel("Decimal");
QLabel* label2 = new QLabel("Hex");
QLabel* label3 = new QLabel("Binary");

QLineEdit *editDec = new QLineEdit;
QLineEdit *editHex = new QLineEdit;
QLineEdit *editBin = new QLineEdit;
editDec->setMaximumHeight(20);
editHex->setMaximumHeight(20);
editBin->setMaximumHeight(20);


editLayout->addWidget(label1,0,0);
editLayout->addWidget(label2,1,0);
editLayout->addWidget(label3,2,0,Qt::AlignTop);
editLayout->addWidget(editDec,0,1);
editLayout->addWidget(editHex,1,1);
editLayout->addWidget(editBin,2,1,7,1,Qt::AlignTop);

ByteConverterClass* conv = new ByteConverterClass;
    QObject::connect(editDec, SIGNAL(textChanged(QString)), conv, SLOT(setDec(QString)));
    QObject::connect(editHex, SIGNAL(textChanged(QString)), conv, SLOT(setHex(QString)));
    QObject::connect(editBin, SIGNAL(textChanged(QString)), conv, SLOT(setBin(QString)));
    QObject::connect(conv, SIGNAL(decChanged(QString)), editHex, SLOT(setText(QString)));
    QObject::connect(conv, SIGNAL(hexChanged(QString)), editBin, SLOT(setText(QString)));
    QObject::connect(conv, SIGNAL(binChanged(QString)), editDec, SLOT(setText(QString)));



QPushButton *quitButton = new QPushButton("&Quit");
QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
buttonLayout->addStretch(800);
buttonLayout->addWidget(quitButton);

mainLayout->addLayout(editLayout);

mainLayout->addLayout(buttonLayout);



    window.show();

    return a.exec();
}
