

#include "server.h"

#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    QString hostip;
    quint16 port{};
    QTextStream in(stdin);
     QTextStream out(stdout);

    out<< "Enter HostIPAsddress: " << Qt::flush;
    in >> hostip;
    in.flush();
    out << "Enter listening Port: " << Qt::flush;
    in >> port;
    in.flush();

    server.start(hostip,port);



    return a.exec();
}
