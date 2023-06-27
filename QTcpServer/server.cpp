

#include "server.h"

Server::Server(QObject *parent)
    : QObject{parent}
{
    QObject::connect(&server,&QTcpServer::newConnection,this,&Server::newConnection);
    QObject::connect(&server,&QTcpServer::pendingConnectionAvailable,this,&Server::pendingConnectionAvailable);
    QObject::connect(&server,&QTcpServer::acceptError,this,&Server::acceptError);

}

Server::~Server()
{
    // TODO
}

void Server::start(QString hostip, quint16 port)
{
    QHostAddress address;
    address.setAddress(hostip);
    if(!server.listen(address,port))
    {
        qWarning() << server.errorString() << " | Couldn't Start The Server On :" << address << ":On Port:" << port;
        return;
    }
    qInfo() << "Listening...";
}

void Server::stop()
{
    server.close();
}

void Server::newConnection()
{
    QTcpSocket* socket = server.nextPendingConnection();
    QObject::connect(socket,&QTcpSocket::disconnected,this,&Server::disconnected);
    QObject::connect(socket,&QTcpSocket::readyRead,this,&Server::readyread);

    qInfo() << "Connected!" << socket;

}

void Server::readyread()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    qInfo() << "ReadyRead!" << socket;
    qInfo() << socket->readAll();
}

void Server::disconnected()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    qInfo() << "Disconnected!" << socket;
    qInfo() << "Parent:" << socket->parent();


    socket->deleteLater();
}

void Server::acceptError(QAbstractSocket::SocketError socketError)
{
    qInfo() << "Error:" << socketError;
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    // TODO
}

void Server::addPendingConnection(QTcpSocket *socket)
{
    // TODO
}

void Server::pendingConnectionAvailable()
{
    // TODO
}

