/**
*	FileName: Hakimi.cpp
*	Author: James Muoghalu (j286m692@ku.edu)
*	Date: 3/11/18
*	Description: implementation file for Hakimi class
*/

#include "Hakimi.h"
#define PDEBUG 0 // set to 0 or 1
/*
        #if PDEBUG == 1
        #endif
*/
Hakimi::Hakimi()
{
        this->sequence = nullptr;
        this->original_sequence = nullptr;
}


Hakimi::~Hakimi()
{
        delete this->sequence;
        delete this->original_sequence;
}


bool Hakimi::runAlgorithm()
{
        bool answer = true;
        bool end = false;

        #if (PDEBUG == 1)
                int reduction_number = 1;
        #endif

        while(!end)
        {
                int first = this->sequence->at(0);
                std::vector<int>* next_iteration = new std::vector<int>();

                std::size_t i = 1;

                // perform the algorithm arithmetic
                for(; i <= (std::size_t) first; i++)
                {
                        next_iteration->push_back((this->sequence->at(i))-1);
                }
                for(std::size_t j = i; j < this->sequence->size(); j++)
                {
                        next_iteration->push_back(this->sequence->at(j));
                }

                quickSort(next_iteration, 0, (next_iteration->size()-1));

                bool found_non_zero = false;
                for(std::size_t k = 0; k < next_iteration->size(); k++)
                {
                        if(next_iteration->at(k) > 0)
                        {
                                found_non_zero = true;
                                break;
                        }
                }
                if(found_non_zero) // continue to the next iteration of the while loop
                {
                        delete this->sequence;
                        this->sequence = next_iteration;
                        #if (PDEBUG == 1)
                                std::cout << "\nReduction " << reduction_number++ << ": " << this->sequence->at(0);
                                for(std::size_t i = 1; i < this->sequence->size(); i++)
                                {
                                        std::cout << " " << this->sequence->at(i);
                                }
                                std::cout << std::endl;
                        #endif

                }

                else // else, ignore the new reduction and determine if this->sequence is graphical
                {
                        end = true;
                        delete next_iteration;
                }
        }

        if(this->sequence->at(0) >= (int) this->sequence->size())
        {
                return false;
        }

        int sum = 0;
        for(std::size_t i = 0; i < this->sequence->size(); i++)
        {
                sum +=  this->sequence->at(i);
        }
        if(sum % 2)
        {
                return false;
        }
        else
        {
                return true;
        }


        return answer;
}


// sort the given sequence
void Hakimi::quickSort(std::vector<int>* seq_to_sort, std::size_t low, std::size_t high)
{
        if(low < high && low >= 0 && high < seq_to_sort->size())
        {
                int pivot_index = partition(seq_to_sort, low, high);
                #if (PDEBUG == 1)
                        //std::cout << "\t\t\tPivot Index: " << pivot_index << std::endl;
                #endif
                quickSort(seq_to_sort, low, (pivot_index-1));
                quickSort(seq_to_sort, (pivot_index+1), high);
        }
}

// quickSort helper function
int Hakimi::partition(std::vector<int>* seq_to_sort, std::size_t low, std::size_t high)
{
        int pivot = seq_to_sort->at(high);

        std::size_t i = low-1;
        for(std::size_t j = low; j < high; j++)
        {
                if( seq_to_sort->at(j) > pivot)
                {
                        i++;
                        int temp = seq_to_sort->at(i);
                        seq_to_sort->at(i) = seq_to_sort->at(j);
                        seq_to_sort->at(j) = temp;
                }
        }
        int temp = seq_to_sort->at(i+1);
        seq_to_sort->at(i+1) = seq_to_sort->at(high);
        seq_to_sort->at(high) = temp;

        return i+1;
}
