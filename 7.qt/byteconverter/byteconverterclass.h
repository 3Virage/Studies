#ifndef BYTECONVERTERCLASS_H
#define BYTECONVERTERCLASS_H

#include <QMainWindow>

class ByteConverterClass : public QObject
{
 Q_OBJECT


public slots:
 void setDec(const QString&);
 void setHex(const QString&);
 void setBin(const QString&);
signals:
 void decChanged(const QString&);
 void hexChanged(const QString&);
 void binChanged(const QString&);
private:
 int number;
 bool ok;
};
#endif
