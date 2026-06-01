namespace aubs::simd {

enum class SIMDLevel
{
    Scalar,
    SSE2,
    AVX2,
    AVX512,
    NEON
};

class SIMDDetector
{
public:

    static SIMDLevel detect();
};

}