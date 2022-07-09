#include <iostream>
#include <string>

class exam_list {

  private:

  class exam_list_node {
    public:
    const char *data;
    exam_list_node *next;
    exam_list_node *previous;
    inline exam_list_node(const char *d, exam_list_node *n, exam_list_node *p) :
      data(d), next(n), previous(p)
    {
      if (next) {
        next->previous = this;
      }
      if (previous) {
        previous->next = this;
      }
    }
  };
  exam_list_node *head;
  exam_list_node *tail;
  public:
  exam_list() : head(0), tail(0) {}
  exam_list(const exam_list &el);
//   ~exam_list() { clear(); }
//   void clear();
  void insert_tail(const char *d)
  {
      // difference here
      exam_list_node *new_node;
      new_node->data = d;

      if (head->next == NULL) {
          new_node->previous = head;
          new_node->next = tail;

          head->next = new_node;
          tail->previous = new_node;
          return;
      }

      exam_list_node *end = head;
      while(end->next != NULL) {
          end = end->next;
      }

      end->previous->next = new_node;
      end->previous = new_node;
      new_node->next = end;
  }

  // diference here
  std::ostream &print(std::ostream &o)
  {
      std::string s = "";
      exam_list_node *next = head;

      while (next->next != NULL) {
        //   o << next->data << "," << std::endl;
        s += next->data;
        s += ",\n";
        //   std::cout << &o;
          next = next->next;
      }

    //   o << next->data << std::endl;
    s += next->data;
    s += ",\n";
    //   std::cout << &o;
    return o << s;
  }
};

std::ostream& operator<<(std::ostream& stream, exam_list& el) {return el.print(stream);};

int main() 
{
    exam_list el = exam_list();

    el.insert_tail("lol\n");

    std::cout << el;

    return 0;
}