#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int linearSearch(vector<int>& arr, int x, int& comparisons, double& searchTime);
int binarySearch(vector<int> &arr, int x, int& comparisons, double& sortingTime, double& searchTime);
void fillVec(vector<int>& arr);
void linearHeader();
void binaryHeader();

int vecSize = 1000000;
int range = 3*vecSize;
int key = range + 1;


//main -- 
/*Fill each array with random integers, with new values for every run. The values must be in the range [−3n, 3n], where n
*is the array size. For example, an array of size 100 holds values from −300 to 300. */

int main() {
    cout << fixed << setprecision(3);
    double linearTotal = 0;
    double binaryTotal = 0;
    int comparisons  = 0;
    double sortingTime = 0;

    //Linear Search Final Output:
    linearHeader(); //header
     
    for(int i = 1; i < 6;i++){ //runtime + avg calc
        std::vector<int> vec(vecSize);
        fillVec(vec);
        vec[vecSize-1] = 10;
        double runTime = 0;
        int keyLocation = linearSearch(vec, key, comparisons, runTime);
        cout << "search time for run #"<< i << ": " << runTime << " us " << endl;
        //cout << "key location: " << keyLocation << endl;
        linearTotal += runTime;
    }
    double linearAvg = linearTotal/5;
    cout << "average search time: " << linearAvg << " us "<< endl; //avg
    cout << "# of comparisons made: " << comparisons << endl; //comparisons
    cout << "******************************" << endl; //end

    cout << endl; //seperation

    //Binary Search Final Output:
    binaryHeader(); //header
    for(int i = 1; i < 6;i++){ //runtime + avg calc
        std::vector<int> vec(vecSize);
        fillVec(vec);
        vec[vecSize-1] = 10;
        double runTime = 0;
        int keyLocation = binarySearch(vec, key, comparisons, sortingTime, runTime);
        cout << "search time for run #"<< i << ": " << runTime << " us " << endl;
        //cout << "key location: " << keyLocation << endl;
        binaryTotal += runTime;
    }
    double binaryAvg = binaryTotal/5;
    cout << "average search time: " << binaryAvg << " us "<< endl; //avg
    cout << "sorting time: " << sortingTime << " us " << endl;
    cout << "# of comparisons made: " << comparisons << endl; //comparisons
    cout << "******************************" << endl; //end

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

void linearHeader(){
    // linear search output setup:
    cout << "******************************" << endl;
    cout << "Linear Search:" << endl;
    cout << "-------------------" << endl;
    cout << "Input Size = " << vecSize << endl;
}

void binaryHeader(){
    // linear search output setup:
    cout << "******************************" << endl;
    cout << "Binary Search:" << endl;
    cout << "-------------------" << endl;
    cout << "Input Size = " << vecSize << endl;
}

int linearSearch(vector<int> &arr, int x, int& comparisons, double& searchTime){

    comparisons = 0;

    int return_index = -1;

    // Start of the timer
    auto start = high_resolution_clock::now();

    // Loop to compare each element
    for(int i = 0; i < arr.size(); i++)
    {
        comparisons++;
        if(arr[i] == x)
        //cout << i+1 << " comparisons" << endl;
        return_index = i;
    }
    //cout << arr.size(); << " comparisons" << endl;

    // End timer
    auto end = high_resolution_clock::now();

    // Calculate total time
    duration<double, std::micro> duration = (end - start);
    searchTime = duration.count();
    //cout << fixed << duration.count() << " us ";

    return return_index;

}

int binarySearch(vector<int> &arr, int x, int& comparisons, double& sortingTime, double& searchTime){

    comparisons = 0;

    auto startsort = high_resolution_clock::now(); //start timer
    sort(arr.begin(), arr.end());
    auto endsort = high_resolution_clock::now(); //end timer
    duration<double, std::micro> sortTime = (endsort - startsort);
    sortingTime = sortTime.count();

    // Start timer
    auto start = high_resolution_clock::now();

    int low = 0;
    int high = arr.size() - 1;
    int result_index = -1;

    // Binary search loop to change mid and high
    while(low <= high)
    {
        comparisons++;
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

    // End timer
    auto end = high_resolution_clock::now();

    // Calculate total time
    duration<double, std::micro> duration = (end - start);
    searchTime = duration.count();
    //cout << fixed << setprecision(3) << "binary duration = " << duration.count() << " us ";

    return result_index;


}