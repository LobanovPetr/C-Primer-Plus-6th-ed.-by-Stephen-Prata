#ifndef TV_
#define TV_
#include <iostream>

namespace mns
{
class Remote;
class Tv
{
    friend class Remote;
private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
public:
    enum {Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};
    Tv(int s = Off, int mc = 124) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() { state ^= 1; }
    bool ison() const { return state == On; }
    bool volup() { if (volume == MaxVal) return false; ++volume; return true; }
    bool voldown() { if (volume == MinVal) return false; --volume; return true; }
    void chanup() { channel = (channel + 1) % maxchannel + 1; }
    void chandown() { channel = (channel - 1 + maxchannel) % maxchannel + 1; }
    void set_mode() { mode ^= 1; }
    void set_input() { input ^= 1; }
    void settings() const;
    void change_regim(Remote& r) const;
};

class Remote
{
    friend class Tv;
    enum {Normal, Interactive};
private:
    int mode;
    int regim;
public:
    Remote(int m = Tv::TV, int reg = Normal) : mode(m), regim(reg)  { }
    bool volup(Tv& t) { return t.volup(); }
    bool voldown(Tv & t) { return t.voldown(); }
    void onoff(Tv& t) { t.onoff(); }
    void chanup(Tv& t) { t.chanup(); }
    void chandown(Tv& t) { t.chandown(); }
    void set_chan(Tv& t, int c) { t.channel = (c <= t.maxchannel && c >= 1)? c: t.channel; }
    void set_mode(Tv& t) { t.set_mode(); }
    void set_input(Tv& t) { t.set_input(); }
    void show_regim() const;
};

inline void Tv::settings() const
{
    if (state != On)
        return;
    std::cout << "State: " << state << std::endl;
    std::cout << "Volume: " << volume << std::endl;
    std::cout << "Maxchannel: " << maxchannel << std::endl;
    std::cout << "Current channel: " << channel << std::endl;
    std::cout << "Mode: " << mode << std::endl;
    std::cout << "Input: " << input << std::endl;
}

inline void Remote::show_regim() const
{
    std::cout << "Regime: " << regim << std::endl;
}

inline void Tv::change_regim(Remote& r) const
{
    if (state == On) r.regim ^= 1;
}

}

#endif
