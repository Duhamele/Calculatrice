#ifndef MATH_H
#define MATH_H
#include <sys/types.h>

enum class TypeNumber: u_int8_t{
    Float,
    Int,

};

inline bool isInt(TypeNumber type){
    return type==TypeNumber::Int;
}
class NumberDynamy{






private:
    TypeNumber type;
    union {
        float Float;
        int Int;
    };
public:
    inline NumberDynamy(int number):type(TypeNumber::Int),Int(number){};
    inline NumberDynamy(float number):type(TypeNumber::Float),Float(number){};
    NumberDynamy operator+(NumberDynamy other){
        if(isInt(this->type)&&isInt(other.type)){
            return NumberDynamy(this->Int+other.Int);
        }
        float val1=isInt(this->type)?static_cast<float>(this->Int):this->Float,
            val2=isInt(other.type)?static_cast<float>(other.Int):other.Float;
        return NumberDynamy(val1+val2);
    };
    NumberDynamy operator-(NumberDynamy other){
        if(isInt(this->type)&&isInt(other.type)){
            return NumberDynamy(this->Int-other.Int);
        }
        float val1=isInt(this->type)?static_cast<float>(this->Int):this->Float,
            val2=isInt(other.type)?static_cast<float>(other.Int):other.Float;
        return NumberDynamy(val1-val2);
    };

};




#endif // MATH_H
