#include <iostream>
#include "Node.h"

int main() {
    Node root("body");
    Node child0("img", true, false);
    Node child1("h3");
    Node child1Child0("Caption", false, false);
    Node child2("p");
    Node child2Child0("Sub-Caption", false, false);
    root.addChild(&child0);
    root.addChild(&child1);
    root.addChild(&child2);

    child1.addChild(&child1Child0);
    child2.addChild(&child2Child0);
    std::cout << root.getHierarchyFromRoot("body");
    std::cout << root.fullPageHTMLAsString();
    return 0;
}
