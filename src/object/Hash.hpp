#ifndef HASH_HPP
#define HASH_HPP

#include <map>
#include <memory>

#include "HashKey.hpp"
#include "HashPair.hpp"
#include "Object.hpp"

using namespace std;
using namespace mirror;
using namespace object;

namespace mirror {
class Hash : public Object {
   public:
    unique_ptr<map<HashKey, shared_ptr<HashPair>>> m_pairs;

    Hash(unique_ptr<map<HashKey, shared_ptr<HashPair>>> p)
        : m_pairs(std::move(p)) {
        auto it = m_pairs->begin();
        (void)it;
    };

   public:
    OBJECT_TYPE type() { return OBJECT_TYPE::HASH_OBJ; };
    string Inspect() {
        string ret = "";
        ret += "{";

        auto& pairs = *m_pairs;
        auto it = pairs.begin();
        while (it != pairs.end()) {
            auto hash_pair = it->second;
            auto key = (*hash_pair).m_key;
            auto value = (*hash_pair).m_value;
            ret += key->Inspect() + ":" + value->Inspect();
            it++;
        }

        ret += "}";

        return ret;
    };
};
}  // namespace mirror
#endif /* HASH_HPP */
