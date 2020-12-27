#ifndef __node_tag_h
#define __node_tag_h

#include "node.h"
#include "../tag/tag.h"

namespace iml
{
    class node_tag : public node
    {
    private:
        tag* current_tag;
        std::list<node*> children;
    public:
        // Constructor and destructor
        node_tag(tag*, std::list<node*>);
        ~node_tag();

        void visualize(std::ostream&) const;
        std::list<double> evaluate() const;
    };
}

#endif