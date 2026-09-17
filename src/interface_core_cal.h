#ifndef INTERFACE_CORE_CAL_H
#define INTERFACE_CORE_CAL_H
#include <QObject>
#include <QTextEdit>

/**
 * @brief The Interface_core_cal class
 * Core logical calcul
 */
class Interface_core_cal:public QObject
{
    Q_OBJECT
public:
    Interface_core_cal(QTextEdit* output);
    /**
     * @brief addchar for equation
     * @param symbol is number or /,*,-,+.
     */
    void addchar(QChar symbol);
    /**
     * @brief remove the equation in writing
     */
    void clear();
    /**
     * @brief equal start compute
     */
    void equal();
private:
    QString string_selc;
    QString string_old;
    QTextEdit * const output;
    void updateOutput();
};

#endif // INTERFACE_CORE_CAL_H
