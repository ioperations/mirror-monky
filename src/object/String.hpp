#ifndef STRING_HPP
#define STRING_HPP

#include <memory>

#include "Hashable.hpp"
#include "Object.hpp"

using namespace mirror;
using namespace std;
using namespace object;

namespace mirror {
class String : public Object, public Hashable {
   public:
    string m_value;

    String(string value) : m_value(value){};

   public:
    OBJECT_TYPE type() override { return OBJECT_TYPE::STRING_OBJ; };
    string Inspect() override { return m_value; };

   public:
    HashKey hash_key() override {
        std::size_t h = std::hash<std::string>{}(m_value);
        HashKey hk(type(), h);
        return hk;
    };
};
}  // namespace mirror
#endif /* STRING_HPP */
