#include "../../include/Algorithms/BloomFilter.h"

template <typename T>
std::size_t BloomFilter<T>::computeHash(const T& item, std::size_t seed) const {
    std::hash<T> hasher;
    return hasher(item) ^ (seed * 0x9e3779b97f4a7c15ULL);
}

template <typename T>
BloomFilter<T>::BloomFilter(std::size_t size, std::size_t numHashes)
        : m_bits(size, false), m_size(size), m_numHashes(numHashes) {}

template <typename T>
void BloomFilter<T>::add(const T& item) {
    for (std::size_t i = 0; i < m_numHashes; ++i) {
        std::size_t idx = computeHash(item, i) % m_size;
        m_bits[idx] = true;
    }
}

template <typename T>
bool BloomFilter<T>::mightContain(const T& item) const {
    for (std::size_t i = 0; i < m_numHashes; ++i) {
        std::size_t idx = computeHash(item, i) % m_size;
        if (!m_bits[idx]) return false;
    }
    return true;
}

