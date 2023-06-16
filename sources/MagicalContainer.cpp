#include "MagicalContainer.hpp"
#include <math.h>
#include <algorithm>

using namespace std;

namespace ariel
{
    bool MagicalContainer::isPrime(int element){
        if(element <= 1){return false;}
        else if(element == 2){return true;}
        else{
            for(int i = 2;i <sqrt(element) + 1;i++){
                if(element%i == 0){return false;}
            }
            return true;
        }
    }
    void MagicalContainer::sortRegularElem() {
        for(unsigned long i = 0;i<elements.size();i++)
        {
            for(unsigned long j = 0;j<elements.size()-i-1;j++)
            {
                if(elements[j] > elements[j+1]){
                    int tem = elements[j];
                    elements[j] = elements[j+1];
                    elements[j+1] = tem;
                }
            }
        }
    }

    void MagicalContainer::updateSort()
    {
        sortElem.clear();
        for (auto iter = elements.begin(); iter != elements.end(); ++iter)
        {
            sortElem.push_back(&(*iter));
        }
    }

    void MagicalContainer::updatePrime()
    {
        primeElem.clear();
        for (auto iter = elements.begin(); iter != elements.end(); ++iter)
        {
            if (isPrime(*iter))
            {
                primeElem.push_back(&(*iter));
            }
        }
    }

    void MagicalContainer::updateCross()
    {
        crossElem.clear();
        auto start = elements.begin();
        auto end = --elements.end();

        while(start < end)
        {
            crossElem.push_back(&(*start));
            crossElem.push_back(&(*end));
            start++;
            end--;
        }
        if (start == end)
        {
            crossElem.push_back(&(*start));
        }

    }

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
  

    // Magical Container
    void MagicalContainer::addElement(int element) {
        // Add to elements
        elements.push_back(element);
        sortRegularElem();

        // Add to sorted, prime and cross.
        updateAll();
    }

    void MagicalContainer::removeElement(int element) {
        // Check if the element in elements vector
        bool present = false;
        for (auto iter = elements.begin(); iter != elements.end(); ++iter)
        {
            if (*iter == element)
            {
                present = true;
                break;
            }
        }
        if (!present)
        {
            throw std::runtime_error("Invalid argument");
        }

        // Remove from elements
        elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());

        // Remove from sorted, prime and cross.
        updateAll();
    }

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
    
    // AscendingIterator

    // Constructors

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &cont) : container(cont), iter(container.sortElem.begin()), currentIdx(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container),iter(other.iter), currentIdx(other.currentIdx) {}

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        // If they are not the same container
        if(&container != &other.container)
        {
            throw std::runtime_error("Invalid argument");
        }
        currentIdx = other.currentIdx;
        iter = other.iter;
        return *this;
    }

    // Comparison operators
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        // Checking wether they are not the same container
        if(&container != &other.container){
            throw std::invalid_argument("Invalid argument");
        }
        return currentIdx == other.currentIdx;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        // Checking wether they are not the same container
        if(&container != &other.container){
            throw std::invalid_argument("Invalid argument");
        }
        return currentIdx < other.currentIdx;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        // Checking wether they are not the same container
        if(&container != &other.container){
            throw std::invalid_argument("Invalid argument");
        }
        return currentIdx > other.currentIdx;
    }

    int MagicalContainer::AscendingIterator::operator*() const
    {
        if(iter == container.sortElem.end()){
            throw std::out_of_range("Out of range");
        }
        return **iter;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if(iter == container.sortElem.end())
        {
            throw std::runtime_error("Out of range");
        }
        ++currentIdx;
        ++iter;
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin(){
        // Iterates to the beginning of the container
        iter = container.sortElem.begin();
        currentIdx = 0;
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end(){
        // Iterates to the end of the container
        iter = container.sortElem.end();
        currentIdx = container.sortElem.size();
        return *this;
    }

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
    
    // SideCrossIterator

    // Constructors

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &cont) : container(cont), iter(container.crossElem.begin()), currentIdx(0) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container),iter(other.iter), currentIdx(other.currentIdx) {}

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        // If they are not the same container
        if(&container != &other.container)
        {
            throw std::runtime_error("Invalid argument");
        }
        currentIdx = other.currentIdx;
        iter = other.iter;
        return *this;
    }

    // Comparison operators
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        // Checking wether they are not the same container
        if(&container != &other.container){
            throw std::invalid_argument("Invalid argument");
        }
        return currentIdx == other.currentIdx;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        // Checking wether they are not the same container
        if(&container != &other.container){
            throw std::invalid_argument("Invalid argument");
        }
        return currentIdx < other.currentIdx;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        // Checking wether they are not the same container
        if(&container != &other.container){
            throw std::invalid_argument("Invalid argument");
        }
        return currentIdx > other.currentIdx;
    }

    int MagicalContainer::SideCrossIterator::operator*() const
    {
        if(iter == container.crossElem.end()){
            throw std::out_of_range("Out of range");
        }
        return **iter;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if(iter == container.crossElem.end())
        {
            throw std::runtime_error("Out of range");
        }
        ++currentIdx;
        ++iter;
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::begin(){
        // Iterates to the beginning of the container
        iter = container.crossElem.begin();
        currentIdx = 0;
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::end(){
        // Iterates to the end of the container
        iter = container.crossElem.end();
        currentIdx = container.crossElem.size();
        return *this;
    }

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
    
    // PrimeIterator

    // Constructors

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &cont) : container(cont), iter(container.primeElem.begin()), currentIdx(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container),iter(other.iter), currentIdx(other.currentIdx) {}

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        // If they are not the same container
        if(&container != &other.container)
        {
            throw std::runtime_error("Invalid argument");
        }
        currentIdx = other.currentIdx;
        iter = other.iter;
        return *this;
    }

    // Comparison operators
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        // Checking wether they are not the same container
        if(&container != &other.container){
            throw std::invalid_argument("Invalid argument");
        }
        return currentIdx == other.currentIdx;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        // Checking wether they are not the same container
        if(&container != &other.container){
            throw std::invalid_argument("Invalid argument");
        }
        return currentIdx < other.currentIdx;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        // Checking wether they are not the same container
        if(&container != &other.container){
            throw std::invalid_argument("Invalid argument");
        }
        return currentIdx > other.currentIdx;
    }

    int MagicalContainer::PrimeIterator::operator*() const
    {
        if(iter == container.primeElem.end()){
            throw std::out_of_range("Out of range");
        }
        return **iter;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if(iter == container.primeElem.end())
        {
            throw std::runtime_error("Out of range");
        }
        ++currentIdx;
        ++iter;
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::begin(){
        // Iterates to the beginning of the container
        iter = container.primeElem.begin();
        currentIdx = 0;
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::end(){
        // Iterates to the end of the container
        iter = container.primeElem.end();
        currentIdx = container.primeElem.size();
        return *this;
    }
}