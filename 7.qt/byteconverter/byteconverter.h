#ifndef BYTECONVERTER_H
#define BYTECONVERTER_H

#include <QMainWindow>

namespace Ui {
class ByteConverter;
}

class ByteConverter : public QMainWindow
{
    Q_OBJECT

public:
    explicit ByteConverter(QWidget *parent = 0);
    ~ByteConverter();

private:
    Ui::ByteConverter *ui;
};

#endif // BYTECONVERTER_H
