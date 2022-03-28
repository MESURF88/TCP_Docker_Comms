#include <QtCore>

#include "TCPServer.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  
  TCPServer* server = new TCPServer();
  server->StartServer();
  
  return a.exec();
}