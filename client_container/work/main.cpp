#include <QtCore>

#include "TCPClient.h"

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

int main(int argc, char *argv[])
{
  QString ipaddr = "";
  int port = 0u;
  int num_messages = 0u;
  for (int i = 0u; i < argc; i++)
  {
	qDebug() << argv[i];
  }
  
  // read in arguments ipaddr then port
  if (argc == 4u)
  {
	ipaddr = argv[1u];
	sscanf(argv[2u],"%d",&port);
	sscanf(argv[3u],"%d",&num_messages);
  }
  else
  {
	qDebug() << "invalid arguments:";
	return 1u;
  }
	
  QCoreApplication a(argc, argv);
  
  TCPClient* client = new TCPClient();
  client->StartClient(ipaddr, port, num_messages);
  
  return a.exec();
}