#include <iostream>
typedef int anytype;
//template <class anytype>
class dataclass{
public:
	anytype coef;//指数
	anytype exp;//系数
	dataclass();
	dataclass(anytype coef,anytype exp);
	bool operator <=(dataclass *another);
};
