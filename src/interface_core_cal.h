#ifndef INTERFACE_CORE_CAL_H
#define INTERFACE_CORE_CAL_H
#include <QObject>
#include <QTextEdit>
class Interface_core_cal:public QObject
{
    Q_OBJECT
public:
    Interface_core_cal(QTextEdit* output);
    void addchar(QChar symbol);
    void clear();
    void equal();
private:
    QString string_selc;
    QString string_old;
     QTextEdit * const output;
    void updateOutput();
};

#endif // INTERFACE_CORE_CAL_H
