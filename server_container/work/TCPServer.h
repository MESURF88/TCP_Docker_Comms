#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class TCPServer : public QTcpServer
{
  Q_OBJECT

  public:
    explicit TCPServer(QObject *parent=0);
    
    //Start the server
    void StartServer();

  signals:

  public slots:
	void newConnection();

  protected:

  private:
    QTcpServer *qserver = nullptr;
	int port = 1234;
};