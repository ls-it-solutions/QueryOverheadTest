//
// Created by Kemal Soysal on 25.07.24.
//

#ifndef BASE_H
#define BASE_H
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

    };
}
#endif //BASE_H
