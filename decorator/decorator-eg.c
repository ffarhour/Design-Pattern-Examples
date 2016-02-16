#include <iostream>
using namespace std;

class VisualComponent {
public:
  VisualComponent() {};
  
  virtual void draw () { cout << "(draw VisualComponent)";};
  
};


class decorator : public VisualComponent {

public:
  decorator(VisualComponent *it) : _component(it) {};
  
  virtual void draw  () { 
    cout << "(draw decorator) ";
    _component->draw();
  };
  
private:
  VisualComponent *_component; 
}  ;


class border: public decorator {
public:
  border(VisualComponent* it): decorator(it) {};
  virtual void draw() { cout << "border" << endl; 
  decorator::draw();
  };

};

class title: public decorator {
public:
  title(VisualComponent * it): decorator(it) {}; 
  virtual void draw() { cout << "title" << endl; 
  decorator::draw();
  };

};

class TextView: public VisualComponent {
public:
  TextView() {};
  virtual void draw() {cout << "draw base" << endl;};
};

int main () {

  TextView *b = new TextView();
  title *tb = new title(b);
  border *btb = new border(tb);
  btb->draw();
}
