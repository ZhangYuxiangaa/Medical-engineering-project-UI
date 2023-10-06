#ifndef SERIAL_PORT_CONTROL_H
#define SERIAL_PORT_CONTROL_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QTimer>

class serial_port_control : public QObject
{
    Q_OBJECT
public:
    explicit serial_port_control(QObject *parent = nullptr);

    void init_serial();

    QSerialPort *serial;

    void test_timer();


signals:
    void update_flow_data(QString data);

public slots:

    // 读取串口接收数据
    void serialPortReadyRead();
};

#endif // SERIAL_PORT_CONTROL_H
