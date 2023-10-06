#include "qt_ui_pro.h"

Qt_UI_Pro::Qt_UI_Pro(QWidget *parent)
    : QWidget(parent)
{
    init_UI();
}


void Qt_UI_Pro::init_UI()
{
    this->setStyleSheet("background-color: rgb(220, 210, 190);");

    this->setWindowFlags(Qt::Window);
    this->showFullScreen();

    QGridLayout *main_layout = new QGridLayout(this);
    main_layout->setContentsMargins(2, 2, 2, 2);

    QWidget* upper_button_widget = create_upper_button_widget();
    QWidget* center_widget = create_center_widget();
    QWidget* right_button_widget = create_right_button_widget();
    QWidget* right_down_widget = create_right_down_widget();

    right_button_widget->setFixedWidth(120);
    right_down_widget->setFixedWidth(120);

    main_layout->addWidget(upper_button_widget, 0, 0, 1, 5);
    main_layout->addWidget(center_widget, 1, 0, 3, 4);
    main_layout->addWidget(right_button_widget, 1, 4, 2, 1);
    main_layout->addWidget(right_down_widget, 3, 4, 1, 1);

    QTimer *m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Qt_UI_Pro::update_time_widget);
    m_timer->start(10);

}

// 创建上面的按钮
QWidget* Qt_UI_Pro::create_upper_button_widget()
{
    QWidget *upper_blue_widget = new QWidget();
    QGridLayout *upper_blue_widget_layout = new QGridLayout(upper_blue_widget);

    upper_blue_widget_layout->setContentsMargins(10, 2, 10, 2);
    upper_blue_widget_layout->setSpacing(20);

    upper_blue_widget->setStyleSheet("background-color: rgb(2, 15, 168);");

    // 设置上面按钮界面高度
    upper_blue_widget->setFixedHeight(90);

    QPushButton *button_1 = create_button("准备完成\n停止",
                                          "background-color: rgb(193, 219, 255);",
                                          "color: rgb(53, 68, 127);",
                                          5, 250, 80);

    QPushButton *button_2 = create_button("准备",
                                          "background:qlineargradient(x1:0, y1:0, x2:0.5, y2:1,stop:0 rgb(189, 212, 253), stop: 1 rgb(0, 117, 78));",
                                          "color: rgb(0, 0, 0);",
                                          5,  120, 80);

    QPushButton *button_3 = create_button("治疗",
                                          "background:qlineargradient(x1:0, y1:0, x2:0.5, y2:1,stop:0 rgb(130, 166, 226), stop: 1 rgb(56, 103, 204));",
                                          "color: rgb(255, 255, 255);",
                                          5, 120, 80);

    QPushButton *button_4 = create_button("旁通\n自动",
                                          "background:qlineargradient(x1:0, y1:0, x2:0.5, y2:1,stop:0 rgb(189, 212, 253), stop: 1 rgb(0, 117, 78));",
                                          "color: rgb(0, 0, 0);",
                                          5, 120, 80);

    QPushButton *button_5 = create_button("排液",
                                          "background:qlineargradient(x1:0, y1:0, x2:0.5, y2:1,stop:0 rgb(130, 166, 226), stop: 1 rgb(56, 103, 204));",
                                          "color: rgb(255, 255, 255);",
                                          5, 120, 80);

    QPushButton *button_6 = create_button("清洗",
                                          "background:qlineargradient(x1:0, y1:0, x2:0.5, y2:1,stop:0 rgb(132, 179, 253), stop: 1 rgb(0, 115, 254));",
                                          "color: rgb(53, 68, 127);",
                                          5, 120, 80);


    QWidget *time_widget = create_time_widget();

    QPushButton *button_7 = create_button("退出",
                                          "background-color: rgb(221, 178, 84);",
                                          "color: rgb(0, 0, 0);",
                                          0, 60, 30);

    QWidget *blank_widget = new QWidget();
    blank_widget->setStyleSheet("background-color: rgb(221, 178, 84);color: rgb(0, 0, 0);border-radius:40px;");
    blank_widget->setFixedSize(120, 80);

    QGridLayout *blank_widget_layout = new QGridLayout(blank_widget);
    blank_widget_layout->addWidget(button_7, 0, 0, 1, 1);

    connect(button_7, &QPushButton::clicked,this, &Qt_UI_Pro::upper_button_7_clicked);

    upper_blue_widget_layout->addWidget(button_1, 0, 0, 1, 1);
    upper_blue_widget_layout->addWidget(button_2, 0, 1, 1, 1);
    upper_blue_widget_layout->addWidget(button_3, 0, 2, 1, 1);
    upper_blue_widget_layout->addWidget(button_4, 0, 3, 1, 1);
    upper_blue_widget_layout->addWidget(button_5, 0, 4, 1, 1);
    upper_blue_widget_layout->addWidget(button_6, 0, 5, 1, 1);
    upper_blue_widget_layout->addWidget(time_widget, 0, 6, 1, 1);
    upper_blue_widget_layout->addWidget(blank_widget, 0, 7, 1, 1);

    return upper_blue_widget;
}

// 创建中间界面
QWidget* Qt_UI_Pro::create_center_widget()
{
  QWidget* center_widget = new QWidget();
  QGridLayout* center_widget_layout = new QGridLayout(center_widget);
  center_widget->setStyleSheet("background-color: rgb(146, 192, 254);border-radius:10px;");

  QWidget* center_widget_top = new QWidget();
  QGridLayout* center_widget_top_layout = new QGridLayout(center_widget_top);
  center_widget_top->setStyleSheet("background-color: rgb(43, 147, 246);border-radius:10px;");

  center_widget_top_layout->setContentsMargins(5, 5, 2, 2);

  QWidget*center_widget_1 = create_center_widget_1();
  QWidget*center_widget_2 = create_center_widget_2();
  QTabWidget*center_widget_3 = create_center_widget_3();
  QWidget*center_widget_4 = create_center_widget_4();

  QPushButton *cener_button_1 = create_button("条形图",
                                        "background:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 rgb(183, 219, 251), stop: 1 rgb(0, 88, 246));",
                                        "color: rgb(34, 56, 158);",
                                        10, 110, 30);

  QPushButton *cener_button_2 = create_button("液面调整",
                                        "background:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 rgb(183, 219, 251), stop: 1 rgb(0, 88, 246));",
                                        "color: rgb(34, 56, 158);",
                                        10, 110, 30);

  QGridLayout *button_layout_1 = new QGridLayout();
  button_layout_1->setContentsMargins(10, 10, 0, 0);
  button_layout_1->setAlignment(Qt::AlignBottom);
  button_layout_1->addWidget(cener_button_1, 0, 0, 1, 1);
  button_layout_1->addWidget(cener_button_2, 0, 1, 1, 1);

  QPushButton *cener_button_3 = create_button("除水",
                                        "background:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 rgb(183, 219, 251), stop: 1 rgb(0, 88, 246));",
                                        "color: rgb(34, 56, 158);",
                                        10, 100, 40);

  QPushButton *cener_button_4 = create_button("透析液",
                                        "background:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 rgb(183, 219, 251), stop: 1 rgb(0, 88, 246));",
                                        "color: rgb(34, 56, 158);",
                                        10, 100, 40);

  QPushButton *cener_button_5 = create_button("单针",
                                        "background:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 rgb(183, 219, 251), stop: 1 rgb(0, 88, 246));",
                                        "color: rgb(34, 56, 158);",
                                        10, 100, 40);


  QLabel *blank_label = new QLabel();
  blank_label->setFixedWidth(120);

  QGridLayout *button_layout_2 = new QGridLayout();
  button_layout_2->setContentsMargins(10, 0, 0, 0);
  button_layout_2->setAlignment(Qt::AlignBottom);
  button_layout_2->setSpacing(30);
  button_layout_2->setVerticalSpacing(2);
  button_layout_2->addWidget(cener_button_3, 0, 0, 1, 1);
  button_layout_2->addWidget(cener_button_4, 0, 1, 1, 1);
  button_layout_2->addWidget(blank_label, 0, 2, 1, 1);
  button_layout_2->addWidget(cener_button_5, 0, 3, 1, 1);


  center_widget_layout->addWidget(center_widget_1, 0, 0, 3, 4);
  center_widget_layout->addWidget(center_widget_2, 3, 0, 3, 4);
  center_widget_layout->addWidget(center_widget_3, 8, 0, 2, 9);
  center_widget_layout->addWidget(center_widget_4, 0, 4, 6, 5);

  center_widget_layout->addLayout(button_layout_1, 6, 1, 1, 3);
  center_widget_layout->addLayout(button_layout_2, 6, 4, 1, 4);

  center_widget_top_layout->addWidget(center_widget);

  return center_widget_top;
}

QWidget* Qt_UI_Pro::create_center_widget_1()
{
    QWidget* center_widget_1 = new QWidget();
    QGridLayout* center_widget_1_layout = new QGridLayout(center_widget_1);
    center_widget_1_layout->setAlignment(Qt::AlignTop);
    center_widget_1_layout->setVerticalSpacing(20);
    center_widget_1->setStyleSheet("background-color: rgb(184, 213, 252);");

    QFont m_font;
    m_font.setPointSize(18);
    QLabel *tip_label = new QLabel("A液选择");
    tip_label->setFont(m_font);


    center_widget_1_layout->addWidget(tip_label, 0, 0, 1 ,1);

    QCheckBox *check_box_1 = new QCheckBox("\t\t\t\tk + 2.0 mmmol/L");
    QCheckBox *check_box_2 = new QCheckBox("\t\t\t\tk + 2.5 mmmol/L");
    QCheckBox *check_box_3 = new QCheckBox("\t\t\t\tk + 3.0 mmmol/L");

    check_box_1->setFont(m_font);
    check_box_2->setFont(m_font);
    check_box_3->setFont(m_font);

    center_widget_1_layout->addWidget(tip_label, 0, 0, 1, 1);
    center_widget_1_layout->addWidget(check_box_1, 1, 0, 1, 1);
    center_widget_1_layout->addWidget(check_box_2, 2, 0, 1, 1);
    center_widget_1_layout->addWidget(check_box_3, 3, 0, 1, 1);

    return center_widget_1;
}

QWidget* Qt_UI_Pro::create_center_widget_2()
{
    QWidget* center_widget_2 = new QWidget();
    QGridLayout* center_widget_2_layout = new QGridLayout(center_widget_2);

    center_widget_2_layout->setSpacing(20);
    center_widget_2_layout->setVerticalSpacing(20);

    center_widget_2->setStyleSheet("background-color: rgb(146, 192, 254);");

    QWidget* left_show_widget_1 = create_left_show_widget("电导度\nmS/cm", "14.2");
    QWidget* left_show_widget_2 = create_left_show_widget("B 电导度\nmS/cm", "3.26");
    QWidget* left_show_widget_3 = create_left_show_widget("温度\n°C", "33.9");

    QProgressBar *bar_1 = new QProgressBar();
    QProgressBar *bar_2 = new QProgressBar();

    bar_1->setTextVisible(false);
    bar_2->setTextVisible(false);

    bar_1->setStyleSheet("QProgressBar{background: rgb(232, 237, 253);border: none;border-radius:0px;}QProgressBar::chunk {border: none;background:qlineargradient(x1:0, y1:0, x2:0.5, y2:1,stop:0 rgb(217, 218, 251), stop: 1 rgb(121, 147, 234));}");
    bar_2->setStyleSheet("QProgressBar{background: rgb(232, 237, 253);border: none;border-radius:0px;}QProgressBar::chunk {border: none;background:qlineargradient(x1:0, y1:0, x2:0.5, y2:1,stop:0 rgb(217, 218, 251), stop: 1 rgb(121, 147, 234));}");

    bar_1->setValue(60);
    bar_2->setValue(20);

    QFont m_font;
    m_font.setPointSize(10);
    m_font.setBold(true);

    QLabel *bar_1_start_label = new QLabel("12.0");
    QLabel *bar_1_end_label = new QLabel("16.0");

    QLabel *bar_2_start_label = new QLabel("2.0");
    QLabel *bar_2_end_label = new QLabel("8.0");

    bar_1_start_label->setFont(m_font);
    bar_1_end_label->setFont(m_font);
    bar_2_start_label->setFont(m_font);
    bar_2_end_label->setFont(m_font);

    bar_1_start_label->setStyleSheet("color: rgb(21, 67, 162);");
    bar_1_end_label->setStyleSheet("color: rgb(21, 67, 162);");
    bar_2_start_label->setStyleSheet("color: rgb(21, 67, 162);");
    bar_2_end_label->setStyleSheet("color: rgb(21, 67, 162);");

    center_widget_2_layout->addWidget(left_show_widget_1, 0, 0, 2, 1);
    center_widget_2_layout->addWidget(left_show_widget_2, 2, 0, 2, 1);
    center_widget_2_layout->addWidget(left_show_widget_3, 4, 0, 2, 1);

    center_widget_2_layout->addWidget(bar_1, 0, 1, 1, 7);
    center_widget_2_layout->addWidget(bar_1_start_label, 1, 1, 1, 1);
    center_widget_2_layout->addWidget(bar_1_end_label, 1, 7, 1, 1);

    center_widget_2_layout->addWidget(bar_2, 2, 1, 1, 7);
    center_widget_2_layout->addWidget(bar_2_start_label, 3, 1, 1, 1);
    center_widget_2_layout->addWidget(bar_2_end_label, 3, 7, 1, 1);

    return center_widget_2;
}

QTabWidget* Qt_UI_Pro::create_center_widget_3()
{
    QTabWidget* center_widget_3 = new QTabWidget();



//    156, 188, 255
    center_widget_3->setStyleSheet("QTabWidget::pane {border: 0px;}\
                                  QTabBar::tab:selected{background:qlineargradient(x1:0, y1:0, x2:0, y2:0.4,stop:0 rgb(164, 66, 147), stop: 0.4 rgb(206, 180, 253));}\
                                  QTabBar::tab:last:!selected{background:qlineargradient(x1:0, y1:0, x2:0.0, y2:0.2,stop:0 rgb(0, 88, 246), stop: 1 rgb(183, 219, 251));}\
                                  QTabBar::tab:first:!selected{background:qlineargradient(x1:0, y1:0, x2:0.0, y2:0.2,stop:0 rgb(0, 88, 246), stop: 1 rgb(183, 219, 251));}");



   QWidget* center_widget_3_tab_1 = new QWidget();
   QWidget* center_widget_3_tab_2 = new QWidget();

   center_widget_3_tab_1->setObjectName("center_widget_3_tab_1");
   center_widget_3_tab_2->setObjectName("center_widget_3_tab_2");
   center_widget_3_tab_1->setStyleSheet("background-color:rgb(206, 180, 253);border-radius:0px;");
   center_widget_3_tab_2->setStyleSheet("background-color:rgb(206, 180, 253);border-radius:0px;");

   QGridLayout *center_widget_3_tab_1_layout = new QGridLayout(center_widget_3_tab_1);
   center_widget_3_tab_1_layout->setAlignment(Qt::AlignLeft);

   QLabel *image_label = new QLabel();
//   image_label->setPixmap(QPixmap(":/res/danger.png"));
   QLabel *tip_label = new QLabel("E156 请确认原液供给情况");

   QFont m_font;
   m_font.setPointSize(15);
   m_font.setBold(true);

   tip_label->setFont(m_font);
   tip_label->setStyleSheet("color: rgb(212, 101, 172);");

   center_widget_3_tab_1_layout->addWidget(image_label, 0, 0, 3, 2);
   center_widget_3_tab_1_layout->addWidget(tip_label, 0, 3, 1, 2);

    center_widget_3->addTab(center_widget_3_tab_1, "报警");
    center_widget_3->addTab(center_widget_3_tab_2, "指南");




    return center_widget_3;
}

// 右边布局设置
QWidget* Qt_UI_Pro::create_center_widget_4()
{
    QWidget* center_widget_4 = new QWidget();
    QGridLayout* center_widget_4_layout = new QGridLayout(center_widget_4);
    center_widget_4->setObjectName("center_widget_4");

    center_widget_4->setStyleSheet("#center_widget_4{border:2px solid rgb(70, 118, 203);background-color: rgb(213, 239, 248);}");

    QWidget* center_widget_4_1 = create_center_widget_4_1();
    QWidget* center_widget_4_2 = create_center_widget_4_2();
    QWidget* center_widget_4_3 = create_center_widget_4_3();

    center_widget_4_layout->addWidget(center_widget_4_1, 0, 0, 1, 1);
    center_widget_4_layout->addWidget(center_widget_4_2, 1, 0, 1, 1);
    center_widget_4_layout->addWidget(center_widget_4_3, 2, 0, 1, 1);

    return center_widget_4;
}

QWidget* Qt_UI_Pro::create_center_widget_4_1()
{
    QWidget* center_widget_4_1 = new QWidget();
    QGridLayout* center_widget_4_1_layout = new QGridLayout(center_widget_4_1);
    center_widget_4_1->setObjectName("center_widget_4_1");
    center_widget_4_1->setStyleSheet("#center_widget_4_1{border:2px solid rgb(70, 118, 203);background-color: rgb(184, 213, 252);}");

    QFont m_font;
    m_font.setBold(true);
    m_font.setPointSize(20);

    QLabel *label_1 = new QLabel("K+量");
    m_font.setPointSize(20);
    label_1->setFont(m_font);
    label_1->setStyleSheet("background-color: transparent;");

    QLabel *label_2 = new QLabel("2.  13");
    m_font.setPointSize(40);
    label_2->setFont(m_font);
    label_2->setStyleSheet("color: rgb(194, 180, 42);background-color: transparent;");

    QLabel *label_3 = new QLabel("mmol/L");
    m_font.setPointSize(15);
    label_3->setFont(m_font);
    label_3->setStyleSheet("background-color: transparent;");

    QLabel *label_4 = new QLabel("流量");
    m_font.setPointSize(20);
    label_4->setFont(m_font);
    label_4->setStyleSheet("background-color: transparent;");


    QLabel *label_5 = new QLabel("18.  34");
    m_font.setPointSize(40);
    label_5->setFont(m_font);
    label_5->setStyleSheet("color: rgb(63, 118, 154);background-color: transparent;");

    QLabel *label_6 = new QLabel("mL/s");
    m_font.setPointSize(15);
    label_6->setFont(m_font);
    label_6->setStyleSheet("background-color: transparent;");


    center_widget_4_1_layout->addWidget(label_1, 0, 0, 1, 1);
    center_widget_4_1_layout->addWidget(label_2, 1, 1, 1, 3);
    center_widget_4_1_layout->addWidget(label_3, 2, 3, 1, 1);

    center_widget_4_1_layout->addWidget(label_4, 0, 4, 1, 1);
    center_widget_4_1_layout->addWidget(label_5, 1, 5, 1, 3);
    center_widget_4_1_layout->addWidget(label_6, 2, 7, 1, 1);

    return center_widget_4_1;
}

QWidget* Qt_UI_Pro::create_center_widget_4_2()
{
    QWidget* center_widget_4_2 = new QWidget();
    QGridLayout* center_widget_4_2_layout = new QGridLayout(center_widget_4_2);

    center_widget_4_2->setObjectName("center_widget_4_2");

    center_widget_4_2->setStyleSheet("#center_widget_4_2{border:2px solid rgb(70, 118, 203);background-color: rgb(184, 213, 252);}");

    QFont m_font;
    m_font.setBold(true);
    m_font.setPointSize(20);

    QLabel *label_1 = new QLabel("除水时间");
    m_font.setPointSize(30);
    label_1->setFont(m_font);
    label_1->setStyleSheet("background-color: transparent;color: rgb(0, 11, 101);");

    QLabel *label_2 = new QLabel("4:00");
    m_font.setPointSize(60);
    label_2->setFont(m_font);
    label_2->setStyleSheet("color: rgb(194, 180, 42);background-color: transparent;color: rgb(3, 33, 184);");

    QLabel *label_3 = new QLabel("h:min");
    m_font.setPointSize(15);
    label_3->setFont(m_font);
    label_3->setStyleSheet("background-color: transparent;color: rgb(3, 33, 184);");

    QLabel *label_4 = new QLabel("除水速度");
    m_font.setPointSize(30);
    label_4->setFont(m_font);
    label_4->setStyleSheet("background-color: transparent;color: rgb(0, 11, 101);");


    QLabel *label_5 = new QLabel("0:00");
    m_font.setPointSize(60);
    label_5->setFont(m_font);
    label_5->setStyleSheet("color: rgb(63, 118, 154);background-color: transparent;color: rgb(3, 33, 184);");

    QLabel *label_6 = new QLabel("L/h");
    m_font.setPointSize(15);
    label_6->setFont(m_font);
    label_6->setStyleSheet("background-color: transparent;color: rgb(3, 33, 184);");

    center_widget_4_2_layout->addWidget(label_1, 0, 0, 1, 3);
    center_widget_4_2_layout->addWidget(label_2, 1, 1, 1, 3);
    center_widget_4_2_layout->addWidget(label_3, 2, 2, 1, 1);

    center_widget_4_2_layout->addWidget(label_4, 0, 4, 1, 3);
    center_widget_4_2_layout->addWidget(label_5, 1, 5, 1, 3);
    center_widget_4_2_layout->addWidget(label_6, 2, 7, 1, 1);

    return center_widget_4_2;
}

QWidget* Qt_UI_Pro::create_center_widget_4_3()
{
    QWidget* center_widget_4_3 = new QWidget();
    QGridLayout* center_widget_4_3_layout = new QGridLayout(center_widget_4_3);

    center_widget_4_3_layout->setContentsMargins(30, 10, 10, 10);
    center_widget_4_3_layout->setSpacing(15);

    center_widget_4_3->setObjectName("center_widget_4_3");
    center_widget_4_3->setStyleSheet("#center_widget_4_3{border:2px solid rgb(70, 118, 203);background-color: rgb(184, 206, 255);}");

    QFont m_font;
    m_font.setBold(true);
    m_font.setPointSize(20);

    QLabel *label_1 = new QLabel("低钾电磁阀");
    QLabel *label_2 = new QLabel("中钾电磁阀");
    QLabel *label_3 = new QLabel("高钾电磁阀");

    label_1->setStyleSheet("background-color: rgb(184, 206, 255);color: rgb(25, 28, 27);border-radius:0px;");
    label_2->setStyleSheet("background-color: rgb(184, 206, 255);color: rgb(25, 28, 27);border-radius:0px;");
    label_3->setStyleSheet("background-color: rgb(184, 206, 255);color: rgb(25, 28, 27);border-radius:0px;");

    label_1->setFont(m_font);
    label_2->setFont(m_font);
    label_3->setFont(m_font);

    label_1->setFixedWidth(150);
    label_2->setFixedWidth(150);
    label_3->setFixedWidth(150);


    QLabel *label_4 = new QLabel("开");
    QLabel *label_5 = new QLabel("开");
    QLabel *label_6 = new QLabel("关");

    label_4->setStyleSheet("background-color: rgb(184, 206, 255);color: rgb(47, 105, 1);border-radius:0px;");
    label_5->setStyleSheet("background-color: rgb(184, 206, 255);color: rgb(47, 105, 1);border-radius:0px;");
    label_6->setStyleSheet("background-color: rgb(184, 206, 255);color: rgb(47, 105, 1);border-radius:0px;");

    m_font.setPointSize(30);
    label_4->setFont(m_font);
    label_5->setFont(m_font);
    label_6->setFont(m_font);

    center_widget_4_3_layout->addWidget(label_1, 0, 0, 1, 5);
    center_widget_4_3_layout->addWidget(label_2, 0, 5, 1, 5);
    center_widget_4_3_layout->addWidget(label_3, 0, 10, 1, 5);

    center_widget_4_3_layout->addWidget(label_4, 1, 1, 1, 1);
    center_widget_4_3_layout->addWidget(label_5, 1, 6, 1, 1);
    center_widget_4_3_layout->addWidget(label_6, 1, 11, 1, 1);

    return center_widget_4_3;
}

//创建时间框--
QWidget *Qt_UI_Pro::create_time_widget()
{
    QWidget *time_widget = new QWidget();

    QGridLayout *time_widget_layout = new QGridLayout(time_widget);

    time_widget_layout->setContentsMargins(2, 2, 2, 2);
    time_widget->setFixedHeight(80);
    time_widget->setStyleSheet("background-color: rgb(218, 225, 254);");

    QFont font;
    font.setPixelSize(18);
    font.setBold(true);

    time_label = new QLabel();
    time_label->setFont(font);
    time_label->setStyleSheet("color:rgb(16, 24, 86);");

//    QCheckBox *checkbox = new QCheckBox("空");
//    checkbox->setStyleSheet("QCheckBox{color:rgb(16, 24, 86);}QCheckBox::indicator:checked {image: url(:/res/no_check.png);}QCheckBox::indicator:unchecked {image: url(:/res/no_check.png);}");
//    checkbox->setChecked(true);
//    checkbox->setFont(font);

    time_widget_layout->addWidget(time_label, 0, 0, 3, 1);
//    time_widget_layout->addWidget(checkbox, 3, 0, 2, 1);

    return time_widget;
}


// 创建右边的按钮区域
QWidget* Qt_UI_Pro::create_right_button_widget()
{
    QWidget *right_button_widget = new QWidget();
    QGridLayout *right_button_widget_layout = new QGridLayout(right_button_widget);

    right_button_widget_layout->setContentsMargins(2, 2, 2, 2);
    right_button_widget->setStyleSheet("background-color: rgb(2, 15, 168);");

    QPushButton *right_button_1 = create_button("预览支持",
                                          "background:qlineargradient(x1:0, y1:0, x2:0.5, y2:1,stop:0 rgb(183, 219, 251), stop: 1 rgb(0, 88, 246));",
                                          "color: rgb(34, 56, 158);",
                                          5, 110, 60);

    QPushButton *right_button_2 = create_button("应急处置",
                                          "background:qlineargradient(x1:0, y1:0, x2:0.5, y2:1,stop:0 rgb(183, 219, 251), stop: 1 rgb(0, 88, 246));",
                                          "color: rgb(34, 56, 158);",
                                          5, 110, 60);

    QPushButton *right_button_3 = create_button("HP(20ml)\n0.0",
                                          "background:qlineargradient(x1:0, y1:0, x2:0.5, y2:1,stop:0 rgb(183, 219, 251), stop: 1 rgb(0, 88, 246));",
                                          "color: rgb(34, 56, 158);",
                                          5, 110, 60);

    QPushButton *right_button_4 = create_button("血压计\n---/---",
                                          "background:qlineargradient(x1:0, y1:0, x2:0.5, y2:1,stop:0 rgb(183, 219, 251), stop: 1 rgb(0, 88, 246));",
                                          "color: rgb(34, 56, 158);",
                                          5, 110, 60);

    QPushButton *right_button_5 = create_button("系统",
                                          "background:qlineargradient(x1:0, y1:0, x2:0.5, y2:1,stop:0 rgb(183, 219, 251), stop: 1 rgb(0, 88, 246));",
                                          "color: rgb(34, 56, 158);",
                                          5, 110, 60);

    QPushButton *right_button_6 = create_button("功能",
                                          "background:qlineargradient(x1:0, y1:0, x2:0.5, y2:1,stop:0 rgb(183, 219, 251), stop: 1 rgb(0, 88, 246));",
                                          "color: rgb(34, 56, 158);",
                                          5, 110, 60);

    right_button_widget_layout->addWidget(right_button_1, 0, 0, 1, 1);
    right_button_widget_layout->addWidget(right_button_2, 1, 0, 1, 1);
    right_button_widget_layout->addWidget(right_button_3, 2, 0, 1, 1);
    right_button_widget_layout->addWidget(right_button_4, 3, 0, 1, 1);
    right_button_widget_layout->addWidget(right_button_5, 4, 0, 1, 1);
    right_button_widget_layout->addWidget(right_button_6, 5, 0, 1, 1);

    return right_button_widget;
}



// 创建底部界面
QWidget* Qt_UI_Pro::create_right_down_widget()
{
    QWidget* right_down_widget = new QWidget();
    QGridLayout *right_down_widget_layout = new QGridLayout(right_down_widget);

    right_down_widget_layout->setContentsMargins(10, 5, 5, 5);
    right_down_widget_layout->setAlignment(Qt::AlignCenter);
    right_down_widget->setObjectName("right_down_widget");//
    right_down_widget->setStyleSheet("#right_down_widget{border:2px solid rgb(135, 138, 187);background-color: rgb(196, 203, 254);}");

    QFont m_font;

    QLabel *right_down_label_1 = new QLabel("血流量");
    m_font.setPointSize(15);
    right_down_label_1->setFont(m_font);
    right_down_label_1->setStyleSheet("color: rgb(76, 85, 144);background-color: transparent;");

    QLabel *right_down_label_2 = new QLabel("100");
    m_font.setPointSize(30);
    right_down_label_2->setFont(m_font);
    right_down_label_2->setStyleSheet("color: rgb(91, 97, 158);background-color: transparent;");

    QLabel *right_down_label_3 = new QLabel("mL/min");
    m_font.setPointSize(15);
    right_down_label_3->setFont(m_font);
    right_down_label_3->setStyleSheet("color: rgb(91, 97, 158);background-color: transparent;");

    QLabel *right_down_label_4 = new QLabel("血泵\n流量");
    m_font.setPointSize(25);
    right_down_label_4->setFont(m_font);
    right_down_label_4->setStyleSheet("color: rgb(195, 205, 255);background-color: rgb(114, 140, 215);border-radius:10px;");

    right_down_widget_layout->addWidget(right_down_label_1, 0, 0, 1, 1);
    right_down_widget_layout->addWidget(right_down_label_2, 1, 0, 1, 1);
    right_down_widget_layout->addWidget(right_down_label_3, 2, 0, 1, 1);
    right_down_widget_layout->addWidget(right_down_label_4, 3, 0, 2, 1);

    return right_down_widget;
}


//创建按钮函数--
QPushButton *Qt_UI_Pro::create_button(QString text, QString color, QString font_color,
                                      int radius, int width, int height)
{
    QPushButton *button = new QPushButton();


    button->setText(text);
    button->setFixedHeight(height);
    button->setFixedWidth(width);
    QFont font;
    font.setPixelSize(24);
    font.setBold(true);
    button->setFont(font);

    QString radius_Sheet = QString("border-radius: %0").arg(radius);
    QString StyleSheet = color + font_color+ radius_Sheet;

    button->setStyleSheet(StyleSheet);



//    QString normalStyle = "background-color: " + color + "; color: " + font_color + "; border-radius: " + QString::number(radius) + "px;";
    QString pressedStyle = "background-color: #CCCCCC; color: #000000; border-radius: " + QString::number(radius) + "px;";

//    button->setStyleSheet(StyleSheet);

    QObject::connect(button, &QPushButton::pressed, [button, pressedStyle]() {
        button->setStyleSheet(pressedStyle);
    });

    QObject::connect(button, &QPushButton::released, [button, StyleSheet]() {
        button->setStyleSheet(StyleSheet);
    });

    return button;
}


QWidget* Qt_UI_Pro::create_left_show_widget(QString left_text, QString right_text)
{
    QWidget* left_show_widget = new QWidget();
    QGridLayout *left_show_widget_layout = new QGridLayout(left_show_widget);

    left_show_widget->setStyleSheet("background-color: rgb(227, 227, 254);border-radius:10px;");

    QFont m_font;
    m_font.setPointSize(15);

    QLabel *label_1 = new QLabel(left_text);
    QLabel *label_2 = new QLabel(right_text);

    label_1->setStyleSheet("color: rgb(16, 81, 175);");
    label_2->setStyleSheet("color: rgb(32, 91, 122);");

    label_1->setFont(m_font);
    m_font.setPointSize(20);
    label_2->setFont(m_font);

    left_show_widget_layout->addWidget(label_1, 0, 0, 1, 1);
    left_show_widget_layout->addWidget(label_2, 0, 1, 1, 1);

    return left_show_widget;

}

// 实时更新时间
void Qt_UI_Pro::update_time_widget()
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd \nddd hh:mm").
            replace("周", "星期");

    time_label->setText(current_date);
    update();
}

//系统退出按钮执行的函数
void Qt_UI_Pro::upper_button_7_clicked()
{
    exit(0);
}

Qt_UI_Pro::~Qt_UI_Pro()
{
}

