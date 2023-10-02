#ifndef WEBNODE_NODE_H
#define WEBNODE_NODE_H

#include <string>
#include <vector>
#include <unordered_map>

struct Node {
public:
    explicit Node(std::string element, bool isElement, bool canHaveChildren);
    explicit Node(std::string element);

    Node* parent = nullptr;
    Node* root = this;
    std::string element = "text";
    bool isElement = false;
    bool canHaveChildren = false;

    Node* getChild(int index);
    int getIndexInParent();

    void addChild(Node* node);

    std::string getHierarchyFromRoot(const std::string& rootName);
    std::string fullPageHTMLAsString();
private:

    std::vector<Node*> childrenAsList = {};

    std::string hierarchyAsString(int level);
    std::string htmlAsString(int level);
};



#endif //WEBNODE_NODE_H
