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

UList::UList()
{
    begin = nullptr;
    end = nullptr;
    count = 0;
}
UList::UList(vector<double> a)
{
    count = a.size();
    Element* prev = nullptr;
    for (int i = 0; i < count; i++)
    {
        Element* newEl = new Element;
        newEl->ch = a[i];
        if (i == 0)
        {
            begin = make_unique<Element*>(newEl);
        }
        else {
            prev->next = newEl;
        }
    	if (i == count - 1) {
            end = make_unique<Element*>(newEl);
        }
        newEl->next = nullptr;
        prev = newEl;
    }
}
void UList::show()
{
    if (begin != nullptr) {
        cout << (*begin)->ch << " ";
        shared_ptr<Element*> tmp = make_shared<Element*>((*begin)->next);
        for (int i = 1; i < count - 1; i++) {
            cout << (*tmp)->ch << " ";
            tmp = make_shared<Element*>((*tmp)->next);
        }
        if(count != 1)
    	cout << (*end)->ch << endl;
    }
}
double UList::getFirstEl()
{
    if(begin == nullptr)
    {
        return NULL;
    }
    return (*begin)->ch;
}
double UList::getLastEl()
{
    if (end == nullptr)
    {
        return NULL;
    }
    return (*end)->ch;
}
double UList::getNumOfEl()
{
    return count;
}
UList::UList(UList& a)
{
    *this = a;
}
UList::UList(UList&& a) noexcept
{
    begin = move(a.begin);
    end = move(a.end);
    count = a.getNumOfEl();
    a.count = 0;
}
UList :: ~UList() {}
double UList::findMax()
{
    if (begin == nullptr) { return NULL; }
    shared_ptr<Element*> tmp = make_shared<Element*>((*begin)->next);
    double max;
    ((*begin)->ch >= (*end)->ch) ? max = (*begin)->ch : max = (*end)->ch;
    if (tmp != nullptr) {
        for (int i = 1; i < count - 1; i++) {
            if (max < (*tmp)->ch) { max = (*tmp)->ch; }
            tmp = make_shared<Element*>((*tmp)->next);
        }
    }
    return max;
}
double UList::findMin()
{
    if (begin == nullptr) { return NULL; }
    shared_ptr<Element*> tmp = make_shared<Element*>((*begin)->next);
    double min;
    ((*begin)->ch <= (*end)->ch) ? min = (*begin)->ch : min = (*end)->ch;
    if (tmp != nullptr) {
        for (int i = 1; i < count - 1; i++) {
            if (min > (*tmp)->ch) { min = (*tmp)->ch; }
            tmp = make_shared<Element*>((*tmp)->next);
        }
    }
    return min;
}
double UList::findAVG()
{
    if (begin == nullptr) { return NULL; }
    shared_ptr<Element*> tmp = make_shared<Element*>((*begin)->next);
    double avg = (*begin)->ch + (*end)->ch;
    if (tmp != nullptr) {
        for (int i = 1; i < count - 1; i++) {
            avg += (*tmp)->ch;
            tmp = make_shared<Element*>((*tmp)->next);
        }
    }
    return avg / count;
}
void UList::bubbleSort() {
    if (begin != nullptr) {
        int mistakeC = 0;
        do {
            mistakeC = 0;
            Element* tmp = *(begin.get());
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
}
void UList::choiceSort() {
    if (begin != nullptr) {
        for (Element* i = *(begin.get()); i != nullptr; i = i->next)
        {
            Element* max = i;
            for (Element* j = i->next; j != nullptr; j = j->next)
            {
                if (j->ch > max->ch)
                {
                    max = j;
                }
            }
            if (max != i)
            {
                double tmp = i->ch;
                i->ch = max->ch;
                max->ch = tmp;
            }
        }
    }
}


void UList::skalyar(double a)
{
    (*begin)->ch *= a;
    (*end)->ch *= a;
    shared_ptr<Element*> tmp = make_shared<Element*>((*begin)->next);
    for (int i = 1; i < count - 1; i++) {
        (*tmp)->ch *= a;
        tmp = make_shared<Element*>((*tmp)->next);
    }
}


ostream& operator << (ostream& out, UList& a)
{
    Element* curr = nullptr;
    if (a.begin != nullptr) {
        curr = *(a.begin.get());
    }
    for (int i = 0; i < a.count; i++) {
        out << curr->ch << " ";
        curr = curr->next;
    }
    out << endl;
    return out;
}
double UList :: operator[](int index)
{
    if (index >= count) { return NAN; }
    if (index == 0) return (*begin)->ch;
    if (index == count - 1) return (*end)->ch;
    shared_ptr<Element*> tmp = make_shared<Element*>((*begin)->next);
    for (int i = 1; i < index; i++)
    {
        tmp = make_shared<Element*>((*tmp)->next);
    }
    return (*tmp)->ch;
}
istream& operator >> (istream& in, UList& a)
{
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
        if (i == 0) { a.begin = make_unique<Element*>(newEl); }
        else
        {
            pointer->next = newEl;
        }
        if (i == a.count - 1)
        {
            a.end = make_unique<Element*>(newEl);
        }
        pointer = newEl;
    }
    return in;
}
UList& UList :: operator=(UList& b) {

    count = b.count;
    Element* prev = nullptr;
    for (int i = 0; i < count; i++)
    {
        Element* newEl = new Element;
        newEl->ch = b[i];
        if (i == 0)
        {
            begin = make_unique<Element*>(newEl);
        }
        else if (i == count - 1) {
            end = make_unique<Element*>(newEl);
            prev->next = newEl;
        }
        else {
            prev->next = newEl;
        }
        newEl->next = nullptr;
        prev = newEl;
    }
    return *this;
}

UList& UList :: operator=(UList&& b) noexcept
{
    begin = move(b.begin);
    end = move(b.end);
    count = b.getNumOfEl();
    b.count = 0;
    return *this;
}
UList UList :: operator - ()
{
    if (begin != nullptr) {
        if (count == 1)
        {
            Element* u = *(begin.release());
            delete u;
            begin = nullptr;
            end = nullptr;
            count--;
            return *this;
        }
        unique_ptr<Element*> tmp = make_unique<Element*>((*begin)->next);
        for (int i = 1; i < count - 2; i++) {
            tmp = make_unique<Element*>((*tmp)->next);
        }
        (*tmp)->next = nullptr;
        Element* u = *(end.release());
        delete u;
        end = make_unique<Element*>(*tmp);
        count--;
    }
    return *this;
}
UList UList :: operator+(double b)
{
    Element* newEl = new Element;
    newEl->ch = b;
    newEl->next = nullptr;
    if(count == 0)
    {
        begin = make_unique<Element*>(newEl);
    }
    else {
        (*end)->next = newEl;
    }
    end = make_unique<Element*>(newEl);
    count++;
    return *this;
}
