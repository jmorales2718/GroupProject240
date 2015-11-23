#include "Signal.h"
#include "DTW.h"
#include "DTW_GUI.h"


int main(int argc, char* argv[])
{
    Signal sig1(argv[0]);
    Signal sig2(argv[1]);

    DTW dtw(sig1, sig2);
    vector<double> mapVec = dtw.getMapVec();
    dtw.printDistance();

    DTW_GUI gui(sig1, sig2, mapVec);
    gui.makeThingsPretty();
}
