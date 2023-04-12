#pragma once
#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include<limits>
#include <cmath>
#include<memory>
#include "Functions.h"
using namespace std;


List :: List() {
    begin = end = nullptr;
    count = 0;
}

List :: List(vector<double> a)
{
    count = a.size();
    Element* prev = nullptr;
    for (int i = 0; i < count; i++)
    {
        Element* newEl = new Element;
        newEl->ch = a[i];
        if (i == 0)
        {
            begin = newEl;
        }
        else if (i == count - 1) {
            end = newEl;
            prev->next = newEl;
        }
        else {
            prev->next = newEl;
        }
        newEl->next = nullptr;
        prev = newEl;
    }
}
List::List(List&& a) noexcept : count(a.count)
{
    swap(begin, a.begin);
    swap(end, a.end);
    a.count = NULL;
}

List:: List(Element* b)
{
    Element* tmp = b;
    Element* tmp1 = nullptr;
    if (tmp == nullptr)
    {
        begin = end = nullptr;
        count = 0;
    }
    else {
        int c = 0;
        do
        {
            Element* newEl = new Element;
            newEl->ch = tmp->ch;
            if (tmp->next == nullptr)
            {
                end = newEl;
            }
            if (c == 0)
            {
                begin = newEl;
            }
            else
            {
                tmp1->next = newEl;
            }
            c++;
            newEl->next = nullptr;
            tmp1 = tmp;
            tmp = tmp->next;
        } while (tmp != nullptr);
        count = c;
    }
}


//Done
List::List(const List& a) : count(a.count)
{
    *this = a;
}

//DONE
List :: ~List()
{
    while (begin != nullptr)
    {
        Element* t = begin;
        begin = begin->next;
        delete t;
    }
    //   cout << "Cleared" << endl;
}
void List:: Del(int index)
{
    if (count == 0)
        return;
    if ((index < 0) || (index >= count))
        return;
    if (index == 0)
    {
        Element* t = begin;
        if (count == 1) { begin = nullptr; }
        else {
            begin = begin->next;
        }
        count--;
        delete t;
    }
}
void List::Del()
{
    Del(0);
}
void List::Clear()
{
    while (begin != nullptr) {
        Del();
    }
    end = nullptr;
   // cout << "Cleared" << endl;
}

//Done
double List::getFirstEl()
{
    if (begin == nullptr) return NULL;
    return begin->ch;
}

//Done
double List::getLastEl()
{
    if (end == nullptr) return NULL;
    return end->ch;
}

//Done
double List::getNumOfEl()
{
    return count;
}


//Done
double List::findMax()
{
    if (begin == nullptr) { return NULL; }
    Element* tmp = begin;
    double max = 0;
    if (tmp != nullptr) {
        max = begin->ch;
        while (tmp != nullptr) {
            if (max < tmp->ch) max = tmp->ch;
            tmp = tmp->next;
        }
    }
    return max;
}

//Done
double List::findMin()
{
    if (begin == nullptr) { return NULL; }
    Element* tmp = begin;
    double min = 0;
    if (tmp != nullptr) {
        min = begin->ch;
        while (tmp != nullptr){
            if (min > tmp->ch) min = tmp->ch;
            tmp = tmp->next;
        } 
    }
    return min;
}

//Done
double List::findAVG()
{
    if (begin == nullptr) { return NULL; }
    Element* tmp = begin;
    double avg = 0;
    if (tmp != nullptr) {
        while (tmp != nullptr) {
            avg = avg + tmp->ch;
            tmp = tmp->next;
        }
        avg /= count;
    }
    return avg;
}

//Done
Element* List::getBegin()
{
    return begin;
}

//Done
Element* List::getEnd()
{
    return end;
}

//Done
void List::show()
{
    Element* tmp = begin;
    while (tmp != nullptr) {
        cout << tmp->ch << " ";
        tmp = tmp->next;
    } 
    cout << endl;
}

//Done
void List::choiceSort()
{
    Element* mover = begin;
    for (int i = 0; i < count; i++)
    {
        int n = 0;
        Element* tmp = begin;
        Element* min = 0;
        while (tmp != nullptr)
        {
            if (n == i) min = tmp;
            if (n > i)
            {
                if (min->ch < tmp->ch) min = tmp;
            }
            n++;
            tmp = tmp->next;
        } 
        swap(mover->ch, min->ch);
        mover = mover->next;
    }
}

//Done
void List::bubbleSort()
{
    int mistakeC = 0;
    do {
        mistakeC = 0;
        Element* tmp = begin;
        while (tmp->next != nullptr)
        {
            if (tmp->next->ch < tmp->ch)
            {
                mistakeC++;
                swap(tmp->ch, tmp->next->ch);
            }
            tmp = tmp->next;
        }
    } while (mistakeC != 0);
}

//Done
double List::getElById(int n)
{
    Element* tmp = begin;
    for (int i = 0; i < n; i++)
    {
        tmp = tmp->next;
    }
    return tmp->ch;
}

//Done
void List::skalyar(double a)
{
    Element* tmp = begin;
    do
    {
        tmp->ch = tmp->ch * a;
        tmp = tmp->next;
    } while (tmp != nullptr);
}

//Done
bool List::Checker(List& a)
{
    if (a.begin == nullptr)
    {
        cout << "List doesn't exist";
        return false;
    }
    return true;
}


//Done
List List :: operator+(double b)
{
    Element* elem = new Element;
    elem->ch = b;
    elem->next = nullptr;
    if (begin == nullptr)
    {
        begin = end = elem;
    }
    else
    {
        end->next = elem;
        end = elem;
    }
    count++;
    return *this;
}

//Done
List List :: operator - ()
{
    if (begin != nullptr) {
    Element* tmp = begin;
    if (count != 1) {
        while (tmp->next->next != nullptr)
        {
            tmp = tmp->next;
        }
    }
        tmp->next = nullptr;
        delete end;
        end = tmp;
        count--;
        if (count == 0) { begin = nullptr; }
    }
    return *this;
}

//Done
ostream& operator << (ostream& out, List& a) {
    Element* tmp = a.begin;
    while (tmp != nullptr)
    {
        out << tmp->ch << " ";
        tmp = tmp->next;
    }
    out << endl;
    return out;
}

//Done
istream& operator >> (istream& in, List& a)
{
    a.Clear();
    cout << "Enter number of elements" << endl;
    in >> a.count;
    double s = 0;
    Element* pointer = nullptr;
    cout << "Enter " << a.count << " elements" << endl;
    for (int i = 0; i < a.count; i++)
    {
        in >> s;
        Element* newEl = new Element;
        newEl->ch = s;
        newEl->next = nullptr;
        if (i == 0) { a.begin = newEl; }
        else
        {
            pointer->next = newEl;
        }
        if (i == a.count - 1)
        {
            a.end = newEl;
        }
        pointer = newEl;
    }
    return in;
}


//Done
double List :: operator[](int index)
{
    double num;
    (index <= count) ? num = getElById(index) : num = NAN;
    return num;
}

//Done
List& List :: operator=(const List& b)
{
    this->count = b.count;
    if (b.begin == nullptr)
    {
        begin = end = nullptr;
        count = 0;
    }
    else
    {
        Element* tmp1 = nullptr;
        Element* tmp = b.begin;
        int i = 0;
        while (tmp != nullptr)
        {
            Element* newEl = new Element;
            newEl->ch = tmp->ch;
            newEl->next = nullptr;
            if (i == 0) { begin = newEl; }
            else
            {
                tmp1->next = newEl;
            }
            if (tmp->next == nullptr)
            {
                end = newEl;
            }
            tmp1 = newEl;
            tmp = tmp->next;
            i++;
        }
    }
    return *this;
}
List& List :: operator=(List&& b) noexcept
{
    Clear();
    this->count = b.count;
    swap(begin, b.begin);
    swap(end, b.end);
    b.count = NULL;
    return *this;
}


