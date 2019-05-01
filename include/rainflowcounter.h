#ifndef RAINFLOWCOUNTER_H
#define RAINFLOWCOUNTER_H

#include <vector>
#include <algorithm>
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
    bool BoundedByExtremeties(double firstExtremity, double firstValue, double secondValue, double secondExtremity)
    {
        auto minExtremity = std::min(firstExtremity,secondExtremity);
        auto maxExtremity = std::max(firstExtremity,secondExtremity);
        return firstValue == std::clamp(firstValue,minExtremity,maxExtremity) &&
                secondValue == std::clamp(secondValue,minExtremity, maxExtremity);
    }

    bool IsCycle4PointsMethod(double firstPoint, double secondPoint, double thirdPoint, double fourthPoint)
    {
        if(BoundedByExtremeties(firstPoint,secondPoint,thirdPoint,fourthPoint))
        {
            auto outerStress = std::abs(fourthPoint-firstPoint);
            auto innerStress = std::abs(thirdPoint-secondPoint);
            return innerStress<=outerStress;
        }
        return false;
    }

    bool RemoveNextCycle(std::vector<double> &values)
    {
        for(auto it=values.begin();it<values.end()-3;++it) {
                 if(BoundedByExtremeties(*it,*(it+1),*(it+2),*(it+3))) {
                    if(IsCycle4PointsMethod(*it,*(it+1),*(it+2),*(it+3))) {
                        values.erase(it+1);
                        values.erase(it+1);
                        return true;
                    }
                }
            }
            return false;
    }

};


#endif // RAINFLOWCOUNTER_H
