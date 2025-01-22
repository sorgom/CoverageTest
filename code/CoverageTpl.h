#ifndef COVERAGE_TPL_H
#define COVERAGE_TPL_H

template <bool B, int I>
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
    static const int Val = IsNeg ? I : -I;
};

#define MAX(V1, V2) (((V1) > (V2)) ? (V1) : (V2))

template <typename T1, typename T2>
class ByteBufferHeap
{
public:
    inline ByteBufferHeap():
        mBytes(new unsigned char[MAX(sizeof(T1), sizeof(T2))])
    {}
    inline ~ByteBufferHeap() { delete[] mBytes; }
private:
    unsigned char* mBytes;
};

template <typename T1, typename T2>
class ByteBufferStack
{
public:
    inline ByteBufferStack() = default;
private:
    unsigned char mBytes[MAX(sizeof(T1), sizeof(T2))];
};

#endif // _H
