#include "byteconverter.h"
#include "ui_byteconverter.h"

ByteConverter::ByteConverter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ByteConverter)
{
    ui->setupUi(this);
}

ByteConverter::~ByteConverter()
{
    delete ui;
}
