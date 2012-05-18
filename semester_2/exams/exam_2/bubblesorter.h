#pragma once

template<class T>
class BubbleSorter
{
public:
	template<class C>
	void sort(T array[], int size, C const &comparator);
protected:
	void swap(T &a, T &b);
};

template<class T>
void BubbleSorter<T>::swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T>
template<class C>
void BubbleSorter<T>::sort(T array[], int size, C const &comparator)
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < size - 1; ++i)
			if (comparator(array[i + 1], array[i]) < 0)
			{
				swap(array[i], array[i + 1]);
				flag = true;
			}
	}
}
