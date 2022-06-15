#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;

//Will be adding a new void called voidcheck, that will check the sorted algorithm with a strcopy of the inputted algorithm


//Works Fully Now
void bubbleSort(int a[], int n){
	int i,j;
	int *d;
	int temp;
	d = a;
	
	int sorted;
	for (j = 1; j <= n-1; j++) {
		sorted = 0;
		for (i = 0; i < n-j; i++){
			if(a[i] > a[i+1]){
				temp = *(d+i);
				*(d+i) = *(d+i+1);
				*(d+i+1) = temp;
				sorted = 1;
			}
			
		}
		if(sorted == 0)
			break;
		}
  /*
	for(i=0; i<n; i++){
			cout<<a[i]<<" ";
		}
  */
	cout<<endl;
}

//String to sort to attack.
void RanArrayGen(int c[], int n){
	int i;
	cout<<"Array: ";
	for (i=0; i<n; i++){
		c[i] = rand()%35+11;
		cout<<c[i]<<" ";
	}
	cout<<endl;
}

//String to Input to Compare
int ArrayGen(int p[], int n){
	int i, a;
	for(i=1; i<n+1; i++){
		cout<<"Please Enter Digit Number "<<i<<endl;
		cin>>a;
    if (a == p[i-1]){
      cout<<"Correct!"<<endl;
    }
    else{
      cout<<"Wrong!"<<endl;
      return 0;
    }
	}
  cout<<"Nice!"<<endl;
  return 1;

	
}