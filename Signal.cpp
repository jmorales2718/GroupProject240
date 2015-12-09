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
  //concatenateColumns();
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
  string line = myLines[lineNumber];
  //cout << "line: " << line << endl;
  //cout << endl;
  int i = 0;
  int start = 0;
  int end = 0;
  while(isWhiteSpace(line[start]))
  {
//    cout << "infLoop MOTHERFUCKA" << endl;
    start ++;
  }
  //cout << "start: " << start << endl;
  while(i < index)
  {
    while(!isWhiteSpace(line[start])) 
    {
  //    cout << "infLoop BITCH" << endl;
      start++; 
    } 
   // cout << "start: " << start << endl;
    while(isWhiteSpace(line[start]))
    {
   //   cout << "infLoop CUNT" << endl;
      start++;
    }
    i++;
    //cout << "start: " << start << endl;
  }
  end = start;
  while(!isWhiteSpace(line[end]))
  {    
   // cout << "infLoop BITCH NIGGA" << endl;
    end++;
  } 
  string dataValue = line.substr(start, end-start);
  //cout << "doubleDV: " << doubleDV << endl;
  return dataValue;
}

void Signal::normalizeData()
{
  for(unsigned int j = 0; j < myLines.size()-1; j++)
  {
    string normalized;
    for(int i = 0; i < numCols; i++)
    {
      string dubDV  = getDataValue(i, j);
      double currDV = atof(dubDV.c_str());
      double min    = myColExtrema[i].min;
      double max    = myColExtrema[i].max;

      double normDV = (currDV - min) / (max - min);
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
    for(unsigned int i = 0; i < myLines.size()-1; i++)
    {
      //cout << "i: " << i << " j: " << j << endl;
      double dataValue = atof(getDataValue(j,i).c_str());
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
    for(unsigned int i = 0; i < myLines.size()-1; i++)
    {
      double myNormData = atof(getDataValue(j,i).c_str());
      mySignalVector.push_back(myNormData);
    }
  }
}



