#include <iostream>
typedef int anytype;
//template <class anytype>
class dataclass{
public:
	anytype coef;//ָ��
	anytype exp;//ϵ��
	dataclass();
	dataclass(anytype coef,anytype exp);
	bool operator <=(dataclass *another);
};
