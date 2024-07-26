#include <QCoreApplication>
#include <QDebug>
#include <QElapsedTimer>

#include "database/Mapper.h"
#include "domain/A.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    QElapsedTimer timer = QElapsedTimer();
    qDebug() << "Hello World";


    domain::Base base = domain::Base();
    qDebug() << "Hello Base" << base.toJson();

    qDebug() << "Hi Kemal\n" << domain::A().toJson();

    database::Mapper mapper;
    QSharedPointer<domain::A> queryResult;
    const quint64 MAX = 100000;
    timer.start();
    for (quint64 i = 0; i < MAX; ++i)
    {
        queryResult = mapper.query(
            QStringLiteral(
                // "SELECT * FROM A;\n"
                // "SELECT * FROM B;\n"
                "SELECT 1 id, 'proxy' \"name\";\n"
                "SELECT 1 id, 'proxy child' \"name\" ;\n"
            )
        );
    }
    qint64 elapsed = timer.elapsed();
    qDebug() << "Hi Mapper\n" << queryResult->toJson();
    qDebug() << "elapsed time" << elapsed;

    timer.restart();
    for (quint64 i = 0; i < MAX; ++i)
    {
        queryResult = mapper.query(
            QStringLiteral(
                "SELECT 1 id, 'proxy' \"name\";\n"
            )
        );
    }
    elapsed = timer.elapsed();
    qDebug() << "Hi Mapper\n" << queryResult->toJson();
    qDebug() << "elapsed time" << elapsed;

    timer.restart();
    for (quint64 i = 0; i < MAX; ++i)
    {
        queryResult = mapper.query(
            QStringLiteral(
                "SELECT 1 id, 'proxy child' \"name\" ;\n"
            )
        );
    }
    elapsed = timer.elapsed();
    qDebug() << "Hi Mapper\n" << queryResult->toJson();
    qDebug() << "elapsed time" << elapsed;

    timer.restart();
    for (quint64 i = 0; i < MAX; ++i)
    {
        queryResult = mapper.query(
            QStringLiteral(
                "SELECT A.ID, A.NAME FROM A;\n"
                "SELECT B.ID, B.NAME FROM B;\n"
            )
        );
    }
    elapsed = timer.elapsed();

    qDebug() << "Hi Mapper\n" << queryResult->toJson();
    qDebug() << "elapsed time" << elapsed;

    timer.restart();
    for (quint64 i = 0; i < MAX; ++i)
    {
        queryResult = mapper.query(
            QStringLiteral(
                "SELECT A.ID, A.NAME FROM A;\n"
            )
        );
    }
    elapsed = timer.elapsed();

    qDebug() << "Hi Mapper\n" << queryResult->toJson();
    qDebug() << "elapsed time" << elapsed;


    timer.restart();
    for (quint64 i = 0; i < MAX; ++i)
    {
        queryResult = mapper.query(
            QStringLiteral(
                "SELECT B.ID, B.NAME FROM B;\n"
            )
        );
    }
    elapsed = timer.elapsed();

    qDebug() << "Hi Mapper\n" << queryResult->toJson();
    qDebug() << "elapsed time" << elapsed;

    //return QCoreApplication::exec();
    return 0;
}
