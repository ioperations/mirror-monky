#ifndef HASHABLE_HPP
#define HASHABLE_HPP

#include <memory>

#include "HashKey.hpp"
namespace mirror {
class Hashable {
   public:
    virtual HashKey hash_key() = 0;
};
}  // namespace mirror
#endif /* HASHABLE_HPP */
