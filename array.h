/*****************************************************
Template prepared by Kazumi Slott
CS211
lab on template functions
This header file provides useful operations on an array
of any data type.

Your name: Liam Nelson
*****************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/********************************************
This function fills the array with data entered from the keyboard.

ar is an array of any data type
n is the number of items entered into ar
********************************************/
template <class T>

void fill(T ar[], int n, T data)
{
  ar[n] = data;
  cout << endl;
}




/********************************************
This function prints the array.
1
ar is an array of any data type
n is the number of items in ar
********************************************/
template <class T, class O>

  void print(O&out, T ar[], int n)
{
 //prints the array from start to finish
 for(int i = 0; i < n; i++)
  {
     out << ar[i] << " ";
  } 
 out << endl;
}




/*******************************************
This function returns the index of the highest value.

ar is an array of any data type.
n is the number of items in ar
*******************************************/
template <class T>

int getHighest(T ar[], int n)
{
 int pointer = 0;

// compares the current value of pointer to values in the array and saves
// the index of the highest value in pointer
 for(int i = 0; i < n; i++)
 {
  if(ar[i] > ar[pointer])
  {
   pointer = i;
  }
 }

 //cout << pointer;
 return pointer;
}




/*******************************************
This function returns the index of the lowest value.

ar is an array of any data type.
n is the number of items in array
*******************************************/
template <class T>

int getLowest(T ar[],int n)
{
 
int pointer = 0;

// compares the current value of pointer to values in the array and saves
// the index of the lowest value in pointer
 for(int i = 0; i < n; i++)
 {
  if(ar[i] < ar[pointer])
  {
   pointer = i;
  }
 }

 return pointer;
}




/********************************************
This function returns the average.

ar is an array of any data type.
n is the number of items in ar
********************************************/
template <class T>

double getAvg(T ar[], int n)
{
 double sum = 0; 

 // this loop adds all of the numbers of ar and stores them in sum
 for(int i = 0; i < n; i++)
 {
  sum = ar[i]+sum; 
 }

 double avg = (double)(sum / n);

 return avg;
}



/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1
        The function returns 4  
       
ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar and uniqAr
*******************************************/
template <class T>

int unique(T ar[], T uniqAr[] , int n)
{
  int counter = 0; //counts the unique items
//uniqAr in the caller will be filled with only unique numbers
  for(int i = 0; i < n; i++)
  {
   int j;
    for(j = 0; j < i; j++)
    {
      if(ar[i] == uniqAr[j])
      {
        break;
      }
    }
   if(i == j)
   {
     uniqAr[counter] = ar[i];
     counter++; 
   }
  }

  cout<<endl;
  return counter;
}




/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/                                                

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order 
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <class T>

void sort(T array[], int N)
{
  int lrgIndx; //the index of the largest value                                                                                               
  T temp; //temporary variable that holds the largest value                                                                                  

  //last is the last index in unsorted portion                                                                                                 
  for(int last = N-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest                                                                                      
      //find the largest in unsorted portion ([0..last])                                                                                       
      for(int i = 1; i <= last; i++)
        {
          if(array[i] > array[lrgIndx]) //The current item is larger                                                                           
            lrgIndx = i;
        }

      //swap the largest with the last item in the unsorted portion                                                                            
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}

// ===================================================================
//  takes in an array, it's size, and the item that needs to be found
//
//  if found it returns the index of key, if not it returns -1
// ===================================================================

template <class T>

int find(T ar[], int n, T key)
{
  for(int i = 0; i < n-1; i++)
    {
      if(key != ar[i])
	{
	  return -1;
	}
      else if(key == ar[i])
	{
	  return i;
	}
    }
}

// =========================================================
//  this fuction takes in an array, the size of the array,
//  and the item that is to be removed.
// 
//  returns true if item was deleted and false if it was not
// ==========================================================


template <class T>

bool remove(T ar[], int n, T key)
{
  T temp;
  int tempIndex = -1;
    
  tempIndex = find(ar, n, key);
  
  if(tempIndex != -1)
    {
      //switches the class we want to move with the class in the first index,
      //moves the first index outside of the array, and sorts

      temp = ar[tempIndex];
      ar[tempIndex] = ar[0];
      ar[0] = temp;
      ar[0] = ar[-1];
      sort(ar);
      return true;
    }
  else
    {
      return false;
    }
}

//

//template <class T, class O>

  //void print(O& out, const T ar[], int n)
  //{
  // for(int i = 0; i < n; i++)
  //  {
      //  out << ar[i} << " ";
  //  }
  //}
