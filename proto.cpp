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
    virtual void slap_stick() = 0;
};

class Elliptical: public proto
{
public:
    void slap_stick()
    {
        std::cout << "Elliptical added to gym\n";
    }
};
class Row: public proto
{
public:
    void slap_stick()
    {
        std::cout << "Rowing machine added to gym\n";
    }
};
class Tredmill: public proto
{
public:
    void slap_stick()
    {
        std::cout << "Tredmill added to gym\n";
    }
};
