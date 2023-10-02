#include "Component.h"

#include <utility>
#include "algorithm"

#include "iostream"

Component::Component(std::string element) {
    this->element = std::move(element);
}

Component *Component::getParent() {
    return this->parent;
}

Component *Component::getRoot() {
    return this->root;
}

Component *Component::getChild(int index) {
    return this->childrenAsList[index];
}

int Component::getIndexInParent() {
    if (this->root == this) return 0;
    auto iterator = std::find(this->parent->childrenAsList.begin(), this->parent->childrenAsList.end(), this);
    if (iterator != this->parent->childrenAsList.end()) return iterator - this->parent->childrenAsList.begin();
    else exit(1);
}

void Component::addChild(Component* component) {
    component->parent = this;
    component->root = this->root;
    this->childrenAsList.push_back(component);
}

void Component::printHierarchy(const std::string& rootName) {
    std::cout << "--- " << rootName << " ---" << std::endl;
    if (this->childrenAsList.empty()) return;
    for (Component* child : this->childrenAsList) {
        std::cout << child->hierarchyAsString(1);
    }
}

std::string Component::hierarchyAsString(int level) {
    std::string result;
    for (int i = 0; i < level; i++) result += "| ";
    result += this->element + "\n";

    if (this->childrenAsList.empty()) return result;

    for (Component* child : this->childrenAsList) {
        result += child->hierarchyAsString(level + 1);
    }

    return result;
}