#include <QCoreApplication>
#include <QDebug>

#include "src/database/Mapper.h"
#include "src/domain/A.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    qDebug() << "Hello World";


    domain::Base base = domain::Base();
    qDebug() << "Hello Base" << base.toJson();

    qDebug() << "Hi Kemal\n" << domain::A().toJson();

    QSharedPointer<domain::A> queryResult = database::Mapper().query(QStringLiteral("What a query"));
    qDebug() << "Hi Mapper\n" << queryResult->toJson();

    return QCoreApplication::exec();
}
