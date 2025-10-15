/********************************************************************************
	Title: 	    LinkedListDriver.h
	Authors:    Jocelyn Lee & Kylie Truong
	Date:  	    11/1/2024
	Purpose:   Contains everything needed for the LinkedList, mergeSort & Driver
*********************************************************************************/
#ifndef LINKEDLISTDRIVER_H
#define LINKEDLISTDRIVER_H
#include <iostream>
#include <sstream>
#include "SmartPointer.h"
using namespace std;

/*********************************************/
/*              SuperList Class              */
/*********************************************/
template<typename T>
class SuperList
{
private:
    /*listNode struct*/
    struct listNode
    { 
        SmartPointer<T> data;
        listNode * next;
        listNode * previous;
        /*Constructor for listNode*/
        listNode(const T& heroData) : data(SmartPointer<T>(new T(heroData))), next(nullptr), previous(nullptr) {}
    };
    /*Private Variables*/
    int size;
    listNode * head;
    listNode * tail; 

    /*Helper functions for mergeSort*/
    listNode* mergeSort(listNode* node, bool ascending);
    listNode* split(listNode* top) 
    {
        listNode* fast = top;
        listNode* slow = top;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        listNode* middle = slow->next;
        slow->next = nullptr;
        return middle;
    }
    listNode* merge(listNode* left, listNode* right, bool ascending) 
    {
        if (!left) return right;
        if (!right) return left;

        if ((ascending && *left->data <= *right->data) || (!ascending && *left->data > *right->data)) {
            left->next = merge(left->next, right, ascending);
            left->next->previous = left;
            left->previous = nullptr;
            return left;
        } else {
            right->next = merge(left, right->next, ascending);
            right->next->previous = right;
            right->previous = nullptr;
            return right;
        }
    }

public:
    /*Constructor*/
    SuperList()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    /*Destructor*/
    ~SuperList(); 

    /*Function Prototypes*/
    void appendSuperHero(const T& heroData);
    void printHeroesTop() const;
    void printHeroesBottom() const;
    bool removeHero(const T& hero);
    void mergeSort(bool ascending = true);
    bool getAtHero(int index, T& value) const;
    void printHeroesByIndex() const;
    int getSize() const { return size; }
    template<typename U>
    friend ostream& operator<<(ostream& os, const SuperList<U>& list);
};

/*********************************************/
/*                 ~SuperList                */
/*********************************************/
template<typename T>
SuperList<T>::~SuperList()
{
    listNode * nodePtr = head;
    listNode * nextNode; 
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

/*********************************************/
/*              appendSuperHero              */
/*********************************************/
template<typename T>
void SuperList<T>::appendSuperHero(const T& heroData)
{
    listNode* newNode = new listNode(heroData);
    newNode->data = SmartPointer<T>(new T(heroData));
    newNode->next = nullptr;
    newNode->previous = nullptr; 
    if (!head)
    { 
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail -> next = newNode;
        newNode -> previous = tail; 
        tail = newNode; 
    }
    mergeSort();
    size++;
}

/*********************************************/
/*              printHeroesTop               */
/*********************************************/
template <typename T>
void SuperList<T>::printHeroesTop() const
{
    cout << "Top Ranked Heroes!\n";
    for (int i = 0; i < size; ++i) 
    {
        T hero("", 0, ""); 
        if (getAtHero(i, hero)) 
        {
            cout << "RANK " << hero.getRank() << ": " << hero.getName() << endl; 
        }
    }
}

/*********************************************/
/*             printHeroesBottom             */
/*********************************************/
template <typename T>
void SuperList<T>::printHeroesBottom() const
{
    cout << "Bottom Ranked Heroes!\n";
    for (int i = size - 1; i >= 0; --i) 
    {
        T hero("", 0, ""); 
        if (getAtHero(i, hero)) 
        {
            cout << "RANK " << hero.getRank() << ": " << hero.getName() << endl; 
        }
    }
}

/*********************************************/
/*                 mergeSort                 */
/*********************************************/
template<typename T>
void SuperList<T>::mergeSort(bool ascending)
{
    if (!head || !head->next) return;
    head = mergeSort(head, ascending);
    
    listNode* temp = head;
    while (temp && temp->next) {
        temp = temp->next;
    }
    tail = temp;
}

template<typename T>
typename SuperList<T>::listNode* SuperList<T>::mergeSort(listNode* node, bool ascending)
{
    if (!node || !node->next) return node;
    listNode* middle = split(node);
    listNode* left = mergeSort(node, ascending);
    listNode* right = mergeSort(middle, ascending);

    return merge(left, right, ascending);
}

/*********************************************/
/*                 removeHero                */
/*********************************************/
template<typename T>
bool SuperList<T>::removeHero(const T& hero) 
{
    if (!head)
    {
        cout << "There are no heroes in the list.";
        return false;
    }
    
    listNode* superHero = head;

    while (superHero != nullptr && *superHero->data != hero)
    {
        superHero = superHero->next;
    }

    if (!superHero) 
    {
        cout << "This superhero is not in the list.";
        return false;
    }

    if (superHero == head)
    {
        head = head->next;
        if (head)
            head->previous = nullptr;
        else
            tail = nullptr;
    }
    else if (superHero == tail)
    {
        tail = tail->previous;
        tail->next = nullptr;
    }
    else
    {
        superHero->previous->next = superHero->next;
        superHero->next->previous = superHero->previous;
    }

    delete superHero;
    size--;
    cout << "The superhero " << hero.getName() << " has been deleted from the list.";
    mergeSort();
    return true;
}

/*********************************************/
/*                getAtHero                  */
/*********************************************/
template<typename T>
bool SuperList<T>::getAtHero(int index, T& hero) const 
{
    if (index < 0 || index >= size) {  
        return false;
    }

    listNode * current = head;
    int count = 0;

    while (current != nullptr) 
    {
        if (count == index) {
            hero = *(current -> data);
            return true;
        }
        current = current -> next;
        count++;
    }

    return false;
}

/*********************************************/
/*           printHeroesByIndex              */
/*********************************************/
template<typename T>
void SuperList<T>::printHeroesByIndex() const 
{
    listNode* current = head; 
    int index = 0;

    while (current != nullptr) 
    {
        cout << "Index " << index << ": " << *(current->data) << endl;
        current = current->next; 
        index++; 
    }
}

/*********************************************/
/*                operator<<                 */
/*********************************************/
template<typename T>
ostream& operator<<(ostream& os, const SuperList<T>& list) 
{
    typename SuperList<T>::listNode* current = list.head;
    if (!current) {
        os << "The list is empty." << endl;
        return os;
    }

    while (current) {
        os << *(current->data) << " " << endl; 
        current = current -> next;
    }
    return os;
}

#endif