#include <iostream>
#include <vector>
using namespace std;

vector<int> mixedArray = {5, 4, 1, 8, 7, 2, 6, 3,-9};

vector<int> Merge(vector<int> a, vector<int> b)
{
    vector<int> c;
    int leftIndex = 0;
    int rightIndex = 0;

    while (leftIndex < a.size() && rightIndex < b.size())
    {
        if (a[leftIndex] <= b[rightIndex])
        {
            c.push_back(a[leftIndex]);
            leftIndex++;
        }
        else
        {
            c.push_back(b[rightIndex]);
            rightIndex++;
        }
    }
    if (leftIndex < a.size())
    {
        int tamp = leftIndex;
        for (size_t i = tamp; i < a.size(); i++)
        {
              c.push_back(a[i]);
        }
        
    }
    if(rightIndex < b.size()){
              int tamp = rightIndex;
        for (size_t i = tamp; i < b.size(); i++)
        {
              c.push_back(b[i]);
        }  
    }
    return c;
}

vector<int> MergeSort(vector<int> targetArray)
{

    vector<int> left;
    vector<int> right;
    // base case
    if (targetArray.size() <= 1)
        return targetArray;

    for (size_t i = 0; i < targetArray.size() / 2; i++)
    {
        left.push_back(targetArray[i]);
    }
    for (size_t i = (targetArray.size() / 2); i < targetArray.size(); i++)
    {
        right.push_back(targetArray[i]);
    }

    left = MergeSort(left);
    right = MergeSort(right);
    return Merge(left, right);
}

int main()
{
    for (size_t i = 0; i < mixedArray.size(); i++)
    {
        cout << mixedArray[i];
    }
    cout << endl;
    vector<int> orderedArray = MergeSort(mixedArray);

    for (size_t i = 0; i < orderedArray.size(); i++)
    {
        cout << orderedArray[i];
    }

    return 0;
}