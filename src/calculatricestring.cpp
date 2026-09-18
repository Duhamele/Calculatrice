#include "calculatricestring.h"
//#include <sys/types.h>
#include <QString>
#include  <stdint.h>
CalculatriceString::CalculatriceString() {}



enum class TypeTokenComputeString: std::int8_t{
    Number,
    Add,
    Sub,
    Mul,
    Div,
};

struct TokenComputeString
{
    TypeTokenComputeString type;
    union {
        int number;
    };

};


TokenComputeString QStringNumberToTokenComputeString(QString string){
    int val=string.toInt();
    return {.type=TypeTokenComputeString::Number,.number=val};
};
TokenComputeString QCharOpToTokenComputeString(QChar op){
    switch (op.toLatin1()) {
    case '/':
        return {TypeTokenComputeString::Div};
        break;
    case '+':
        return {.type=TypeTokenComputeString::Add};
        break;
    case '*':
        return {.type=TypeTokenComputeString::Mul};
        break;
    case '-':
        return {.type=TypeTokenComputeString::Add};
    default:
        throw new std::invalid_argument("");
        break;
    };
}

std::vector<TokenComputeString> TokenizerComputeString(QString string){
    QString number="";
    std::vector<TokenComputeString> array;
    for( int i=0; i<string.size();i++){
        if(string.at(i).isDigit()){
            number.append(string.at(i));
        }else{
            if(!number.isEmpty()){
                array.push_back(QStringNumberToTokenComputeString(number));
                number.clear();
            }
            array.push_back(QCharOpToTokenComputeString(string.at(i)));

        }
    }
    if(!number.isEmpty()){
        array.push_back(QStringNumberToTokenComputeString(number));
        number.clear();
    }
    return array;

}




