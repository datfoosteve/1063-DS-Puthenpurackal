```cpp
/**
* @Homework: Homework-3
* @Author: Stephen Puthenpurackal 
* @Description: 
*     The full program reads in images stored as rgb values in a space delimited file format, but this snippet
* is the print method that we are instructed to change.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 03/01/2017
*/

/**
* @FunctionName: Print
* @Description: 
*     This function was changed because the original print method did not print even when the array was full. Fixed the loop invariant
* by creating a bool that equals the "Full" method and checked for that when running the loop.
* @Params:
*    NONE
* @Returns:
*    NONE
*/
void Print(){

  bool ArrFull = Full();
  int Index = Front;

  while(Index != Rear || ArrFull){
    cout<<Q[Index]<<" ";
    Index = ((Index + 1) % (ArraySize));
    ArrFull = false;
  }
  cout<<endl;
}
```
