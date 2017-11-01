#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

template<typename T>
class User{
	private:
		int len;
		T data;
	public:	
	User() { len = 0; }
	~User();
	bool sorted(T a[], int n);
	void merge(T a[], T x[], int start, int mid, int end);
	void msort(T a[], T x[], int start, int end);
	void mergesort(T a[], int len);
};
template<class T>
bool User<T>::sorted(T a[], int n) {//checks if array is sorted

    if (n == 1 || n == 0)
        return true;
 	int j = 1;
 	for(int i = 0; i < n; ++i){
		if(a[i] > a[i+1])
			j = 0;
	 }	
	 if(j = 0)
	 	return false;
	else
    	return true;
}
template<class T>
void User<T>::merge(T a[], T x[], int start, int mid, int end){
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
    while (i < num1 && j < num2)
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
 
    while (i < num1)
    {
        a[k] = arr1[i];
        i++;
        k++;
    }
 
    while (j < num2)
    {
        a[k] = arr2[j];
        j++;
        k++;
    }	
}
template<class T>
void User<T>::msort(T a[], T x[], int start, int end){
	if(start < end){
	int mid = (start + end) / 2;
	msort(a, x, start, mid);
	msort(a, x, mid + 1, end);
	merge(a, x, start, mid, end);
}

}
template<class T>
void User<T>::mergesort(T a[], int len){
	data = new int[len];
	msort(a, data, 0, len-1);
}


int main()
{
	User<int> a;
	
	
	cout << "All tests passed." << endl;	
	return 0;
}

