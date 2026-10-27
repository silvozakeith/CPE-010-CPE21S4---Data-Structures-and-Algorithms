#include <iostream>
#include "binaryTree.h"

main(){

    BinaryTree<char>* root = new BinaryTree<char>('A');
    root->insertChildLeft('B');
    root-> insertChildRight('C');

    root->getLeftChild()->insertChildLeft('D');
    root->getLeftChild() -> insertChildRight('E');
    root -> getRightChild()->insertChildRight('F');

    
std::cout<<"The root: " << root->getRootVal()<< std::endl;
std::cout<<"The left child of root a is: " << root->getLeftChild()->getRootVal() <<std::endl;
std::cout<<"The left child of the left child root a is: " << root->getLeftChild()->getLeftChild()->getRootVal() <<std::endl;
std::cout<<"The right child of the left child root a is: " << root->getLeftChild()->getRightChild()->getRootVal() <<std::endl;
std::cout<<"The right child of root a is: " << root->getRightChild()->getRootVal() <<std::endl;
std::cout<<"The left child of the right child root a is: " << root->getRightChild()->getRightChild()->getRootVal() <<std::endl;

root -> getRightChild()->setRootVal('V');
std::cout<<"The NEW right child of root A  is: " << root->getRightChild()->getRootVal() <<std::endl;

    return 0;
}