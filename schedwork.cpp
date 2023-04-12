#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#endif

// add or remove necessary headers as you please
#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;

#include "schedwork.h"


// Recursive helper function for schedule()

bool Helper(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched,
    size_t day,
    map<Worker_T, size_t>& workerAvail
){
    if (day == sched.size()) {
        return true;
    }
    for(Worker_T i = 0; i < avail[day].size(); i++) {
      if(avail[day][i] && workerAvail[i] < maxShifts) {
        sched[day].push_back(i);
        workerAvail[i]++;
        if(sched[day].size() == dailyNeed) {
          if(Helper(avail, dailyNeed, maxShifts, sched, day + 1, workerAvail)) {
            return true;
                }
            } 
            else{
              if(Helper(avail, dailyNeed, maxShifts, sched, day, workerAvail)) {
                return true;
                }
            }
            sched[day].pop_back();
            workerAvail[i]--;
        }
    }
    return false;
}


bool schedule(const AvailabilityMatrix& avail,
              const size_t dailyNeed,
              const size_t maxShifts,
              DailySchedule& sched) 
{
    if (avail.empty()) {
        return false;
    }
    
    sched.clear();
    sched.resize(avail.size(), std::vector<Worker_T>());
    map<Worker_T, size_t> workerAvail;
    for (Worker_T i = 0; i < avail[0].size(); i++) {
        workerAvail[i] = 0;
    }
    return Helper(avail, dailyNeed, maxShifts, sched, 0, workerAvail);
   
}
