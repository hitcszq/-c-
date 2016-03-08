#include <cstdlib>
#include <cstring>
#include <iostream> 
#include <stdexcept>


//
// 希尔排序函数模版. 
//
template <typename T>
void shellSort(T *array, int first, int last)
{

	int LENGTH = last - first + 1;
	int gap = LENGTH, i, j;
	T temp;

	do {
		gap = gap / 3 + 1;
		// 内层循环是直接插入排序，只是各相邻排序元素间隔为 gap. 
		for (i = gap; i < LENGTH; i += gap)
		{
			temp = array[i];
			for (j = i; j >= gap && temp < array[j - gap]; j -= gap)
			{
				array[j] = array[j - gap];
			}
			if (j >= 0) {
				array[j] = temp;
			}
		}
	} while (gap > 1);
}

//
// 测试.
//
int main(void)
{
	
	int iarrTest[] = { 23, 12, 2, 123, 72, 35, 49, 51, 83, 94, 65 };
	const size_t INT_ARR_SIZE = sizeof(iarrTest) / sizeof(iarrTest[0]);

	shellSort(iarrTest, 0, INT_ARR_SIZE - 1);


	for (size_t i = 0; i < INT_ARR_SIZE; ++i)
	{
		std::cout << iarrTest[i] << " ";
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}