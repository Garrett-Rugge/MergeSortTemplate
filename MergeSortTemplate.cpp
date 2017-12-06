#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

template<class T>
class User{
private:
	int len;
	T * data;
public:	
	User(int len);
	~User();
	T & operator[](int i);
	bool sorted(T a[], int n);
	void merge(T x[], int start, int mid, int end);
	void msort(T x[], int start, int end);
	void mergesort(int len);
};

template<class T>
User<T>::User(int len){
	len = len;
	data = new T[len];
}
template<class T>
User<T>::~User(){
	delete []data;
	data = NULL;
}
template<class T>
T & User<T>::operator[](int i){
	return data[i];
}
template<class T>
bool User<T>::sorted(int n) {//checks if array is sorted

    if (n == 1 || n == 0)
        return true;
 	int j = 1;
 	for(int i = 0; i < n; ++i){
		if(data[i] > data[i+1])
			j = 0;
	 }	
	 if(j = 0)
	 	return false;
	else
    	return true;
}
template<class T>
void User<T>::merge(T x[], int start, int mid, int end){
    int num1 = mid - start + 1; //lower part of the array start point
    int num2 =  end - mid; //Higher part of the array start point
 	int k, i, j;
    T arr1[num1], arr2[num2]; //2 temporary arrays
 
    for (i = 0; i < num1; i++)
        arr1[i] = data[start + i];
    for (j = 0; j < num2; j++)
        arr2[j] = data[mid + 1+ j];
 
  
    i = 0; 
    j = 0; 
    k = start;
    while (i < num1 && j < num2)
    {
        if (arr1[i] <= arr2[j])
        {
            data[k] = arr1[i];
            i++;
        }
        else
        {
            data[k] = arr2[j];
            j++;
        }
        k++;
    }
 
    while (i < num1)
    {
        data[k] = arr1[i];
        i++;
        k++;
    }
 
    while (j < num2)
    {
        data[k] = arr2[j];
        j++;
        k++;
    }	
}

template<class T>
void User<T>::msort(T x[], int start, int end){
	if(start < end){
	int mid = (start + end) / 2;
	msort(x, start, mid);
	msort(x, mid + 1, end);
	merge(x, start, mid, end);
	}	
}

template<class T>
void User<T>::mergesort(int len){
	data = new T[len];
	msort(data, 0, len-1);
}
template<class T>
void test1(){
	User<int> a(5);
	a[0] = 2;
	a[1] = 1;
	a[2] = 3;
	a[3] = 7;
	a[4] = 11;
	a.mergesort(5);
	assert(a.sorted(5));
}
int main()
{
	test1();
	cout << "All tests passed." << endl;	
	return 0;
}

