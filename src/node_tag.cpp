#include "../include/node/node_tag.h"
#include "../include/tag/tag_config.h"

namespace iml
{
    node_tag::node_tag(tag* tag, std::list<node*> _children) : current_tag(tag), children(_children)
    {}

    node_tag::~node_tag()
    {
        for (node* child : children)
        {
            delete child;
        }
    }

    void node_tag::visualize(std::ostream& out) const
    {
        out << (long)this << "[label=\"" << "Tag: " << current_tag->as_string() << "\"];\n";
        for (node* child : children)
        {
            out << (long)this << "->" << (long)child << ";\n";
            child->visualize(out);
        }
    }

    std::list<double> node_tag::evaluate() const
    {
        std::list<double> values;
        for (node* child : children)
        {
            for (double value : child->evaluate())
            {
                values.push_back(value);
            }
        }
        return tag_config::apply(values, current_tag);
    }
}