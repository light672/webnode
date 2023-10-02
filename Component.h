#ifndef WEBNODE_COMPONENT_H
#define WEBNODE_COMPONENT_H

#include <string>
#include <vector>
#include <unordered_map>

struct Component {
public:
    explicit Component(std::string element);

    std::string element = "text";

    Component* getParent();
    Component* getRoot();
    Component* getChild(int index);
    int getIndexInParent();

    void addChild(Component* component);

    void printHierarchy(const std::string& rootName);
private:
    Component* parent = nullptr;
    Component* root = this;

    std::vector<Component*> childrenAsList = {};

    std::string hierarchyAsString(int level);
};



#endif //WEBNODE_COMPONENT_H
