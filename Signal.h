#ifndef _SIGNAL_H_
#define _SIGNAL_H_

#include <vector>
#include <string>

struct Extrema
{
  double max;
  double min;
};

class Signal
{

    public:
      Signal(char* file);
      
      std::vector<double> getVector(){return mySignalVector;};
    
      std::vector<Extrema> getExtVec(){return myColExtrema;};
      
      std::vector<std::string> getMyLines(){return myLines;};

    private:
      
      //void concatenateColumns();

      std::string getDataValue(int index, int lineNumber);

      void normalizeData();

      void findExtrema();

      void getRows(char* file);

      bool isWhiteSpace(char c);
//      std::vector<int> fileToVector(File signalFile);

      void populateVec(); 

      static const int numCols = 17;
      
      std::vector<Extrema> myColExtrema;
      std::vector<std::string> myLines;
      std::vector<double> mySignalVector;
};
#endif
