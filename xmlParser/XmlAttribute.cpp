// Copyright 2017 Timothy Oltjenbruns.

#include "XmlAttribute.hpp"

XmlAttribute::XmlAttribute(const std::string &key, const std::string &value) : key(key), value(value) {}

const std::string &XmlAttribute::getKey() const {
  return key;
}

void XmlAttribute::setKey(const std::string &key) {
  XmlAttribute::key = key;
}

const std::string &XmlAttribute::getValue() const {
  return value;
}

void XmlAttribute::setValue(const std::string &value) {
  XmlAttribute::value = value;
}
