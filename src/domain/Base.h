//
// Created by Kemal Soysal on 25.07.24.
//

#ifndef BASE_H
#define BASE_H
#include <QJsonObject>
#include <QObject>
#include <QString>

namespace domain
{
    class Base : public QObject
    {
        Q_OBJECT

    public:
        Q_PROPERTY(quint64 id READ getID WRITE setID)

    protected:
        quint64 id;

    public:
        Base();
        virtual ~Base();
        quint64 getID() { return this->id; };
        void setID(quint64 id) { this->id = id; };

        QJsonObject toJson()
        {
            QJsonObject json;
            if (this != nullptr) { json["id"] = QJsonValue::fromVariant(QVariant(this->getID())); }
            return json;
        }
    };
}
#endif //BASE_H
