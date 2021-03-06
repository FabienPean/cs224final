// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.1 (2010/04/14)

//----------------------------------------------------------------------------
template <int N>
Rational<N>::Rational ()
    :
    mNumer(0),
    mDenom(1)
{
    // Default construction produces the rational number zero (0/1).
}
//----------------------------------------------------------------------------
template <int N>
Rational<N>::Rational (const Rational& rat)
    :
    mNumer(rat.mNumer),
    mDenom(rat.mDenom)
{
}
//----------------------------------------------------------------------------
template <int N>
Rational<N>::Rational (const Integer<N>& numer)
    :
    mNumer(numer),
    mDenom(1)
{
}
//----------------------------------------------------------------------------
template <int N>
Rational<N>::Rational (const Integer<N>& numer, const Integer<N>& denom)
    :
    mNumer(numer),
    mDenom(denom)
{
}
//----------------------------------------------------------------------------
template <int N>
Rational<N>::Rational (int numer)
    :
    mNumer(numer),
    mDenom(1)
{
}
//----------------------------------------------------------------------------
template <int N>
Rational<N>::Rational (int numer, int denom)
    :
    mNumer(numer),
    mDenom(denom)
{
}
//----------------------------------------------------------------------------
template <int N>
inline Integer<N>& Rational<N>::Numer ()
{
    return mNumer;
}
//----------------------------------------------------------------------------
template <int N>
inline Integer<N>& Rational<N>::Denom ()
{
    return mDenom;
}
//----------------------------------------------------------------------------
template <int N>
inline const Integer<N>& Rational<N>::Numer () const
{
    return mNumer;
}
//----------------------------------------------------------------------------
template <int N>
inline const Integer<N>& Rational<N>::Denom () const
{
    return mDenom;
}
//----------------------------------------------------------------------------
template <int N>
Rational<N>& Rational<N>::operator= (const Rational& rat)
{
    mNumer = rat.mNumer;
    mDenom = rat.mDenom;
    return *this;
}
//----------------------------------------------------------------------------
template <int N>
bool Rational<N>::operator== (const Rational& rat) const
{
    return mNumer*rat.mDenom == mDenom*rat.mNumer;
}
//----------------------------------------------------------------------------
template <int N>
bool Rational<N>::operator!= (const Rational& rat) const
{
    return mNumer*rat.mDenom != mDenom*rat.mNumer;
}
//----------------------------------------------------------------------------
template <int N>
bool Rational<N>::operator<= (const Rational& rat) const
{
    Integer<N> prod0 = mNumer*rat.mDenom;
    Integer<N> prod1 = mDenom*rat.mNumer;
    if (mDenom > 0)
    {
        return (rat.mDenom > 0 ? prod0 <= prod1 : prod0 >= prod1);
    }
    else
    {
        return (rat.mDenom > 0 ? prod0 >= prod1 : prod0 <= prod1);
    }
}
//----------------------------------------------------------------------------
template <int N>
bool Rational<N>::operator< (const Rational& rat) const
{
    Integer<N> prod0 = mNumer*rat.mDenom;
    Integer<N> prod1 = mDenom*rat.mNumer;
    if (mDenom > 0)
    {
        return (rat.mDenom > 0 ? prod0 < prod1 : prod0 > prod1);
    }
    else
    {
        return (rat.mDenom > 0 ? prod0 > prod1 : prod0 < prod1);
    }
}
//----------------------------------------------------------------------------
template <int N>
bool Rational<N>::operator>= (const Rational& rat) const
{
    Integer<N> prod0 = mNumer*rat.mDenom;
    Integer<N> prod1 = mDenom*rat.mNumer;
    if (mDenom > 0)
    {
        return (rat.mDenom > 0 ? prod0 >= prod1 : prod0 <= prod1);
    }
    else
    {
        return (rat.mDenom > 0 ? prod0 <= prod1 : prod0 >= prod1);
    }
}
//----------------------------------------------------------------------------
template <int N>
bool Rational<N>::operator> (const Rational& rat) const
{
    Integer<N> prod0 = mNumer*rat.mDenom;
    Integer<N> prod1 = mDenom*rat.mNumer;
    if (mDenom > 0)
    {
        return (rat.mDenom > 0 ? prod0 > prod1 : prod0 < prod1);
    }
    else
    {
        return (rat.mDenom > 0 ? prod0 < prod1 : prod0 > prod1);
    }
}
//----------------------------------------------------------------------------
template <int N>
Rational<N> Rational<N>::operator+ (const Rational& rat) const
{
    Rational sum;
    sum.mNumer = mNumer*rat.mDenom + mDenom*rat.mNumer;
    sum.mDenom = mDenom*rat.mDenom;
    sum.EliminatePowersOfTwo();
    return sum;
}
//----------------------------------------------------------------------------
template <int N>
Rational<N> Rational<N>::operator- (const Rational& rat) const
{
    Rational diff;
    diff.mNumer = mNumer*rat.mDenom - mDenom*rat.mNumer;
    diff.mDenom = mDenom*rat.mDenom;
    diff.EliminatePowersOfTwo();
    return diff;
}
//----------------------------------------------------------------------------
template <int N>
Rational<N> Rational<N>::operator* (const Rational& rat) const
{
    Rational prod;
    prod.mNumer = mNumer*rat.mNumer;
    prod.mDenom = mDenom*rat.mDenom;
    prod.EliminatePowersOfTwo();
    return prod;
}
//----------------------------------------------------------------------------
template <int N>
Rational<N> Rational<N>::operator/ (const Rational& rat) const
{
    Rational quot;
    quot.mNumer = mNumer*rat.mDenom;
    quot.mDenom = mDenom*rat.mNumer;
    quot.EliminatePowersOfTwo();
    return quot;
}
//----------------------------------------------------------------------------
template <int N>
Rational<N> Rational<N>::operator- () const
{
    Rational neg;
    neg.mNumer = -mNumer;
    neg.mDenom = mDenom;
    return neg;
}
//----------------------------------------------------------------------------
template <int N>
Rational<N> operator+ (const Integer<N>& ival, const Rational<N>& rat)
{
    Rational<N> sum;
    sum.Numer() = ival*rat.Denom() + rat.Numer();
    sum.Denom() = rat.Denom();
    return sum;
}
//----------------------------------------------------------------------------
template <int N>
Rational<N> operator- (const Integer<N>& ival, const Rational<N>& rat)
{
    Rational<N> diff;
    diff.Numer() = ival*rat.Denom() - rat.Numer();
    diff.Denom() = rat.Denom();
    return diff;
}
//----------------------------------------------------------------------------
template <int N>
Rational<N> operator* (const Integer<N>& ival, const Rational<N>& rat)
{
    Rational<N> prod;
    prod.Numer() = ival*rat.Numer();
    prod.Denom() = rat.Denom();
    return prod;
}
//----------------------------------------------------------------------------
template <int N>
Rational<N> operator/ (const Integer<N>& ival, const Rational<N>& rat)
{
    Rational<N> quot;
    quot.Numer() = rat.Denom()*ival;
    quot.Denom() = rat.Numer();
    return quot;
}
//----------------------------------------------------------------------------
template <int N>
Rational<N>& Rational<N>::operator+= (const Rational& rat)
{
    *this = *this + rat;
    EliminatePowersOfTwo();
    return *this;
}
//----------------------------------------------------------------------------
template <int N>
Rational<N>& Rational<N>::operator-= (const Rational& rat)
{
    *this = *this - rat;
    EliminatePowersOfTwo();
    return *this;
}
//----------------------------------------------------------------------------
template <int N>
Rational<N>& Rational<N>::operator*= (const Rational& rat)
{
    *this = (*this)*rat;
    EliminatePowersOfTwo();
    return *this;
}
//----------------------------------------------------------------------------
template <int N>
Rational<N>& Rational<N>::operator/= (const Rational& rat)
{
    *this = (*this)/rat;
    EliminatePowersOfTwo();
    return *this;
}
//----------------------------------------------------------------------------
template <int N>
Rational<N> Rational<N>::Abs () const
{
    return (*this >= 0 ? *this : -(*this));
}
//----------------------------------------------------------------------------
template <int N>
void Rational<N>::EliminatePowersOfTwo ()
{
    if ((mNumer.mBuffer[0] & 1) > 0
    ||  (mDenom.mBuffer[0] & 1) > 0)
    {
        // Neither term is divisible by 2 (quick out).
        return;
    }

    int block0 = mNumer.GetTrailingBlock();
    if (block0 == -1)
    {
        // Numerator is zero.
        mDenom = 1;
        return;
    }

    int block1 = mDenom.GetTrailingBlock();
    assertion(block1 >= 0, "Denominator should never be zero\n");
    int minBlock = (block0 < block1 ? block0 : block1);
    int bit0 = mNumer.GetTrailingBit(block0);
    int bit1 = mDenom.GetTrailingBit(block1);
    int minBit = (bit0 < bit1 ? bit0 : bit1);
    int shift = 16*minBlock + minBit;
    mNumer >>= shift;
    mDenom >>= shift;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Conversions between rational numbers and 'float'.
//----------------------------------------------------------------------------
template <int N>
Rational<N>::Rational (float value)
{
    mDenom = Integer<N>(1);
    if (value == 0.0f)
    {
        // Exponent is zero, mantissa is zero, number is +0 (sign bit = 0)
        // or -0 (sign bit = 1).  Return rational value for +0.
        mNumer = Integer<N>(0);
        return;
    }

    unsigned int bits = *(unsigned int*)&value;
    unsigned int sign = (0x80000000 & bits);
    int exponent = ((0x7F800000 & bits) >> 23);
    int mantissa = (0x007FFFFF & bits);

    if (1 <= exponent && exponent <= 254)
    {
        // The number is normal:  (-1)^s * 2^{e-127} * 1.m
        mNumer = Integer<N>((1 << 23) + mantissa);
        int power = exponent - 150;
        if (power > 0)
        {
            mNumer <<= power;
        }
        else if (power < 0)
        {
            mDenom <<= -power;
        }
    }
    else if (exponent == 0)
    {
        // The number is subnormal (denormal):  (-1)^s * 2^{-126} * 0.m
        mNumer = Integer<N>(mantissa);
        mDenom <<= 149;
    }
    else  // exponent == 255
    {
#ifdef WM5_ASSERT_ON_RATIONAL_CONVERT_NAN
        if (mantissa > 0)
        {
            if (mantissa & 0x00400000)
            {
                assertion(false, "Input is quiet NaN.\n");
            }
            else
            {
                // Payload is (mantissa & 0x003FFFFF).
                assertion(false, "Input is signaling NaN.\n");
            }
        }
        else
        {
            assertion(false, "Input is an infinity.\n");
        }
#endif
        // The number is infinite, a quiet NaN, or a signaling NaN.  In all
        // cases, represent them as max_normal_float.
        mNumer = Integer<N>((1 << 24) - 1);
        mNumer <<= 104;
    }

    if (sign)
    {
        mNumer = -mNumer;
    }
}
//----------------------------------------------------------------------------
template <int N>
void Rational<N>::ConvertTo (float& value) const
{
    if (mNumer == 0)
    {
        value = 0.0f;
        return;
    }

    // Compute the sign of the result and the absolute values of the numerator
    // and denominator.
    int sign0 = mNumer.GetSign();
    int sign1 = mDenom.GetSign();
    int sign = sign0*sign1;
    Integer<N> absNumer = sign0*mNumer;
    Integer<N> absDenom = sign1*mDenom;

    // Get the leading bits of of the numerator and denominator.
    int nbit = absNumer.GetLeadingBit();
    int dbit = absDenom.GetLeadingBit();

    // The rational is for the form N/D = 2^{nbit-dbit}*(1+n)/(1+d), where
    // n and d are in [0,1).  Convert to N'/D' = (1+n)/(1+d).
    int power = nbit - dbit;
    if (power > 0)
    {
        absDenom <<= power;
    }
    else if (power < 0)
    {
        absNumer <<= -power;
    }

    // To represent (1+n)/(1+d) = 1+m, where m in [0,1), we need n >= d.  If
    // n < d, convert to N"/D" = (2*(1+n))/(1+d) = 1+m, which is in [0,1).
    if (absNumer < absDenom)
    {
        absNumer <<= 1;
        --power;
    }

    int result;
    if (power <= 127)
    {
        if (power >= -149)
        {
            int exponent, bit, shift;
            if (power >= -126)
            {
                // normal_float, 1.c * 2^{e - 127}
                exponent = power + 127;
                bit = 1;
                shift = 0;
            }
            else
            {
                // subnormal_float, 0.c * 2^{-126}
                exponent = 0;
                bit = 0;
                absDenom <<= 1;
                shift = -(power + 127);
            }

            int mantissa = 0;
            Integer<N> one(1);
            for (int mask = ((1 << 22) >> shift); mask > 0; mask >>= 1)
            {
                if (bit == 1)
                {
                    absNumer -= absDenom;
                }
                absNumer <<= 1;

                if (absNumer >= absDenom)
                {
                    bit = 1;
                    mantissa |= mask;
                }
                else
                {
                    bit = 0;
                }
            }

            result = (exponent << 23) | mantissa;
        }
        else
        {
            // Smaller than min_subnormal_float, truncate to zero.
            result = 0;
        }
    }
    else
    {
        // Larger than max_normal_float, truncate to this value.
        result = 0x7F7FFFFF;
    }

    if (sign < 0)
    {
        result |= 0x80000000;
    }
    value = *(float*)&result;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Conversions between rational numbers and 'double'.
//----------------------------------------------------------------------------
template <int N>
Rational<N>::Rational (double value)
{
    mDenom = Integer<N>(1);
    if (value == 0.0)
    {
        // Exponent is zero, mantissa is zero, number is +0 (sign bit = 0)
        // or -0 (sign bit = 1).  Return rational value for +0.
        mNumer = Integer<N>(0);
        return;
    }

    uint64_t bits = *(uint64_t*)&value;
    uint64_t sign = (0x8000000000000000ULL & bits);
    int exponent = (int)((0x7FFF000000000000LL & bits) >> 52);
    int64_t mantissa = (0x000FFFFFFFFFFFFFLL & bits);
    int mlo24 = (int)(mantissa & 0x0000000000FFFFFFLL);
    int mhi28 = (int)((mantissa & 0x000FFFFFFF000000LL) >> 24);

    if (1 <= exponent && exponent <= 2046)
    {
        // The number is normal:  (-1)^s * 2^{e-1023} * 1.m
        Integer<N> numer0(1);
        numer0 <<= 52;  // = (1 << 52);
        Integer<N> numer1(mhi28);
        numer1 <<= 24;
        numer1 += Integer<N>(mlo24);
        mNumer = numer0 + numer1;  // (1LL < 52) + mantissa
        int power = exponent - 1075;
        if (power > 0)
        {
            mNumer <<= power;
        }
        else if (power < 0)
        {
            mDenom <<= -power;
        }
    }
    else if (exponent == 0)
    {
        // The number is subnormal (denormal):  (-1)^s * 2^{-1022} * 0.m
        mNumer = Integer<N>(mhi28);
        mNumer <<= 24;
        mNumer += Integer<N>(mlo24);  // mantissa
        mDenom <<= 1074;
    }
    else  // exponent == 1023
    {
#ifdef WM5_ASSERT_ON_RATIONAL_CONVERT_NAN
        if (mantissa > 0)
        {
            if (mantissa & 0x0008000000000000LL)
            {
                assertion(false, "Input is quiet NaN.\n");
            }
            else
            {
                // Payload is (mantissa & 0x0007FFFFFFFFFFFFLL).
                assertion(false, "Input is signaling NaN.\n");
            }
        }
        else
        {
            assertion(false, "Input is an infinity.\n");
        }
#endif
        // The number is infinite, a quiet NaN, or a signaling NaN.  In all
        // cases, represent them as max_normal_double.
        mNumer = Integer<N>(1);
        mNumer <<= 53;
        mNumer -= Integer<N>(1);  // (1LL << 53) - 1L
        mNumer <<= 971;
    }

    if (sign)
    {
        mNumer = -mNumer;
    }
}
//----------------------------------------------------------------------------
template <int N>
void Rational<N>::ConvertTo (double& value) const
{
    if (mNumer == 0)
    {
        value = 0.0;
        return;
    }

    // Compute the sign of the result and the absolute values of the numerator
    // and denominator.
    int sign0 = mNumer.GetSign();
    int sign1 = mDenom.GetSign();
    int sign = sign0*sign1;
    Integer<N> absNumer = sign0*mNumer;
    Integer<N> absDenom = sign1*mDenom;

    // Get the leading bits of of the numerator and denominator.
    int nbit = absNumer.GetLeadingBit();
    int dbit = absDenom.GetLeadingBit();

    // The rational is for the form N/D = 2^{nbit-dbit}*(1+n)/(1+d), where
    // n and d are in [0,1).  Convert to N'/D' = (1+n)/(1+d).
    int power = nbit - dbit;
    if (power > 0)
    {
        absDenom <<= power;
    }
    else if (power < 0)
    {
        absNumer <<= -power;
    }

    // To represent (1+n)/(1+d) = 1+m, where m in [0,1), we need n >= d.  If
    // n < d, convert to N"/D" = (2*(1+n))/(1+d) = 1+m, which is in [0,1).
    if (absNumer < absDenom)
    {
        absNumer <<= 1;
        --power;
    }

    int64_t result;
    if (power <= 1023)
    {
        if (power >= -1074)
        {
            int64_t exponent;
            int bit, shift;
            if (power >= -1022)
            {
                // normal_float, 1.c * 2^{e - 1023}
                exponent = power + 1023;
                bit = 1;
                shift = 0;
            }
            else
            {
                // subnormal_float, 0.c * 2^{-1022}
                exponent = 0;
                bit = 0;
                absDenom <<= 1;
                shift = -(power + 1023);
            }

            int64_t mantissa = 0;
            Integer<N> one(1);
            for (int64_t mask = ((1LL << 51) >> shift); mask > 0; mask >>= 1)
            {
                if (bit == 1)
                {
                    absNumer -= absDenom;
                }
                absNumer <<= 1;

                if (absNumer >= absDenom)
                {
                    bit = 1;
                    mantissa |= mask;
                }
                else
                {
                    bit = 0;
                }
            }

            result = (exponent << 52) | mantissa;
        }
        else
        {
            // Smaller than min_subnormal_float, truncate to zero.
            result = 0LL;
        }
    }
    else
    {
        // Larger than max_normal_float, truncate to this value.
        result = 0x7FEFFFFFFFFFFFFFLL;
    }

    if (sign < 0)
    {
        result |= 0x8000000000000000LL;
    }
    value = *(double*)&result;
}
//----------------------------------------------------------------------------
