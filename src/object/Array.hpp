#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <memory>

#include "Object.hpp"

using namespace std;
using namespace mirror;
using namespace object;

namespace mirror {
class Array : public Object {
   public:
    vector<shared_ptr<Object>> m_elements;

    Array(vector<shared_ptr<Object>> v) : m_elements(v){};

   public:
    OBJECT_TYPE type() { return OBJECT_TYPE::ARRAY_OBJ; };
    string Inspect() {
        string ret = "";

        ret += "[";
        for (int i = 0; i < m_elements.size(); i++) {
            ret += m_elements[i]->Inspect();

            if (i < m_elements.size() - 1) {
                ret += ", ";
            }
        }
        ret += "]";

        return ret;
    };
};

}  // namespace mirror
#endif /* ARRAY_HPP */
