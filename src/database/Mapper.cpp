//
// Created by Kemal Soysal on 25.07.24.
//

#include "Mapper.h"
#include "../domain/B.h"

namespace database {

    QSharedPointer<domain::A> Mapper::query(QString query)
    {
    QSharedPointer<domain::A> result = QSharedPointer<domain::A>(new domain::A());
    result->setID(1);
    result->setName("proxy");
    result->setB(QSharedPointer<domain::B>(new domain::B()));
    result->getB()->setID(1);
    result->getB()->setName("proxy child");
    return result;
    }
} // database