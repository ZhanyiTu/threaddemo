#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <thread>
using namespace std;

int GetSum(vector<int>::iterator first, vector<int>::iterator last)
{
    return accumulate(first, last, 0);//����C++��׼���㷨
    
}

void GetSumT(vector<int>::iterator first, vector<int>::iterator last, int &result)
{
    result = accumulate(first, last, 0); //����C++��׼���㷨
}


int fun1() {
    vector<int> largeArrays;
    for (int i = 0; i < 100000000; i++) {
        if (i % 2 == 0)
            largeArrays.push_back(i);
        else
            largeArrays.push_back(-1 * i);
    }
    int res = GetSum(largeArrays.begin(), largeArrays.end());
    return res;
}
int fun2() {
    int result1, result2, result3, result4, result5;
    vector<int> largeArrays;
    for (int i = 0; i < 100000000; i++)
    {
        if (i % 2 == 0)
            largeArrays.push_back(i);
        else
            largeArrays.push_back(-1 * i);
    }
    thread first(GetSumT, largeArrays.begin(),
        largeArrays.begin() + 20000000, std::ref(result1)); //���߳�1
    thread second(GetSumT, largeArrays.begin() + 20000000,
        largeArrays.begin() + 40000000, std::ref(result2)); //���߳�2
    thread third(GetSumT, largeArrays.begin() + 40000000,
        largeArrays.begin() + 60000000, std::ref(result3)); //���߳�3
    thread fouth(GetSumT, largeArrays.begin() + 60000000,
        largeArrays.begin() + 80000000, std::ref(result4)); //���߳�4
    thread fifth(GetSumT, largeArrays.begin() + 80000000,
        largeArrays.end(), std::ref(result5)); //���߳�5

    first.join(); //���߳�Ҫ�ȴ����߳�ִ�����
    second.join();
    third.join();
    fouth.join();
    fifth.join();
    int resultSum = result1 + result2 + result3 + result4 + result5; //���ܸ������̵߳Ľ��

    return resultSum;


}
int fun3() {
    for (int i = 0; i < 100; i++) {
        printf("%d\n", i);
    }
    return 0;
}
int main()
{
    printf("1\n");
    printf("2\n");
    printf("3\n");
    thread t1(fun3);
    //t1.detach();
    printf("4\n");
    t1.detach();
    //t1.join();
    printf("5\n");
    printf("6\n");
    system("pause");
    return 0;
}