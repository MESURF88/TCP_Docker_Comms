#include "TCPServer.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>

TCPServer::TCPServer(QObject *parent):
  QTcpServer(parent)
{
}


void TCPServer::StartServer()
{
    qserver = new QTcpServer(this);

    // whenever a user connects, it will emit signal
    connect(qserver, SIGNAL(newConnection()),
            this, SLOT(newConnection()));
			
  if (!qserver->listen(QHostAddress::Any, port))
  {
	qDebug()<<"Server couldn't start!";
  }
  else
  {
	qDebug()<<"Server started on port: "<< port;
  }
}

void TCPServer::newConnection()
{

    // need to grab the socket
    QTcpSocket *socket = qserver->nextPendingConnection();
	QDateTime now = QDateTime::currentDateTime();
	QString timestamp = now.toString(QLatin1String("ddMMyyyy_hhmmss"));
	QString filename = QString::fromLatin1("./log/server_log_%1.txt").arg(timestamp);
	QFile file(filename);
	QByteArray recvdData("");
    if(!file.open(QFile::WriteOnly |
                  QFile::Text))
    {
        qDebug() << "Could not open the file for writing";
        exit(1u);
    }
	
	QTextStream out(&file);
	while(socket->waitForReadyRead(3000))
	{
		recvdData = socket->readAll();
		out << recvdData;
		socket->write("Hello client ack \n");
		socket->flush();
		socket->waitForBytesWritten(3000);
	}

    file.close();
    socket->close();
	exit(0u);
}