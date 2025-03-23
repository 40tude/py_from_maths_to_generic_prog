#include <algorithm> // for std::fill
#include <iostream>
#include <vector>

template <typename I, typename N> void mark_sieve(I first, I last, N factor) {
  *first = false;
  while (last - first > factor) {
    first = first + factor;
    *first = false;
  }
}

template <typename I, typename N> void sift0(I first, N n) {
  std::fill(first, first + n, true);
  N i(0);
  N index_square(3);
  while (index_square < n) {
    // invariant: index_square = 2*i^2 + 6*i + 3
    if (first[i]) {
      mark_sieve(first + index_square, first + n, i + i + 3);
    }
    ++i;
    index_square = 2 * i * (i + 3) + 3;
  }
}

int main() {
  int n = 20;
  std::vector<bool> is_prime(n);

  sift0(begin(is_prime), n);

  for (int i = 0; i < n; ++i) {
    if (is_prime[i]) {
      std::cout << 2 * i + 3 << " ";
    }
  }
  std::cout << std::endl;
}