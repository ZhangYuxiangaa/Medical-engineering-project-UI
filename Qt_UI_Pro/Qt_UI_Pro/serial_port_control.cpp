#include "serial_port_control.h"

serial_port_control::serial_port_control(QObject *parent) : QObject(parent)
{
    init_serial();
}

// 初始化串口
void serial_port_control::init_serial()
{
    serial = new QSerialPort();
    //设置串口名
//    serial->setPortName("COM1");
    serial->setPortName("/dev/ttyUSB0");
    //设置波特率
    serial->setBaudRate(QSerialPort::Baud115200);
    //设置数据位数
    serial->setDataBits(QSerialPort::Data8);
    //设置奇偶校验
    serial->setParity(QSerialPort::NoParity);
    //设置停止位
    serial->setStopBits(QSerialPort::OneStop);
    //设置流控制
    serial->setFlowControl(QSerialPort::NoFlowControl);
    //打开串口
    bool ret = serial->open(QIODevice::ReadWrite);
    if (ret)
    {
        qDebug() << "成功打开串口";

    }
    //清空缓存
    serial->flush();

    QTimer *m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &serial_port_control::test_timer);
    m_timer->start(500);

    connect(serial,&QSerialPort::readyRead,this, &serial_port_control::serialPortReadyRead);

}

void serial_port_control::test_timer()
{
    qDebug() << "send";

    QString test_data = "0x20";

    serial->write(QByteArray::fromHex(test_data.toLatin1()));

}


// 读取串口数据
void serial_port_control::serialPortReadyRead()
{
    //读取数据
    QByteArray Serial_buff = serial->readAll();

    qDebug() << "读取数据";


    QString strDis;
    QByteArray hexData = Serial_buff.toHex();

    hexData = hexData.toUpper ();//转换为大写
    for(int i = 0;i<hexData.length ();i+=2)//填加空格
    {
        QString st = hexData.mid (i,2);
        strDis += st;
        strDis += "  ";
    }
    Serial_buff.clear();//先清空，以防已接收的部分变成乱码
    Serial_buff.append(strDis);

    emit update_flow_data(Serial_buff.data());

    qDebug() << "接收到的数据"<< Serial_buff.data();
}
