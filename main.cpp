#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int linearSearch(vector<int> &arr, int x);
int binarySearch(vector<int> &arr, int x);

int main() {
    cout << "Hello World!";
    return 0;
}

int linearSearch(vector<int> &arr, int x){

    int return_index = -1;

    auto start = high_resolution_clock::now();

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == x)
        //cout << i+1 << " comparisons" << endl;
        return_index = i;
    }
    //cout << arr.size(); << " comparisons" << endl;

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);
    cout << duration.count();

    return return_index;;

}

int binarySearch(vector<int> &arr, int x){
    sort(arr.begin(), arr.end());

    auto start = high_resolution_clock::now();

    int low = 0;
    int high = arr.size() - 1;
    int result_index = -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == x)
        {
            result_index = mid; 
            break;           
        }

        if(arr[mid] < x)
        {
            low = mid + 1;
        }
        
        if(arr[mid] > x)
        {
            high = mid - 1;
        }
    }

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);
    cout << duration.count();

    return result_index;


}

