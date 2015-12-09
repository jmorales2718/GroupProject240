#include <iostream>
#include <string>
#include "Signal.h"
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
  Signal sig1(argv[1]);

  //vector <Extrema> vec = sig1.getExtVec();
  //vector <string> vec = sig1.getMyLines();
  vector <double> vec = sig1.getVector();

  cout << "concatenated doubles: " << endl;
  cout << endl;
  unsigned int i = 0;
  for(i = 0; i < vec.size(); i++)
  {
    cout <<  vec[i] << " ";
    

    //cout << "Line " << i << ": " << vec[i] << endl;
    // cout << "Max: " << vec[i].max << " Min: " << vec[i].min << endl;
  }
  cout << endl; 
  cout << i << endl;  
  
  
  //string s = "I like to eat donkeys, mama!";
  //for(int i = 0;  i < s.length(); i++)
  //{
   // cout << "isWhiteSpace at " << i << ": " << sig1.isWhiteSpace(s[i]) << endl;
  //}

  return 0;
}

