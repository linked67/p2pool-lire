#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <math.h> 

static const int64_t COIN = 100000000;

int64_t static GetBlockBaseValue(int nBits, int nHeight)
{

  int64_t nSubsidy = 50 * COIN;

        if (nHeight == 1)
                nSubsidy = 25000000 * COIN; // Premine

        if (nHeight >= 2 && nHeight <= 30) // 0 Reward blocks to confirms premine
                nSubsidy = 0 * COIN;

        if (nHeight >= 31 && nHeight <= 300 ) // Allow miners to set up 
                nSubsidy = 5 * COIN;

  
    nSubsidy >>= (nHeight / 350000); 

    return nSubsidy;

}


#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
using namespace boost::python;
 
BOOST_PYTHON_MODULE(lirecoin_subsidy)
{
    def("GetBlockBaseValue", GetBlockBaseValue);
}

