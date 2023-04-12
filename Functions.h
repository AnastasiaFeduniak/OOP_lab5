#pragma once
#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include<limits>
#include <cmath>

using namespace std;

struct Element
{
    double ch;
    Element* next;
};
class List
{
private:
    Element* begin;
    Element* end;
    int count;
public:
    List();
    List(vector<double> a);
    List(List&& a) noexcept;
    List(Element* b);
    List(const List& a);
    ~List();
    void Del(int index);
    void Del();
    void Clear();
    double getFirstEl();
    double getLastEl();
    double getNumOfEl();
    double findMax();
    double findMin();
    double findAVG();
    Element* getBegin();
    Element* getEnd();
    void show();
    void choiceSort();
    void bubbleSort();
    double getElById(int n);
    void skalyar(double a);
    bool Checker(List& a);
    List operator+(double b);
    List operator - ();
    friend ostream& operator << (ostream& out, List& a);
    friend istream& operator >> (istream& in, List& a);
    double operator[](int index);
    List& operator=(const List& b);
    List& operator=(List&& b) noexcept;
  
};

