#include <iostream>
using namespace std;
/*
   [ Binary Search Algorithm ]
   
   Check the middle element of the sorted array to see if it is equal to
   the key. If it is, then the position is found.
   Otherwise, the left half or right half is chosen for further searching
   based on whether the key is greater than or less than the middle element.
*/
int performBinarySearch(int arr[], int left, int right, int key)
{
    if ( left > right )
        return -1;
    else
    {
        int mid = ( left + right )/2;
        if ( key == arr[mid] )
            return mid;
        else if ( key < arr[mid] )
            return performBinarySearch( arr, left, mid-1, key );
        else
            return performBinarySearch( arr, mid+1, right, key );
    }
}

void performSearchMark(int arr[], const int& size)
{
	system("cls");
	cout << "-------------" << endl;
    cout << "  Searching  " << endl;
    cout << "-------------" << endl;	
	do{
		int noFind;
		cout << "Mark to find (-1 to quit)? ";
		cin >> noFind;
		if(noFind == -1)
			break;
		int index = performBinarySearch(arr, 0, size-1, noFind);
		if(index != -1)
			cout << "The mark " << noFind << " is found at index " << index << endl;
		else
			cout << "The mark is not found" << endl;
	}while(true);
}