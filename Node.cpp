#include "Node.h"

#include "utility"
#include "algorithm"
#include "iostream"

Node::Node(std::string element, bool isElement, bool canHaveChildren) {
    this->element = std::move(element);
    this->isElement = isElement;
    this->canHaveChildren = canHaveChildren;
}

Node::Node(std::string element) {
    this->element = std::move(element);
    this->isElement = true;
    this->canHaveChildren = true;
}

Node *Node::getChild(int index) {
    return this->childrenAsList[index];
}

int Node::getIndexInParent() {
    if (this->root == this) return 0;

    auto iterator = std::find(this->parent->childrenAsList.begin(), this->parent->childrenAsList.end(), this);

    if (iterator != this->parent->childrenAsList.end())
        return iterator - this->parent->childrenAsList.begin();
    else
        exit(1);
}

void Node::addChild(Node* node) {
    if (!this->canHaveChildren)
        exit(1);

    node->parent = this;
    node->root = this->root;
    this->childrenAsList.push_back(node);
}

std::string Node::getHierarchyFromRoot(const std::string &rootName) {
    std::string result;

    result += "--- " + rootName + " ---\n";
    for (Node* child : this->childrenAsList)
        result += child->hierarchyAsString(1);
    return result;
}

std::string Node::hierarchyAsString(int level) {
    std::string result;
    for (int i = 0; i < level; i++) result += "| ";
    result += this->element + "\n";
    for (Node* child : this->childrenAsList)
        result += child->hierarchyAsString(level + 1);
    return result;
}

std::string Node::fullPageHTMLAsString() {
    std::string result;
    result += "<!DOCTYPE html>\n<html lang=\"en\">\n    <head>\n        <meta charset=\"utf-8\"/>\n    </head>\n    <body>\n";
    for (Node* child : this->childrenAsList)
        result += child->htmlAsString(2);
    result += "    </body>\n</html>";
    return result;
}

std::string Node::htmlAsString(int level) {
    std::string result;
    for (int i = 0; i < level; i++)
        result += "    ";
    if (!this->isElement)
        return result + this->element + "\n";

    if (!this->canHaveChildren)
        return result + '<' + this->element + "/>\n";

    result += '<' + this->element + ">\n";
    for (Node* child : this->childrenAsList)
        result += child->htmlAsString(level + 1);
    for (int i = 0; i < level; i++)
        result += "    ";
    result += "</" + this->element + ">\n";
    return result;
}



