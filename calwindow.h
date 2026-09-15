#ifndef CALWINDOW_H
#define CALWINDOW_H

#include <QMainWindow>
#include "interface_core_cal.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class CalWindow;
}
QT_END_NAMESPACE

class CalWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalWindow(QWidget *parent = nullptr);
    ~CalWindow();

private:
    Ui::CalWindow *ui;
    Interface_core_cal *coreCal;
};
#endif // CALWINDOW_H
