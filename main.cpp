//
//  main.cpp
//  ass2final
//
//  Created by Bridget Rassell on 2015-11-16.
//  Copyright © 2015 Bridget Rassell. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
const int N = 6;

// Prototype
class Character
{
public:
    virtual Character* clone() const = 0;
    virtual void store() const = 0;
    virtual ~Character() { }
};


// Concrete prototypes : Bridget, James, Will

class Bridget : public Character
{
public:
    Character*   clone() const { return new Bridget; }
    void store() const { cout << "Bridget\n"; }
};

class James : public Character
{
public:
    Character* clone() const { return new James; }
    void store() const { cout << "James\n"; }
};

class Will : public Character
{
public:
    Character* clone() const { return new Will; }
    void store() const { cout << "Will\n"; }
};

class Brady : public Character
{
public:
    Character* clone() const { return new Brady; }
    void store() const { cout << "Brady\n"; }
};

class Mo : public Character
{
public:
    Character* clone() const { return new Mo; }
    void store() const { cout << "Mo\n"; }
};

// makeCharacter() calls Concrete Portotype's clone() method
// inherited from Prototype
class CharacterBuilder {
public:
    static Character* make( int choice );
    ~CharacterBuilder (){}
    
private:
    static Character* myPlayers[N];
};

Character* CharacterBuilder ::myPlayers[] =
{
    0, new Bridget, new James, new Will, new Brady, new Mo
};

Character* CharacterBuilder ::make( int choice )
{
    return myPlayers[choice]->clone();
}

// for_each op ()
struct Destruct
{
    void operator()(Character *a) const {
        delete a;
    }
};

// main program
int main() {
    vector<Character*> players(N);
    int choice;
    cout << "end(0), Bridget(1), James(2), Will(3), Brady(4), Mo(5): \n";
    while (true) {
        cout << "Type in your character of choice to play for your team!(0-3)\n";
        cin >> choice;
        if (choice <= 0 || choice >= N)
            break;
        players[choice] = CharacterBuilder::make( choice );
    }
    
    for (int i = 1; i < players.size(); ++i)
        if(players[i]) players[i]->store();
    
    Destruct d;
    // this calls Destruct::operator()
    for_each(players.begin(), players.end(), d);
    
    return 0;
}
