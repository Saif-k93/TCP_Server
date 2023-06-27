#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QAbstractSocket>



class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

    ~Server();


signals:

public slots:
    void start(QString hostip, quint16 port);
    void stop();

private slots:
    void newConnection();
    void pendingConnectionAvailable();
    void disconnected();
    void readyread();
    void acceptError(QAbstractSocket::SocketError socketError);

protected slots:
    void addPendingConnection(QTcpSocket *socket);
    virtual void incomingConnection(qintptr socketDescriptor);


private:

    QTcpServer server;

};

#endif // SERVER_H
