//Christ Rangkas MTH 4300 HW 3 Question 3
//This program will ask for user to input a sequence from values in {1,2,3}
//With the sequence provided, we will transform values s.t.,
//If two consecutive values are not equal, they will form the value that
//is both values are not equal to.

#include <iostream>
int main(){
  int prev, current, first, length = 1, counter = 0; //Counter for printing
  //I found length to be a very important variable in this code
  std::cin >> first; //First input
  current = first; //Save to current so we can compare following value
  while (current == 1 || current == 2 || current == 3){
    //When user inputs from set
    prev = current; //The one to compare with new user input
    std::cin >> current; //New user input
    if (current == 1 || current == 2 || current == 3) {
      length++; //When new input is in set, add to length.
      if (current != prev){ //Not equal consecutive values,
        //When prev+current == 3 means prev&current in set {1,2}
        if (current + prev == 3 && length % 2 == 0){
//While I was debuggin I realized the size of the length was important.
//If the length was even, it will collapse to the value thats not equal
//to prev or current. But if the length was odd,
//it will collapse to be the current value.
          first = 3;//Not equal to prev or current
          length = 1; //resets
          current = first; //we need to compare the NEW first
        }
        else if (current + prev == 3 && length % 2 == 1 ){
          first = current;
        //Because I discovered when length is odd it collapses to current value
          length = 1;
        }
        //When prev+current == 4 means prev&current in set {1,3}
        else if (current + prev == 4 && length % 2 == 0 ){
          first = 2;
          length = 1;
          current = first;
        }
        else if (current + prev == 4 && length % 2 == 1 ){
          first = current;
          length = 1;
        }
        //When prev+current == 5 means prev&current in set {2,3}
        else if(current + prev == 5 && length & 2 == 0 ) {
          first = 1;
          length = 1;
          current = first;
        }
        else if (current + prev == 5 && length % 2 == 1 ){
          first = current;
          length = 1;
        }
      }
    }
  }
  while (counter < length){ // This is for printing the new sequence
    std::cout << first << " ";
//At the end of all processes. the remanining values are all equal.
//So I just printed First length times.
    counter ++;
  }
  std::cout << "\n";
  return 0;
}
