#include "interface_core_cal.h"
#include "calculatorstring.h"
Interface_core_cal::Interface_core_cal(QTextEdit* output):output(output) {
    if(output==nullptr){
        throw new std::invalid_argument("Ouput invalid");
    }
}

void Interface_core_cal::addchar(QChar symvol){
    string_selc.append(symvol);
    updateOutput();
}
void Interface_core_cal::clear(){
    string_selc.clear();
    updateOutput();
}
void Interface_core_cal::updateOutput(){
    output->setText(string_selc);
}
void Interface_core_cal::equal(){
    auto val=evalString(string_selc);
    output->setText(QString(val.toString().c_str()));

    string_selc.clear();
}
