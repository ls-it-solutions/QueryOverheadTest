//
// Created by Kemal Soysal on 25.07.24.
//

#ifndef ORMTEST_B_H
#define ORMTEST_B_H
#import <QObject>
#include <QString>
#include <QVariant>

#include "Base.h"

namespace domain
{
    class B : public Base
    {
        Q_OBJECT

    public:
        Q_PROPERTY(QString name READ getName WRITE setName)

    protected:
        QString name;

    public:
        B();
        virtual ~B();

        QString getName() { return this->name; }

        void setName(const QString& name) { this->name = name; };

        QJsonObject toJson()
        {
            QJsonObject json = Base::toJson();
            json["name"] = this->name;
            return json;
        }
    };
} // domain

#endif //ORMTEST_B_H
