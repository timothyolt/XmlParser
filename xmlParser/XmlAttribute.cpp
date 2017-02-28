// Copyright 2017 Timothy Oltjenbruns.

#include <assert.h>
#include "XmlAttribute.hpp"

XmlAttribute::XmlAttribute() : key(""), value("") { }

XmlAttribute::XmlAttribute(const std::string &key, const std::string &value) : key(key), value(value) {
  assert(!key.empty());
}

const std::string &XmlAttribute::getKey() const {
  return key;
}

void XmlAttribute::setKey(const std::string &key) {
  assert(!key.empty());
  XmlAttribute::key = key;
}

const std::string &XmlAttribute::getValue() const {
  return value;
}

void XmlAttribute::setValue(const std::string &value) {
  XmlAttribute::value = value;
}

bool XmlAttribute::operator==(const XmlAttribute &rhs) const {
  return key == rhs.key &&
      value == rhs.value;
}

bool XmlAttribute::operator!=(const XmlAttribute &rhs) const {
  return !(rhs == *this);
}
