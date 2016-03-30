#include "byteconverterclass.h"

void ByteConverterClass::setDec(const QString& data){
    number=data.toInt(&ok,10);
         emit decChanged(QString::number(number,16));
}

void ByteConverterClass::setHex(const QString& data){
    number=data.toInt(&ok,16);
         emit hexChanged(QString::number(number,2));
}

void ByteConverterClass::setBin(const QString& data){
    number=data.toInt(&ok,2);
         emit binChanged(QString::number(number,10));
}

