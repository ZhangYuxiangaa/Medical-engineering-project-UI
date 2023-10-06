#ifndef QT_UI_PRO_H
#define QT_UI_PRO_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QTabWidget>
#include <QFont>
#include <QCheckBox>
#include <QTimer>
#include <QDateTime>
#include <QProgressBar>

#include "serial_port_control.h"

class Qt_UI_Pro : public QWidget
{
    Q_OBJECT

public:
    Qt_UI_Pro(QWidget *parent = nullptr);
    ~Qt_UI_Pro();

    void init_UI();

    QWidget* create_upper_button_widget();
    QWidget* create_right_button_widget();
    QWidget* create_right_down_widget();
    QWidget* create_center_widget();
    QWidget* create_center_widget_1();
    QWidget* create_center_widget_2();
    QTabWidget* create_center_widget_3();
    QWidget* create_center_widget_4();
    QWidget* create_center_widget_4_1();
    QWidget* create_center_widget_4_2();
    QWidget* create_center_widget_4_3();
    QWidget *create_time_widget();

    QPushButton *create_button(QString text, QString color, QString font_color,
                               int radius, int width,int height);

    QWidget* create_left_show_widget(QString left_text, QString right_text);

    // 系统退出按钮执行的函数
    void upper_button_7_clicked();


    QLabel *time_label;

    // 实时更新时间
    void update_time_widget();

    // 创建串口控制类
    serial_port_control *m_serial_port_control;


    // 更新流量数据的显示
    void update_show_flow_data(QString data);

    QLabel *flow_label_5;
};
#endif // QT_UI_PRO_H
