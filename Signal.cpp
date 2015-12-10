#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cfloat>
#include "Signal.h"

using namespace std;


Signal::Signal(char* file)
{
  getRows(file);
  findExtrema();
  normalizeData();
  populateVec();
}

/*
void Signal::concatenateColumns()
{
  for(int i = 0; i < numCols; i++)
  {
    string finalStr;
    for(unsigned int j = 0; j < myLines.size(); j++)
    {
      string dataValue = getDataValue(i,j); 
      finalStr.append(dataValue);
      finalStr.append(" ");
    }
    myStringVector.push_back(finalStr);
  }
}
*/

string Signal::getDataValue(int index, int lineNumber)
{
  istringstream iss(myLines[lineNumber]);
  string finalStr;
  if(index == 0)
  {
    iss >> finalStr;
  }
  else
  {
    for(int i = 0; i < index; i++)
    {
      iss >> finalStr;
    }
  }
  //cout << "finalStr: " << finalStr << endl;
  return finalStr;
}

void Signal::normalizeData()
{
  for(unsigned int j = 0; j < myLines.size(); j++)
  {
    string normalized;
    for(int i = 0; i < numCols; i++)
    {
      //cout << "row: " << i << "col: " << j << endl;

      string dubDV  = getDataValue(i, j);
      double currDV = atof(dubDV.c_str());
      //cout << "currDV: " << currDV << endl;
      double min    = myColExtrema[i].min;
      //cout << "min: " << min <<endl;
      double max    = myColExtrema[i].max;
      //cout << "max: " << min <<endl;
      double normDV = (currDV - min) / (max - min);
      //cout << "normDV: " << normDV <<endl;
      //cout << endl;
      ostringstream ss;
      string normalizedDV;
      if(normDV == 0 || normDV == 1)
      { 
        ss << normDV << ".000000 ";
        normalizedDV = ss.str(); 
      }
      else
      {
        ss << normDV << " ";
        normalizedDV = ss.str(); 
        //cout << "normalizedDV: " << normalizedDV << endl;
      }
      normalized.append(normalizedDV); 
    }
    //cout << "normalizedLine " << j << ": " << normalized << endl;
    myLines[j] = normalized;
  }
}

void Signal::findExtrema()
{
  //int expJ = 16;
  //int expI = 0;
  for(int j = 0; j < numCols; j++)
  {
    double max = -DBL_MAX;
    double min = DBL_MAX;
    for(unsigned int i = 0; i < myLines.size(); i++)
    {
      //cout << "i: " << i << " j: " << j << endl;
      //cout << "dvString: " << getDataValue(j,i) <<endl;
      double dataValue = atof(getDataValue(j,i).c_str());
      //cout << "dataValue at row " << i << "and col " << j << ": " << dataValue <<endl; 
      if(dataValue < min)
      {
        min = dataValue;
      }
      if(dataValue > max)
      {
        max = dataValue;
      }
      //cout << "currMax: " << max << endl;
      //cout << "currMin: " << min << endl;
    }
    Extrema extrema;
    extrema.max = max;
    extrema.min = min;
    
    myColExtrema.push_back(extrema);
  }
}

void Signal::getRows(char* file)
{
   ifstream infile(file);
   string line;
  
   while(getline(infile, line))
   {
      //cout << "currentLine: " << line << endl;
      myLines.push_back(line);
   }
}

bool Signal::isWhiteSpace(char c)
{
  if(c == ' ' || c == '\t' || c == '\f' || c == '\v' || c == '\n' || c == '\r')
  {
    return true;
  } 
  return false;
}

void Signal::populateVec()
{
  
  for(int j = 0; j < numCols; j++)
  {
    for(unsigned int i = 0; i < myLines.size(); i++)
    {
     // cout << "i: " << i << " j: " << j << endl;
      double myNormData = atof(getDataValue(j,i).c_str());
     // cout << "myNormData: " << myNormData << endl;
      mySignalVector.push_back(myNormData);
    }
  }
}



