//
// Created by Kemal Soysal on 25.07.24.
//

#include "Mapper.h"
#include "../domain/B.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace database
{
    Mapper::Mapper()
    {
        this->connect();
    }

    Mapper::~Mapper()
    {
        this->disconnect();
    }

    QSharedPointer<domain::A> Mapper::query(const QString& query) const
    {
        QSharedPointer<domain::A> result;
        try
        {
            QSqlQuery sqlQuery = QSqlQuery(*this->db);
            sqlQuery.setForwardOnly(true);

            sqlQuery.exec(query);

            QSqlError err = sqlQuery.lastError();
            if (err.type() == QSqlError::NoError)
            {
                bool nextResultSet = true;
                bool next;
                while (nextResultSet && (next = sqlQuery.next()))
                {
                    result = QSharedPointer<domain::A>(new domain::A());
                    result->setID(sqlQuery.value(0).value<quint64>());
                    result->setName(sqlQuery.value(1).toString());
                }
                nextResultSet = sqlQuery.nextResult();
                while (nextResultSet && (next = sqlQuery.next()))
                {
                    result->setB(QSharedPointer<domain::B>(new domain::B()));
                    result->getB()->setID(sqlQuery.value(0).value<quint64>());
                    result->getB()->setName(sqlQuery.value(1).toString());
                }
                sqlQuery.finish();
            }
        }
        catch (const std::exception& e)
        {
            throw e;
        }
        return result;
    }

    void Mapper::connect()
    {
        if (this->db != nullptr) { return; }

        this->db = QSharedPointer<QSqlDatabase>::create(QSqlDatabase::addDatabase("QPSQL", "QueryOverheadTest"));
        this->db->setHostName("localhost");
        this->db->setUserName("postgres");
        this->db->setPassword("postgres");
        this->db->setDatabaseName("queryoverheadtest");
        this->opened = this-db->open();
    }

    void Mapper::disconnect()
    {
        if (this->db == nullptr) { return; }
        this->db->close();
        this->db.clear();
        QSqlDatabase::removeDatabase("QueryOverheadTest");
        this->opened = false;
    }
} // database
