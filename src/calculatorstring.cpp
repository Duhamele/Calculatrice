#include "calculatorstring.h"
//#include <sys/types.h>
#include <QString>
#include  <stdint.h>
#include <stdexcept>
#include "cal_math.h"
#include <span>



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
};

NumberDynamy rule_number(std::span<TokenComputeString> chaine){
    if(chaine.size()==1){
        return NumberDynamy(chaine[0].number);
    }
    if(chaine.size()==2 && chaine[0].type==TypeTokenComputeString::Sub){
        return NumberDynamy(-chaine[1].number);
    }
    return NumberDynamy(0);
}

NumberDynamy rule_mul_div(std::span<TokenComputeString> chaine){
    for(int i=1;i<chaine.size()-1;i++){
        switch (chaine[i].type) {
        case TypeTokenComputeString::Mul:
            return rule_number(chaine.subspan(0,i-1))*
                   rule_mul_div(chaine.subspan(i+1,chaine.size()-i));

            break;
        case TypeTokenComputeString::Div:
            return rule_number(chaine.subspan(0,i-1))/
                   rule_mul_div(chaine.subspan(i+1,chaine.size()-i));
        default:
            break;
        }
    }
    return rule_number(chaine);

}
NumberDynamy rule_add_sub(std::span<TokenComputeString> chaine){
    for(int i=1;i<chaine.size()-1;i++){
        switch (chaine[i].type) {
        case TypeTokenComputeString::Add:
            return rule_mul_div(chaine.subspan(0,i-1))+
                   rule_add_sub(chaine.subspan(i+1,chaine.size()-i));

            break;
        case TypeTokenComputeString::Sub:
            return rule_mul_div(chaine.subspan(0,i-1))-
                   rule_add_sub(chaine.subspan(i+1,chaine.size()-i));
        default:
            break;
        }
    }
    return rule_mul_div(chaine);
}




