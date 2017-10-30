#include <iostream>
#include <cassert>

using namespace std;

template<class T>
bool sorted(T a[], int n) {//checks if array is sorted

    if (n == 1 || n == 0)
        return true;
 	int j = 1;
 	for(int i = 0; i < n; ++i){
		if(a[i] > a[i+1])
			return false;
		else
			return true;
	}
}

template<class T>
void merge(int a[], int x[], T start, T mid, T end){ //merges arrays together in order
    T num1 = mid - start + 1; //lower part of the array start point
    T num2 =  end - mid; //Higher part of the array start point
 	int k, i, j;
    T arr1[num1], arr2[num2]; //2 temporary arrays
 
    for (i = 0; i < num1; i++)
        arr1[i] = a[start + i];
    for (j = 0; j < num2; j++)
        arr2[j] = a[mid + 1+ j];
 
  
    i = 0; 
    j = 0; 
    k = start;
    while (i < num1 && j < num2) //sorts most if not all numbers
    {
        if (arr1[i] <= arr2[j])
        {
            a[k] = arr1[i];
            i++;
        }
        else
        {
            a[k] = arr2[j];
            j++;
        }
        k++;
    }
 
    while (i < num1) //sorts any remaining in the lower array
    {
        a[k] = arr1[i];
        i++;
        k++;
    }
 
    while (j < num2) //sorts any remaining in the upper array
    {
        a[k] = arr2[j];
        j++;
        k++;
    }	
}

template<class T>
void msort(int a[], int x[], T start, T end){ //recursive function to seperate the array
	T mid = (start + end) / 2;
	if(start < end){
		msort(a, x, start, mid);
		msort(a, x, mid + 1, end);
		merge(a, x, start, mid, end);
	}
	return;
}

template<class T>
void mergesort(T a[], int len){
	T x[len];
	msort(a, x, 0, len-1);
}

int main() //tests for the mergesort
{
	int a[1000];
	for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
	mergesort(a, 1000);
	assert(sorted(a, 1000));
	
	int b[1001];
	for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
	mergesort(b, 1001);
	assert(sorted(b, 1001));

	int c[] = { 2 };
	mergesort(c, 1);
	assert(sorted(c, 1));

	int d[] = { 1, 2, 3, 4, 5 };
	mergesort(d, 5);
	assert(sorted(d, 5));

	
	cout << "All tests passed." << endl;	
}
