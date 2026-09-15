#include "interface_core_cal.h"

Interface_core_cal::Interface_core_cal(QTextEdit* output):output(output) {
    if(output==nullptr){
        throw new std::invalid_argument("Ouput invalid");
    }
    qDebug() << "textBrowser =" << output;
}

void Interface_core_cal::addchar(QChar symvol){
    string_selc.append(symvol);
    qDebug("fegzg");
    qDebug() << "textBrowser =" << output;
    updateOutput();
}
void Interface_core_cal::clear(){
    string_selc.clear();
    updateOutput();
}
void Interface_core_cal::updateOutput(){
    output->setText(string_selc);
}
void Interface_core_cal::equal(){}
