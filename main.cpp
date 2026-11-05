#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

int linearSearch(vector<int>& arr, int x);
int binarySearch(vector<int> &arr, int x);

int vecSize = 10;
int range = 3*vecSize

//main -- 
/*Fill each array with random integers, with new values for every run. The values must be in the range [−3n, 3n], where n
*is the array size. For example, an array of size 100 holds values from −300 to 300. */
int main() {
//Fill array/vector
std::vector<int> vec(vecSize)


}

void fillVec(vector<int>& arr){
    //seed random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    //set ranges
    std::uniform_int_distribution<> dis(-range, range);

    for(int i : arr){
        i = dis(gen);
    }

    for(int i = 0; i > arr.size(); i++){
        cout << arr[i] << "," << endl;
    }





}

int linearSearch(vector<int>& arr, int x){

}

int binarySearch(vector<int> &arr, int x){

}

