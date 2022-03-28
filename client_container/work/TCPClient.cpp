#include "TCPClient.h"

TCPClient::TCPClient(QObject *parent)
{
}


void TCPClient::StartClient(QString ipaddr, int port, int num_messages)
{
	QString line = "";
    socket = new QTcpSocket(this);
    socket->connectToHost(ipaddr, port);
    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected!";

		for (int i = 0u; i < num_messages; i++)
		{
			// send
			line = "hello server " + QString::number(i + 1u) + " \n";
			socket->write( line.toUtf8() );
			socket->waitForBytesWritten(1000);
			socket->waitForReadyRead(3000);
			socket->flush();
		}

        socket->close();
	    exit(0u);
    }
    else
    {
        qDebug() << "Not connected!";
		exit(0u);
    }
}

