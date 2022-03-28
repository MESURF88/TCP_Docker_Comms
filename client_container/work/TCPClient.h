#include <QTcpSocket>
#include <QObject>

class TCPClient: public QObject
{
  Q_OBJECT
  
  public:
    explicit TCPClient(QObject *parent=0);
    
    //Start the client
    void StartClient(QString ipaddr, int port, int num_messages);

  signals:

  public slots:

  protected:
  
  private:
	QTcpSocket *socket = nullptr;

};