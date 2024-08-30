#ifndef COVERAGETPL_H
#define COVERAGETPL_H

template <int I, bool B>
class CoverageTpl
{
public:
    CoverageTpl() = default;
    inline static bool isNeg() { return IsNeg or I < 0; }
    inline static int val() { return IsNeg ? Val : -Val; }
private:
    //  static const bool and
    static const bool IsNeg = B and I < 0;
    //  static const int ternary
    static const int Val = B ? I : -I;
};

#endif // _H