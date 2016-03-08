#include "dataclass.h"
typedef int anytype;
dataclass::dataclass()
{
	this->coef = 0;
	this->exp = 0;

}
//template <class anytype>
dataclass::dataclass(anytype exp, anytype coef)
{
	this->coef = coef;
	this->exp = exp;
}
//template <class anytype>
bool dataclass:: operator<=(dataclass *another)
{
	return (this->coef <= another->coef);
}