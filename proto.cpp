//
//  proto.cpp
//  ass2
//
//  Created by Bridget Rassell on 2015-11-15.
//  Copyright © 2015 Bridget Rassell. All rights reserved.
//

#include <iostream>
#include "proto.hpp"


class proto{
public:
    virtual void add_equipment() = 0;
};

class Elliptical: public proto
{
public:
    void add()
    {
        std::cout << "Elliptical added to gym\n";
    }
};
class Row: public proto
{
public:
    void add_equipment()
    {
        std::cout << "Rowing machine added to gym\n";
    }
};
class Tredmill: public proto
{
public:
    void add_equipment()
    {
        std::cout << "Tredmill added to gym\n";
    }
};
