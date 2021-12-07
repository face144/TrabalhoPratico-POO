//
// Created by jedua on 05/12/2021.
//

#ifndef TRABALHOPRATICO_POO_RELOADED_RESOURCE_H
#define TRABALHOPRATICO_POO_RELOADED_RESOURCE_H


class Resource {
private:
    int quantity;
    int sell_money;

public:
    Resource();
    ~Resource();

    void SetQuantity(int quantity);
};


#endif //TRABALHOPRATICO_POO_RELOADED_RESOURCE_H
