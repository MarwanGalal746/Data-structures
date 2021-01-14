cmake_minimum_required(VERSION 3.17)
project(Data_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(Data_structures main.cpp BTree/BTree.cpp BTree/BTree.h suffixTrie/suffixTrie.cpp suffixTrie/suffixTrie.h suffixTrie/Node.cpp suffixTrie/Node.h suffixTrie/TrieNode.cpp suffixTrie/TrieNode.h suffixTrie/list.cpp suffixTrie/list.h BinaryTree/binaryTree.cpp BinaryTree/binaryTree.h BinaryTree/BST.cpp BinaryTree/BST.h BinaryTree/AVL.cpp BinaryTree/AVL.h)