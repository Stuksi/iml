#ifndef __iml_tag_attribute_h
#define __iml_tag_attribute_h

#include "iml_tag.h"

class iml_tag_attribute : public iml_tag
{
protected:
    iml_attribute attribute;
public:
    iml_attribute get_attribute() const;

    virtual void set_attribute(iml_attribute) = 0;
    virtual dllist<double> eval() = 0;
};

#endif