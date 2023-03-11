#include "backend.h"

BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
}

QString BackEnd::getTime()
{
    return this->timeFromInt;
}

int BackEnd::getRandomInt() {
    return QRandomGenerator::global()->bounded(0, 255);
}

void BackEnd::setTime(const QString& newTime)
{
    qDebug() << "KEKW!!!";
    QTime* curTime = new QTime(0, 0, 0);
    *curTime = curTime->addSecs(newTime.toInt());
    timeFromInt = curTime->toString("hh:mm:ss");
    emit timeChanged();
}
