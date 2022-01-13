#ifndef TP_POO_RELOADED_RESOURCES_H
#define TP_POO_RELOADED_RESOURCES_H


#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Resource{
protected:
    string type;
    float* value;
    int* quantity;
    int* max;

public:
    Resource();
    static Resource* Create(string type);

    int* GetMax();
    int* GetQuant();
    string GetType();
    float* GetValue();

    void SetMax(int &max);
    void SetQuant(int &quant);

};

class Iron : public Resource {
public:

};

class Steel : public Resource {
public:

};

class Coal : public Resource {
public:

};

class Wood : public Resource {
public:

};

class WoodBeam : public Resource {
public:

};

class Eletricity : public Resource {
public:

};

#endif //TP_POO_RELOADED_RESOURCES_H
