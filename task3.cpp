//-------------------------------------------------------------------------------------------------
// There is a list:
// struct List {
//   struct List* next;
//   SomeDataType payload;
// }
// Write a function that removes every fifth (5) element from this list.
//-------------------------------------------------------------------------------------------------

#include <iostream>

//-------------------------------------------------------------------------------------------------

typedef int SomeDataType;

//-------------------------------------------------------------------------------------------------

//! 
//! @brief Struct of custom list
//! 
struct List
{
  List() {
    next = nullptr;
    payload = 0;
  }

  List(List* next_element) {
    next = next_element;
    payload = 0;
  }

  List(List* next_element, SomeDataType data) {
    next = next_element;
    payload = data;
  }

  struct List* next;
  SomeDataType payload;
};
//-------------------------------------------------------------------------------------------------

//! 
//! @brief Deleting every n'th element in list.
//! 
//! @param[in] head Head-element of list.
//! @param[in] n n'th element. Must be more or equal 2.
//! @return int Status of deleting. 0 - success, 1 - incorrect input arg n.
int deleteEveryNthElement(List* head, unsigned n)
{
  List* currentNode = head;
  List* prevNode = nullptr;
  
  if (n < 2) // if n less than 2, this function make no sense.
    return 1;

  int counter = 1;
  while (currentNode != nullptr)
  {
    if (counter % n == 0 && counter != 0)
    {
      prevNode->next = currentNode->next;
      delete currentNode;
      currentNode = prevNode;
      counter = 0;
    }
    else
    {
      prevNode = currentNode;
      currentNode = currentNode->next;
      ++counter;
    }
  }

  return 0;
}
//-------------------------------------------------------------------------------------------------

//! 
//! @brief Printing list in cout.
//! 
//! @param[in] node Start node for printing.
void printList(List *node) 
{
  List *current_node = node;
  int idx = 0;
  while (current_node != nullptr)
  {
    std::cout << "idx: " << idx << "\t payload: " << current_node->payload << std::endl;
    current_node = current_node->next;
    ++idx;
  }
  std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
  // Test values
  List* tail   = new List(nullptr, 17);
  List* node16 = new List(tail,    16);
  List* node15 = new List(node16,  15);
  List* node14 = new List(node15,  14);
  List* node13 = new List(node14,  13);
  List* node12 = new List(node13,  12);
  List* node11 = new List(node12,  11);
  List* node10 = new List(node11,  10);
  List* node9  = new List(node10,  9);
  List* node8  = new List(node9,   8);
  List* node7  = new List(node8,   7);
  List* node6  = new List(node7,   6);
  List* node5  = new List(node6,   5);
  List* node4  = new List(node5,   4);
  List* node3  = new List(node4,   3);
  List* node2  = new List(node3,   2);
  List* head   = new List(node2,   1);

  //
  printList(head);
  deleteEveryNthElement(head, 5);
  printList(head);

  return 0;
}
//-------------------------------------------------------------------------------------------------