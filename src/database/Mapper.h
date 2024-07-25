//
// Created by Kemal Soysal on 25.07.24.
//

#ifndef MAPPER_H
#define MAPPER_H
#include <QSharedPointer>
#include "../domain/A.h"

namespace database
{
    class Mapper
    {
    public:
        QSharedPointer<domain::A> query(QString query);
    };
} // database

#endif //MAPPER_H
