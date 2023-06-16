#pragma once

#include <vector>
#include <iterator>
#include <set>
#include <list>

using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> elements;
        vector<int*> sortElem;
        vector<int*> crossElem;
        vector<int*> primeElem;

    public:
        void addElement(int element);
        void removeElement(int element);
        int size(){return elements.size();}
        void updateAll(){
            updateCross();
            updatePrime();
            updateSort();
        }
        void updateCross();
        void updateSort();
        void updatePrime();
        void sortRegularElem();
        bool isPrime(int);

        // Returns the size of the vector
        size_t size() const { return elements.size(); }
        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            size_t currentIdx;
            vector<int*>::iterator iter;

        public:
            // Constructors
            AscendingIterator(MagicalContainer &cont);
            AscendingIterator(const AscendingIterator &other);
            // Move constructor
            AscendingIterator(AscendingIterator &&other) noexcept = default;
            // Copy assignment operator
            AscendingIterator &operator=(const AscendingIterator &other);
            // Move assignment operator
            AscendingIterator &operator=(AscendingIterator &&other) noexcept{
                return *this;
            }
            ~AscendingIterator() = default;

            // Operators

            // Comparison operators
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;

            // Dereference operator
            int operator*() const;

            AscendingIterator &operator++();
            
            // Getters
            AscendingIterator &begin();
            AscendingIterator &end();
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &container;
            size_t currentIdx;
            vector<int*>::iterator iter;

        public:
            // Constructors
            SideCrossIterator(MagicalContainer &cont);
            SideCrossIterator(const SideCrossIterator &other);
            // Move constructor
            SideCrossIterator(SideCrossIterator &&other) noexcept = default;
            // Copy assignment operator
            SideCrossIterator &operator=(const SideCrossIterator &other);
            // Move assignment operator
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept{
               return *this;
            }
            ~SideCrossIterator() = default;

            // Operators

            // Comparison operators
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;

            // Dereference operator
            int operator*() const;

            SideCrossIterator &operator++();
            
            // Getters
            SideCrossIterator &begin();
            SideCrossIterator &end();
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            size_t currentIdx;
            vector<int*>::iterator iter;

        public:
            // Constructors
            PrimeIterator(MagicalContainer &cont);
            PrimeIterator(const PrimeIterator &other);
            // Move constructor
            PrimeIterator(PrimeIterator &&other) noexcept = default;
            // Copy assignment operator
            PrimeIterator &operator=(const PrimeIterator &other);
            // Move assignment operator
            PrimeIterator &operator=(PrimeIterator &&other) noexcept{
                return *this;
            }
            ~PrimeIterator() = default;

            // Operators

            // Comparison operators
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;

            // Dereference operator
            int operator*() const;

            PrimeIterator &operator++();
            
            // Getters
            PrimeIterator &begin();
            PrimeIterator &end();
        };
    };
}