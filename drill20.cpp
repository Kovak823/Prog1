#include "std_lib_facilities.h"

template<typename Iter>
void increase(Iter first, Iter last, int x)
{

	while(first!=last)
	{
		*first += x;
		++first;
	}
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while(f1!=e1)
	{
		*f2 = *f1;
		++f1;
		++f2;
	}
	return f2;
}

int main()
{
	array<int, 10> int_a {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	vector<int> int_v {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	list<int> int_l {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	array<int, 10> int_a2 = int_a;
	vector<int> int_v2 = int_v;
	list<int> int_l2 = int_l;

	increase(int_a2.begin(), int_a2.end(), 2);
	increase(int_v2.begin(), int_v2.end(), 3);
	increase(int_l2.begin(), int_l2.end(), 5);

	my_copy(int_a2.begin(), int_a2.end(), int_v2.begin());
	my_copy(int_l2.begin(), int_l2.end(), int_a2.begin());

	constexpr int value = 3;
	constexpr int value2 = 27;

	auto p = find(int_v.begin(), int_v.end(), value);

	if (p != int_v.end())
        cout << "Found at: " << distance(int_v.begin(), p) << '\n';
    else
        cout << "Not found\n";

    auto p2 = find(int_l.begin(), int_l.end(), value2);

    if (p2 != int_l.end())
        cout << "Found at: " << distance(int_l.begin(), p2) << '\n';
    else
        cout << "Not found\n";

	return 0;
}