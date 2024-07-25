#include <QCoreApplication>
#include <QDebug>

#include "src/A.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    qDebug() << "Hello World";


    qDebug() << "Hi Kemal\n" << domain::A().getID();

    return QCoreApplication::exec();
}
