/**
*	FileName: Hakimi.h
*	Author: James Muoghalu (j286m692@ku.edu)
*	Date: 3/11/18
*	Description: header file for Hakimi class
*/

#ifndef HAKIMI_H
#define HAKIMI_H

#include <iostream>
#include <vector>
#include <ctype.h>
#include <fstream>

class Hakimi
{

        public:

                        /*
                        * @brief
                        * @param
                        * @return
                        */
                Hakimi();


                ~Hakimi();


                bool readInput(int input_choice);


                bool runAlgorithm();


                void sortSequence(std::vector<int>* seq_to_sort);


                std::vector<int>* sequence;

};
#endif
