#ifndef RAINFLOWCOUNTER_H
#define RAINFLOWCOUNTER_H

#include <vector>
class RainflowCounter
{
public:
    void KeepPeaksAndValleys(std::vector<double> &currentValues)
    {
        for(auto it=currentValues.begin()+1;it<currentValues.end()-1;++it)
        {
            auto isPeak=*it>*(it-1) && *it>*(it+1);
            auto isValley=*it<*(it-1) && *it<*(it+1);
            if(!isPeak && !isValley)
            {
               currentValues.erase(it);
               it--;
            }
        }
    }

};


#endif // RAINFLOWCOUNTER_H
