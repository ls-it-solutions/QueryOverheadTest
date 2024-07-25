//
// Created by Kemal Soysal on 25.07.24.
//

#ifndef ORMTEST_A_H
#define ORMTEST_A_H
#include <QObject>
#include <QString>
#include <QVariant>

#include "Base.h"
#include <QSharedPointer>

namespace domain
{
    class B;

    class A : public Base
    {
        Q_OBJECT

    public:
        Q_PROPERTY(QString name READ getName WRITE setName)
        Q_PROPERTY(QSharedPointer<B> b READ getB WRITE setB)

    protected:
        QString name;
        QSharedPointer<B> b;

    public:
        A();
        virtual ~A();

        QString getName() { return this->name; }
        void setName(QString name) { this->name = name; }
        QSharedPointer<B> getB() { return this->b; }
        void setB(QSharedPointer<B> b) { this->b = b; }
    };
} // domain

#endif //ORMTEST_A_H
