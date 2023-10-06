#include "qt_ui_pro.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_UI_Pro w;
    w.show();
    return a.exec();
}
