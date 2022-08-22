#ifndef EMP_
#define EMP_

#include <iostream>
#include <string>
#include <iomanip>

namespace mns
{
using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::setw;
using std::left;

class abstr_emp
{
private:
    string fname;
    string lname;
    string job;
public:
    abstr_emp(const string& fn = "fn", const string& ln = "ln", const string& jb = "jb"): fname(fn), lname(ln), job(jb) { }
    virtual void ShowAll(ostream& os) const;
    virtual void SetAll(istream& os);
    friend ostream& operator<<(ostream&, const abstr_emp&);
    friend istream& operator>>(istream&, abstr_emp&);
    virtual ~abstr_emp() = 0;
};


class employee: public abstr_emp
{
public:
    employee(const string& fn = "fn", const string& ln = "ln", const string & jb = "jb"): abstr_emp(fn, ln, jb) { }
    virtual void ShowAll(ostream& os) const { abstr_emp::ShowAll(os); }
    virtual void SetAll(istream& os) { abstr_emp::SetAll(os); }
    ~employee() { }
};

class manager: virtual public abstr_emp
{
private:
    int inchargeof;
protected:
    int inChargeOf() const { return inchargeof; }
    int & inChargeOf() { return inchargeof; }
public:
    manager(const string& fn = "fn", const string& ln = "ln", const string& jb = "jb", int ico = 0): abstr_emp(fn, ln, jb), inchargeof(ico) { }
    manager(const abstr_emp& e, int ico): abstr_emp(e), inchargeof(ico) { }
    manager(const manager& m) : abstr_emp(m), inchargeof(m.inchargeof) { }
    virtual void ShowAll(ostream&) const;
    virtual void SetAll(istream&);
    ~manager() { }
};

class fink: virtual public abstr_emp
{
private:
    string reportsto;
protected:
    const string ReportsTo() const { return reportsto; }
    string & ReportsTo() { return reportsto; }
public:
    fink(const string& fn = "fn", const string& ln = "ln", const string& jb = "jb",
         const string& rpo = "rpo"): abstr_emp(fn, ln, jb), reportsto(rpo) { }
    fink(const abstr_emp& e, const string& rpo): abstr_emp(e), reportsto(rpo) { }
    fink(const fink& e): abstr_emp(e), reportsto(e.reportsto) { }
    virtual void ShowAll(ostream&) const;
    virtual void SetAll(istream&);
    ~fink() { }
};

class highfink: public fink, public manager
{
public:
    highfink(const string& fn = "fn", const string& ln = "ln", const string& jb = "jb", const string& rpo = "rpo", int ico = 0): abstr_emp(fn, ln, jb), fink(fn, ln, jb, rpo), manager(fn, ln, jb, ico) { }
    highfink(const abstr_emp& e, const string& rpo, int ico): abstr_emp(e), manager(e, ico) { }
    highfink(const fink& f, int ico): abstr_emp(f), fink(f), manager(f, ico) { }
    highfink(const manager& m, const string& rpo): abstr_emp(m), fink(m, rpo), manager(m) { }
    highfink(const highfink& h): abstr_emp(h), fink(h), manager(h) { }
    virtual void ShowAll(ostream&) const;
    virtual void SetAll(istream&);
    ~highfink() { }
};

}

#endif
