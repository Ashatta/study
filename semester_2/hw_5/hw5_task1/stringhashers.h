#include "hasher.h"
#include <string>

class StringHasher1 : public Hasher<std::string>
{
public:
    /** Simple hash function for strings: multiplies first
     *  and last characters and adds string length
     */
    int hash(std::string const &str);
};

class StringHasher2 : public Hasher<std::string>
{
public:
    /// Polynomial hash function for strings
    int hash(std::string const &str);
};

