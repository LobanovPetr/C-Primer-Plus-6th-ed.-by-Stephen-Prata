#ifndef WORKERMI_
#define WORKERMI_
#include <string>

class Worker
{
private:
    std::string fullname;
    long id;
protected:
    virtual void Data() const; // show data for each class (module function)
    virtual void Get(); // take information for fullname and id
public:
    Worker() : fullname("no one"), id(0L) { }
    Worker(const std::string& s, long n) : fullname(s), id(n) { }
    virtual ~Worker() { };
    virtual void Set() = 0; // call Get() for each class
    virtual void Show() const = 0; // call Data to show information
};

class Waiter: virtual public Worker
{
private:
    int panache;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Waiter(): Worker(), panache(0) { }
    Waiter(const std::string& s, long n, int p = 0): Worker(s, n), panache(p) { }
    Waiter(const Worker& wk, int p = 0): Worker(wk), panache(p) { }
    virtual void Set();
    virtual void Show() const;
};

class Singer: virtual public Worker
{
protected:
    enum { other, alto, contralto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};
    virtual void Data() const;
    virtual void Get();
private:
    static const char *pv[Vtypes];
    int voice;
public:
    Singer(): Worker(), voice(other) { }
    Singer(const std::string& s, long n, int v = other): Worker(s, n), voice(v) { }
    Singer(const Worker& wk, int v = other): Worker(wk), voice(v) { }
    virtual void Set();
    virtual void Show() const;
};

class SingerWaiter: public Singer, public Waiter
{
protected:
    virtual void Data() const;
    virtual void Get();
public:
    SingerWaiter() { }
    SingerWaiter(const std::string& s, long n, int p = 0, int v = other): Worker(s, n), Waiter(s, n, p), Singer(s, n, v) { }
    SingerWaiter(const Worker& wk, int p = 0, int v = other): Worker(wk), Waiter(wk, p), Singer(wk, v) { }
    SingerWaiter(const Waiter& wt, int v = other): Worker(wt), Waiter(wt), Singer(wt, v) { }
    SingerWaiter(const Singer& sg, int p = 0): Worker(sg), Waiter(sg, p), Singer(sg) { }
    virtual void Set();
    virtual void Show() const;
};


#endif
