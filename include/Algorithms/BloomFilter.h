#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <vector>
#include <functional>

template <typename T>
class BloomFilter {
private:
    std::vector<bool> m_bits;
    std::size_t m_size;
    std::size_t m_numHashes;

    std::size_t computeHash(const T& item, std::size_t seed) const;

public:
    BloomFilter(std::size_t size, std::size_t numHashes);

    void add(const T& item);
    bool mightContain(const T& item) const;
};

#endif // BLOOMFILTER_H

