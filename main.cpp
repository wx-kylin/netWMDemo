#include "mainwindow.h"

#include <QApplication>
#include "xatom-helper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // 添加窗管协议
    MotifWmHints hints;
    hints.flags = MWM_HINTS_FUNCTIONS|MWM_HINTS_DECORATIONS;
    hints.functions = MWM_FUNC_ALL;
    hints.decorations = MWM_DECOR_BORDER;
    XAtomHelper::getInstance()->setWindowMotifHint(w.winId(), hints);

    struct UnityCorners corner;
    corner.topLeft = 5;
    corner.topRight = 5;
    corner.bottomLeft = 5;
    corner.bottomRight = 5;
    XAtomHelper::getInstance()->setWindowBorderRadius(w.winId(), corner);
    XAtomHelper::getInstance()->setTitlebarValue(w.winId(), 55);
    w.show();
    XAtomHelper::getInstance()->setTitlebarValue(w.winId(), 56);
    return a.exec();
}
