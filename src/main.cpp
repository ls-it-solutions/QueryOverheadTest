#include <QCoreApplication>
#include <QDebug>
#include <QElapsedTimer>

#include "database/Mapper.h"
#include "domain/A.h"

#include <tuple>

std::tuple<QSharedPointer<domain::A>, quint64, quint64> testQuery(const database::Mapper& mapper,
                                                                  const quint64 repetitions, const QString& query)
{
    QElapsedTimer timer = QElapsedTimer();
    quint64 errors = 0;
    QSharedPointer<domain::A> result;
    timer.start();
    for (quint64 i = 0; i < repetitions; ++i)
    {
        result = mapper.query(query);
        if (result.isNull())
        {
            errors++;
        }
    }
    quint64 elapsed = timer.elapsed();
    qDebug() << "elapsed time " << elapsed << " with " << errors << " errors";
    return {result, errors, elapsed};
}

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Hello QueryOverheadTest";

    database::Mapper mapper;
    QSharedPointer<domain::A> queryResult;
    quint64 errors = 0;
    quint64 elapsed;
    const quint64 MAX = 100000;
    // const quint64 MAX = 1;
    std::tie(queryResult, errors, elapsed) = testQuery(mapper, MAX,
                                                       QStringLiteral(
                                                           "SELECT 1 id, 'first' \"name\" ;\n"
                                                           "SELECT 2 id, 'second' \"name\" ;\n"
                                                       )
    );
    qDebug() << " for two SELECTs in one query without TABLE access: " << queryResult->toJson() << "\n";

    std::tie(queryResult, errors, elapsed) = testQuery(mapper, MAX,
                                                       QStringLiteral(
                                                           "SELECT 1 id, 'first' \"name\";\n"
                                                       )
    );
    qDebug() << " for the first SELECT in one query without TABLE access: " << queryResult->toJson() << "\n";

    std::tie(queryResult, errors, elapsed) = testQuery(mapper, MAX,
                                                       QStringLiteral(
                                                           "SELECT 2 id, 'second' \"name\" ;\n"
                                                       )
    );
    qDebug() << " for the second SELECTs in one query without TABLE access: " << queryResult->toJson() << "\n";

    std::tie(queryResult, errors, elapsed) = testQuery(mapper, MAX,
                                                       QStringLiteral(
                                                           "SELECT A.ID, A.NAME FROM A;\n"
                                                           "SELECT B.ID, B.NAME FROM B;\n"
                                                       )
    );
    qDebug() << " for two SELECTs in one query with TABLE access: " << queryResult->toJson() << "\n";

    std::tie(queryResult, errors, elapsed) = testQuery(mapper, MAX,
                                                       QStringLiteral(
                                                           "SELECT A.ID, A.NAME FROM A;\n"
                                                       )
    );

    qDebug() << " for first SELECT in one query with TABLE access: " << queryResult->toJson() << "\n";


    std::tie(queryResult, errors, elapsed) = testQuery(mapper, MAX,
                                                       QStringLiteral(
                                                           "SELECT B.ID, B.NAME FROM B;\n"
                                                       )
    );
    qDebug() << " for second SELECT in one query with TABLE access: " << queryResult->toJson() << "\n";

    return 0;
}