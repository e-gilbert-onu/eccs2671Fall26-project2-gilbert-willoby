#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int linearSearch(vector<int>& arr, int x);
int binarySearch(vector<int> &arr, int x);
void fillVec(vector<int>& arr);
void linearOutput();

int vecSize = 1000000;
int range = 3*vecSize;
int linearComparisons = 0;

//main -- 
/*Fill each array with random integers, with new values for every run. The values must be in the range [−3n, 3n], where n
*is the array size. For example, an array of size 100 holds values from −300 to 300. */
int main() {
    //Fill array/vector
    int linearTotal = 0;

    //Linear Search Final Output:
    linearOutput();
    for(int i = 1; i < 6;i++){
        std::vector<int> vec(vecSize);
        fillVec(vec);
        vec[vecSize-1] = 10;
        int runTime = linearSearch(vec,10);
        cout << "search time for run #"<< i << ": " << runTime << " us " << endl;
        linearTotal += runTime;
    }
    int linearAvg = linearTotal/5;
    cout << "average search time: " << linearAvg << " us "<< endl;
    cout << "# of comparisons made: " << linearComparisons << endl;
    cout << "******************************" << endl;


}

void fillVec(vector<int>& arr){
    //seed random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    //set ranges
    std::uniform_int_distribution<> dis(-range, range);

    for (int& i : arr) {
    i = dis(gen);
    }

    /*
    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
    cout << arr[i] << ",";
    } 
    */

}

void linearOutput(){
    // linear search output setup:
    cout << "******************************" << endl;
    cout << "Linear Search:" << endl;
    cout << "-------------------" << endl;
    cout << "Input Size = " << vecSize << endl;
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

    duration<double, std::micro> duration = (end - start);
    //cout << fixed << duration.count() << " us ";

    return duration.count();

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

    duration<double, std::micro> duration = (end - start);
    cout << fixed << setprecision(3) << "binary duration = " << duration.count() << " us ";

    return result_index;


}


