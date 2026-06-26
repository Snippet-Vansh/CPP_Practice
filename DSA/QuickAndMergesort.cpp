#include <vector>

void mergeSort(std::vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    std::vector<int> temp;
    temp.reserve(r - l + 1);

    int i = l;
    int j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= r)
    {
        temp.push_back(arr[j++]);
    }

    for (int k = 0; k < static_cast<int>(temp.size()); ++k)
    {
        arr[l + k] = temp[k];
    }
}
