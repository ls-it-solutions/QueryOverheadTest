//
// Created by Kemal Soysal on 25.07.24.
//

#ifndef MAPPER_H
#define MAPPER_H
#include <QSharedPointer>
#include <QSqlDatabase>

#include "../domain/A.h"

namespace database
{
    class Mapper
    {
    public:
        Mapper();
        virtual ~Mapper();

        QSharedPointer<domain::A> query(QString query);

    private:
        QSharedPointer<QSqlDatabase> db;
        bool opened = false;
        void connect();
        void disconnect();
    };
} // database

#endif //MAPPER_H
