#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > SmallestPairs(vector<int> &arr1, vector<int> &arr2, size_t k)
{
    size_t size1 = arr1.size();
    size_t size2 = arr2.size();

    vector<pair<int, int> > temp;

    priority_queue<pair<int, int>>  pq;

    int sum_top, sum_element;

    for(size_t i(0); i < size1; i++)
    {
        for(size_t j(0); j < size2; j++)
        {
            if(pq.size() < k)
            {
                pq.push(make_pair(arr1[i], arr2[j]));
            }
            else
            {
                sum_element = arr1[i] + arr2[j];
                sum_top = pq.top().first + pq.top().second;

                if(sum_element < sum_top)
                {
                    pq.pop();
                    pq.push(make_pair(arr1[i], arr2[j]));
                }
            }
        }
    }

    while (pq.size() > 0)
    {
        temp.push_back(pq.top());
        pq.pop();
    }

    return temp;
}

int main()
{
    vector<int>     array1;
    vector<int>     array2;

    size_t k = 3;

    for(int i(0); i < 10; i++)
    {
        array1.push_back(rand() % 100);
        array2.push_back(rand() % 100);
    }

    cout << "Array 1:";
    for(int i : array1)
        cout << i << "\t";

    cout << endl << "Array 2:";
    for(int i : array2)
        cout << i << "\t";

    vector<pair<int, int> > smallest = SmallestPairs(array1, array2, k);

    cout << endl << "Smallest " << k << "pairs";

    for(auto val : smallest)
    {
        cout << "(" << val.first << "," << val.second << ")" << endl;
    }

    return 0;
}
