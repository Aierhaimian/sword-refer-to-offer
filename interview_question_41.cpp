#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 求数据流中的中位数
template<typename T>
class DynamicArray{
public:
    void insert(T num)
    {
        // 要保证数据平均分配到两个堆中
        // 则两个堆中数据的数目之差不能超过1
        // 为实现平均分配，可以在数据的总数目是偶数时把新数据插入最小堆
        // 否则插入最大堆
        if (((min.size() + max.size()) & 1) == 0) // 目前堆中数据总数目是偶数？
        {
            // 保证最大堆中所有数据都要小于最小堆中的数据
            if (max.size() > 0 && num < max[0])
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<T>());

                num = max[0];

                pop_heap(max.begin(), max.end(), less<T>());
                max.pop_back();
            }

            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<T>());
        }
        // 反之亦然
        else
        {
            if (min.size() > 0 && num > min[0])
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<T>());

                num = min[0];

                pop_heap(min.begin(), min.end(), greater<T>());
                min.pop_back();
            }

            max.push_back(num);
            push_heap(max.begin(), max.end(), less<T>());
        }
    }

    T getMedian()
    {
        int size = min.size() + max.size();
        if (size == 0)
        {
            cerr << "No number are available" << endl;
            return 0;
        }

        T median = 0;
        if((size & 1) == 1)
            median = min[0];
        else
            median = (min[0] + max[0])/2;

        return median;
    }
private:
    vector<T> min;
    vector<T> max;
};

int main()
{
    return 0;
}

