//
//  main.cpp
//  assignment2
//
//  Created by Bridget Rassell on 2015-11-15.
//  Copyright © 2015 Bridget Rassell. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>

class Gym_Equipment{
public:
    virtual Gym_Equipment* clone()=0;
    virtual void gym_add()=0;
};

class Factory {
public:
    static Gym_Equipment* make( int choice );
private:
    static Gym_Equipment* s_prototypes[4];
};


class Elliptical: public Gym_Equipment
{
public:
    Gym_Equipment* clone()
    {
        return new Elliptical;
    }
    void gym_add()
    {
        std::cout << "Elliptical added to gym\n";
    }
};

class Row: public Gym_Equipment
{
public:
    Gym_Equipment* clone() {
        return new Row;
    }
    void gym_add()
    {
        std::cout << "Rowing machine added to gym\n";
    }
};
class Tredmill: public Gym_Equipment
{
public:
    Gym_Equipment* clone() {
        return new Tredmill;
    }
    void gym_add()
    {
        std::cout << "Tredmill added to gym\n";
    }
};

Gym_Equipment* Factory::s_prototypes[] = {
    0, new Elliptical, new Row, new Tredmill
};
Gym_Equipment* Factory::make( int choice ) {
    return s_prototypes[choice]->clone();
}



int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    
    std::vector<Gym_Equipment> equip;
    int choice;
    
    while(1)
    {
        std::cout<< "Enter the number beside the machine you wish to add to the weightroom. press 0 to quit! \n" <<"Elliptical: 1\nRowing Machine: 2\nTredmill: 3\n";
        std::cin>> choice;
        if(choice==0)
            break;
        else
            equip.push_back(*Factory::make(choice));
        
    }
    
    return 0;
};
