#include <iostream>
using namespace std;

int* allocate_array(int size);

void deallocate_array(int*& arr);

int* copy_array(int arr[], int size);

void double_the_array(int*& arr, int& size);

void half_the_array(int*& arr, int& size);

int* slice_of_array(int arr[], int size, int first_index, int last_index, int& sliced_size);

double mean_array(int arr[], int size);

int compare_array(int arr[], int arr2[], int size, int size2);

int* concatenate_arrays(int arr[], int arr2[], int size, int size2, int& con_size);

void sort_array(int arr[], int size);

int* sorted_copy(int arr[], int size);

void distinct_array(int*& arr, int& size);

int* distinct_copy(int arr[], int size, int& dis_size);

int exists(int arr[], int size, int num);

int is_nullptr(int* p);

/*Function to print an array*/
void print_array(const int* p, int size)
{
    cout << "Array Size: " << size << "\t" << "Elements {";
    if (size <= 0)
        cout << "}" << endl;
    else
    {
        for (int i = 0; i < size - 1; i++)
            cout << p[i] << ", ";
        cout << p[size - 1] << "}" << endl;
    }
}


int main()
{
    cout << "****************Nullptr Check***************\n\n";
    int* my_array1 = allocate_array(50);
    if (is_nullptr(my_array1))
        cout << "my_array1 is nullptr" << endl;
    else
        cout << "my_array1 is not nullptr" << endl;
    // OUTPUT  my_array1 is not nullptr

    print_array(my_array1, 50);
    // OUTPUT Array Size: 50       Elements {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

    deallocate_array(my_array1);
    if (is_nullptr(my_array1))
        cout << "my_array1 is nullptr" << endl;
    else
        cout << "my_array1 is not nullptr" << endl;
    // OUTPUT my_array1 is nullptr


    cout << "\n**********Double and half the array**********\n\n";
    int my_array_size = 10;
    int* my_array = new int[my_array_size] { 5, 6, 7, 8, 10, 11, 12, 34, 16, 14 };
    print_array(my_array, my_array_size);
    // OUTPUT Array Size: 10  Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}

    double_the_array(my_array, my_array_size);
    print_array(my_array, my_array_size);
    //OUTPUT Array Size: 20  Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
    my_array[14] = 100;
    print_array(my_array, my_array_size);
    //OUTPUT Array Size: 20  Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14, -1, -1, -1, -1, 100, -1, -1, -1, -1, -1}
    half_the_array(my_array, my_array_size);
    print_array(my_array, my_array_size);
    //OUTPUT Array Size: 10   Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}

    cout << "\n***************Slice of array***************" << endl << endl;
    int my_slice_size = 0;
    int* my_slice =
        slice_of_array(my_array, my_array_size, 3, 5, my_slice_size);
    print_array(my_array, my_array_size);
    //OUTPUT Array Size: 10    Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}
    print_array(my_slice, my_slice_size);
    //OUTPUT Array Size: 3     Elements {8, 10, 11}

    cout << "\n***************Mean of array***************" << endl << endl;
    double mean = mean_array(my_array, my_array_size);
    cout << "mean= " << mean << endl;
    // OUTPUT 12.3


    cout << "\n***********Concatenation of array************\n\n";
    int concat_array_size = 0;
    int my_array2_size = 3;
    int* my_array2 = new int[my_array2_size] { 10, 5, 6 };

    print_array(my_array, my_array_size);
    //OUTPUT Array Size: 10 Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}

    print_array(my_array2, my_array2_size);
    // OUTPUT Array Size: 3 Elements {10, 5, 6}


    int* concat_array = concatenate_arrays(my_array, my_array2, my_array_size, my_array2_size, concat_array_size);

    print_array(concat_array, concat_array_size);
    // OUTPUTArray Size: 13   Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14, 10, 5, 6}


    cout << "\n***************Compare arrays***************\n\n";
    cout << compare_array(my_array, my_array2, my_array_size, my_array2_size) << endl;
    //OUTPUT  0
    cout << compare_array(my_array, my_array, my_array_size, my_array_size) << endl;
    //OUTPUT  1

    cout << "\n*************Sort arrays***************\n\n";
    print_array(my_array2, my_array2_size);
    //OUTPUT Array Size: 3  Elements {10, 5, 6}
    sort_array(my_array2, my_array2_size);
    print_array(my_array2, my_array2_size);
    //OUTPUT Array Size: 3 Elements {5, 6, 10}
    int* my_array_sorted = sorted_copy(my_array, my_array_size);
    print_array(my_array, my_array_size);
    //OUTPUT Array Size: 10       Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}
    print_array(my_array_sorted, my_array_size);
    //OUTPUT  Array Size: 10       Elements {5, 6, 7, 8, 10, 11, 12, 14, 16, 34}


    cout << "\n**********Element existance***********\n\n";
    cout << exists(my_array, my_array_size, 1000) << endl;	//OUTPUT 0
    cout << exists(my_array, my_array_size, 34) << endl;	// OUTPUT 1

    cout << "\n**********Distinct array**************\n\n";
    int my_array3_size = 6;
    int* my_array3 = new int[my_array3_size] { 44, 6, 7, 6, 7, 5 };

    print_array(my_array3, my_array3_size);
    // OUTPUT Array Size: 6    Elements {44, 6, 7, 6, 7, 5}  
    int distinct_myarray3_copy_size = 0;
    int* distinct_myarray3_copy = distinct_copy(my_array3, my_array3_size, distinct_myarray3_copy_size);
    print_array(my_array3, my_array3_size);
    // OUTPUT Array Size: 6     Elements {44, 6, 7, 6, 7, 5}
    print_array(distinct_myarray3_copy, distinct_myarray3_copy_size);
    //OUTPUT Array Size: 4  Elements {44, 6,  7,  5}

    distinct_array(my_array3, my_array3_size);
    print_array(my_array3, my_array3_size);
    //OUTPUT Array Size: 4     Elements {44, 6,  7,  5}
    deallocate_array(my_array);
    deallocate_array(my_array1);
    deallocate_array(my_array2);
    deallocate_array(my_array3);
    deallocate_array(my_array_sorted);
    deallocate_array(concat_array);
    deallocate_array(my_slice);
    deallocate_array(distinct_myarray3_copy);
    system("pause");
    return 0;
}
/*The function takes a size and create and allocated dynamic
integer array of that size and returns the addressd of thae array*/
int* allocate_array(int const size)
{
    int* p = new int[size];
    for (int i = 0;i < size;i++)
    {
        p[i] = 0;
    }
    return p;
}

/*This function take dynamic array as input and deallocates it
and changes the pointer of array to nullptr*/
void deallocate_array(int*& arr)
{
    delete[] arr;
    arr = 0;
}

/*This function takes an array as input and doubles its size,
the current elements are copies to first half of the new
bigger array. Note that the input array is doubled, size param should
also be doubled. Default value in 2nd half can be -1 */
void double_the_array(int*& arr, int& size)
{
    int const half = size;
    int* temp = copy_array(arr, size);
    deallocate_array(arr);
    size = size + size;
    arr = allocate_array(size);
    for (int i = 0;i < half;i++)
    {
        arr[i] = temp[i];
    }
    deallocate_array(temp);
    for (int i = half;i < size;i++)
    {
        arr[i] = -1;
    }
}

/*This functions take the array as input and reduce the size to half
element of only first half are retained. Note that the input array
is halfed. Size param should also be halfed*/
void half_the_array(int*& arr, int& size)
{
    size = size / 2;
    int* temp = copy_array(arr, size);
    deallocate_array(arr);
    arr = copy_array(temp, size);
    deallocate_array(temp);
}

/*This function takes any array, start index and end index as input
and returns a copy of slice of array from start index to end index.
Input array should not be effected.*/
int* slice_of_array(int arr[], int const size, int const first_index, int const last_index, int& sliced_size)
{
    sliced_size = (last_index - first_index) + 1;
    int* sliced_arr = allocate_array(sliced_size);
    for (int i = first_index, j = 0;i <= last_index;i++, j++)
    {
        sliced_arr[j] = arr[i];
    }
    return sliced_arr;
}

/*This function takes an array as input and give the mean of
numbers of array*/
double mean_array(int arr[], int const size)
{
    double mean = 0;
    for (int i = 0;i < size;i++)
    {
        mean += arr[i];
    }
    mean = mean / size;
    return mean;
}

/*This function takes two arrays and their sizes and
return's True if both have same elements in same order
else return false*/
int compare_array(int arr[], int arr2[], int const size, int const size2)
{
    int count = 0, ret = 0;
    if (size != size2)
    {
        ret = 0;
    }
    else
    {
        for (int i = 0;i < size;i++)
        {
            if (arr[i] == arr2[i])
            {
                count++;
            }
        }
        if (count == size)
        {
            ret = 1;
        }
        else
        {
            ret = 0;
        }
    }
    return ret;
}

/*This function takes two arrays and there size
and returns a new array the is concatenation of both.
If size of both arrays is not same return False*/
int* concatenate_arrays(int arr[], int arr2[], int const size, int const size2, int& con_size)
{
    con_size = size + size2;
    int* con_arr = allocate_array(con_size);
    for (int i = 0;i < size;i++)
    {
        con_arr[i] = arr[i];
    }
    for (int i = size, j = 0;j < size2;i++, j++)
    {
        con_arr[i] = arr2[j];
    }

    return con_arr;
}

/*This function takes an array and sorts its inplace
sort inplace means sorting the input array, not creating its copy*/
void sort_array(int arr[], int const size)
{
    int small = arr[0], temp = 0, index = 0;
    for (int i = 0;i < size;i++)
    {
        for (int j = i + 1;j < size;j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/*This function take and array and returns it's sorted copy
orignal input array should not be effeected
Hint: you can use sort array function in this function*/
int* sorted_copy(int arr[], int const size)
{
    int* copy = copy_array(arr, size);
    sort_array(copy, size);
    return copy;
}

//this function creates and returns a copy of the array sent to it
int* copy_array(int arr[], int const size)
{
    int* copy = allocate_array(size);
    for (int i = 0;i < size;i++)
    {
        copy[i] = arr[i];
    }
    return copy;
}
/*This function takes an array and returns a new array containing only
distinct elements of input array. Original array should not be changed
It also returns the size of new array*/
int* distinct_copy(int arr[], int const size, int& dis_size)
{
    dis_size = size;
    int* dis_copy = copy_array(arr, size);
    distinct_array(dis_copy, dis_size);
    return dis_copy;
}

/*This function takes an array deletes the redudant elements from it
So the input array will not have only distinct value. This function is
different from distinct_copy function, here input array is changed.*/
void distinct_array(int*& arr, int& size)
{
    int temp, index = size, copysize = size, size2 = 0;
    for (int i = 0;i < copysize;i++, index--)
    {
        for (int j = i + 1;j < copysize;j++)
        {
            if (arr[i] == arr[j])
            {
                temp = arr[j];
                arr[j] = arr[index];
                arr[index] = temp;
                size2++;
                copysize--;
            }
        }
    }
    //this process below is done to shrink the size of the original array and thus deleting the repeating elements
    if (size2 != 0)
    {
        int* temp = copy_array(arr, size);
        deallocate_array(arr);
        size -= size2;
        arr = copy_array(temp, size);
        deallocate_array(temp);
    }
}

/*this function takes an array as input; and a number and checkes
if number exists in array. If yes, return True else return false*/
int exists(int arr[], int const size, int const num)
{
    int ret = 0;
    for (int i = 0;i < size;i++)
    {
        if (arr[i] == num)
        {
            ret = 1;
        }
    }
    return ret;
}

/*takes a pointer as input and return true if pointer is NULL of nullptr
else false*/
int is_nullptr(int* p)
{
    int ret = 0;
    if (p == 0)
    {
        ret = 1;
    }
    return ret;
}