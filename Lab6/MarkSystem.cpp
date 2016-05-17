#include <iostream>
using namespace std;

/* Read n marks from keyboard, where n is a user-specified value */

void performDataEntry(int*& arr, int& n)
{
	system("cls");
    cout << "-------------" << endl;
    cout << "    Input    " << endl;
    cout << "-------------" << endl;    
    cout << "How many marks to store? ";
    cin >> n;
    arr = new int[n];
    cout << "Input marks: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];
}

/*
   [ Quicksort Algorithm ]
   
   1. Choose a pivot value
      We take the the middle element as pivot value.
   2. Partition
      Rearrange elements in the array, such that all elements that
      are less than the pivot are moved to the left part of the array
      and all elements greater than the pivot moved to the right
      part of the array.
      Note:
      The pivot should now be placed in its final position in the sorted array.
   3. Sort the left unsorted array and right unsorted array
      Apply quicksort algorithm recursively for the left and the right parts.
*/

void performQuickSort(int arr[], int left, int right)
{
    int i = left;
    int j = right; 
    int tmp; 
    int pivot = arr[(left + right) / 2]; 
    
    while (i <= j)
    { 
        while (arr[i] < pivot) 
            i++;
        while (arr[j] > pivot) 
            j--; 

        if (i <= j)
        { 
            tmp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = tmp;
            i++;
            j--;
        } 
    }
    
    if( left < j )
        performQuickSort( arr, left, j );
    if( i < right)
        performQuickSort( arr, i, right );
}

void performSortMarks(int arr[], const int& size)
{
	system("cls");
	cout << "size: " << size << endl;
    cout << "-------------" << endl;
    cout << "   Sorting   " << endl;
    cout << "-------------" << endl;
    cout << "Marks sorted in ascending order: ";
	performQuickSort(arr, 0, size-1);
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;
	system("pause");
}

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

/* Compute the statistics of marks (mean and unbiased variance */

void performComputation(int arr[], int size)
{
     system("cls");     
     double sum = 0;
     double sumSquared = 0;
     for (int i = 0; i < size; i++)
     {
         sum += arr[i];         
         cout << arr[i] << " ";
     }
	 cout << endl;
     double mean = sum / size;
	 for(int i=0; i<size; i++)
		sumSquared += (arr[i] - mean)*(arr[i] - mean);
	 double variance = sumSquared / (size - 1);	
     cout << "Mean : " << mean << endl;
     cout << "Unbiased variance : " << variance << endl;
     system("pause");
}

/* Plot the histogram with a user-defined number of bins */

void performHistogram(int arr[], int size)
{
     system("cls");
     int bins;
     cout << "How many bins you want to use to group the data ? ";
     cin >> bins;
     double max = arr[0];
     double min = arr[0];
     for (int i = 1; i < size; i++)
     {
         if (max < arr[i])
            max = arr[i];
         if (min > arr[i])
            min = arr[i];
     }
     cout << "min = " << min << endl;
     cout << "max = " << max << endl;
     double dataRange = max - min;
     double classRange = dataRange / bins;
     double lowerBound = min;
     double upperBound = min + classRange;
     for (int i = 0; i < bins; i++, upperBound += classRange, lowerBound += classRange)
     {
         bool last = i == (bins - 1);
         cout << "[" << lowerBound << ", " << upperBound << (last ? "]" : ")") << " : ";
         for (int j = 0; j < size; j++)
         {
             if (arr[j] >= lowerBound && (last || arr[j] < upperBound))
                cout << "*";
         }
         cout << endl;
     }
     system("pause");
}

bool executeMenu(int choice, int*& arr, int& size)
{
     switch(choice)
     {
        case 1:
			 if(arr != NULL)
			     delete [] arr;
             performDataEntry(arr, size);
             break;
        case 2:
             performSortMarks(arr, size);
             break;
        case 3:
			 performSearchMark(arr, size);
			 break;
		case 4:
			 performComputation(arr, size);
             break;
        case 5:
			 performHistogram(arr, size);
			 break;
		case 6:
             return true;
     }
     return false;
}

int selectMenu()
{
	system("cls");
    int choice;
    do {
        cout << "Select function: " << endl;
		cout << "----------------" << endl;
        cout << "1.) Mark Entry" << endl;
		cout << "2.) Sort Marks" << endl;
		cout << "3.) Search Mark" << endl;
        cout << "4.) Compute Statistics " << endl;
        cout << "5.) Plot Histogram " << endl;
        cout << "6.) Quit " << endl;
        cout << endl;
        cout << "Please enter your choice: ";
        cin >> choice;
    } while(choice < 1 || choice > 6);
    return choice;
}

int main()
{
	bool quit;
	int size;
	int* arr = NULL;
	do {	   
       quit = executeMenu(selectMenu(), arr, size);
    } while (!quit);
	if(arr != NULL)
		delete [] arr;
    system("pause");
    return 0;
}
