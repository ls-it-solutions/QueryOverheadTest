#include <QCoreApplication>
#include <QDebug>
#include <QElapsedTimer>

#include "database/Mapper.h"
#include "domain/A.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    QElapsedTimer timer = QElapsedTimer();
    qDebug() << "Hello QueryOverheadTest";

    database::Mapper mapper;
    QSharedPointer<domain::A> queryResult;
    const quint64 MAX = 100000;
    timer.start();
    for (quint64 i = 0; i < MAX; ++i)
    {
        queryResult = mapper.query(
            QStringLiteral(
                "SELECT 1 id, 'proxy' \"name\";\n"
                "SELECT 1 id, 'proxy child' \"name\" ;\n"
            )
        );
    }
    qint64 elapsed = timer.elapsed();
    qDebug() << "elapsed time " << elapsed;
    qDebug() << " for two SELECTs in one query without TABLE access: " << queryResult->toJson() << "\n";

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
    qDebug() << "elapsed time " << elapsed;
    qDebug() << " for the first SELECT in one query without TABLE access: " << queryResult->toJson() << "\n";

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
    qDebug() << "elapsed time " << elapsed;
    qDebug() << " for the second SELECTs in one query without TABLE access: " << queryResult->toJson() << "\n";

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

    qDebug() << "elapsed time " << elapsed;
    qDebug() << " for two SELECTs in one query with TABLE access: " << queryResult->toJson() << "\n";

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

    qDebug() << "elapsed time " << elapsed;
    qDebug() << " for first SELECT in one query with TABLE access: " << queryResult->toJson() << "\n";


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

    qDebug() << "elapsed time " << elapsed;
    qDebug() << " for second SELECT in one query with TABLE access: " << queryResult->toJson() << "\n";

    return 0;
}
