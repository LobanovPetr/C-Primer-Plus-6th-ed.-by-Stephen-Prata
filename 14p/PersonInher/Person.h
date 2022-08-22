#ifndef PERSON_
#define PERSON_
#include <string>

namespace mns
{
using std::string;

class Person
{
private:
    string fullname;
protected:
    virtual void Data() const;
public:
    Person(const string& s = "Person_name"): fullname(s) {}
    virtual void Show() const = 0;
    virtual ~Person() {};
};

class Gunslinger: virtual public Person
{
private:
    int cut;
    double time;
protected:
    virtual void Data() const;
public:
    Gunslinger(const string& s = "Person_name", int c = 0, double tm = 1.) : Person(s), cut(c), time(tm) { }
    Gunslinger(const Person& p, int c = 0, double tm = 1.) : Person(p), cut(c), time(tm) { }
    double Draw() const { return time; }
    virtual void Show() const { Person::Data(); Data();};
};

class PokerPlayer: virtual public Person
{
protected:
    void Data() const {Person::Data();}
public:
    PokerPlayer(const string& s = "Person_name"): Person(s) {}
    void Show() const {Person::Show();}
    int Draw() const;
};

class BadDude: public Gunslinger, public PokerPlayer
{
protected:
    void Data() const {Person::Data(); Gunslinger::Data(); }
public:
    BadDude(const string& s = "Person_name", int c = 0, double tm = 1.): Person(s), Gunslinger(s, c, tm) {}
    BadDude(const Person& p, int c = 0, double tm = 1.): Person(p), Gunslinger(p, c, tm) {}
    BadDude(const Gunslinger& gs): Person(gs), Gunslinger(gs) {}
    BadDude(const PokerPlayer& pp, int c = 0, double tm = 1.): Person(pp), Gunslinger(pp, c, tm) {}
    
    double Gdraw() const { return Gunslinger::Draw(); }
    int Cdraw() const { return PokerPlayer::Draw(); }
    void Show() const {Data();}
};

}

#endif
