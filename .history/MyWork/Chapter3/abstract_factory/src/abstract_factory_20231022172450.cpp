#include <iostream>
#include <memory>

// Abstract Product A

// Concrete Product A1
class WindowsButton : public Button {
public:
  void click() override { std::cout << "Windows Button clicked.\n"; }
};

// Concrete Product A2
class LinuxButton : public Button {
public:
  void click() override { std::cout << "Linux Button clicked.\n"; }
};

// Abstract Product B
class CheckBox {
public:
  virtual void check() = 0;
};

// Concrete Product B1
class WindowsCheckBox : public CheckBox {
public:
  void check() override { std::cout << "Windows CheckBox checked.\n"; }
};

// Concrete Product B2
class LinuxCheckBox : public CheckBox {
public:
  void check() override { std::cout << "Linux CheckBox checked.\n"; }
};

// Abstract Factory
class GUIFactory {
public:
  virtual std::unique_ptr<Button> createButton() = 0;
  virtual std::unique_ptr<CheckBox> createCheckBox() = 0;
};

// Concrete Factory 1
class WindowsFactory : public GUIFactory {
public:
  std::unique_ptr<Button> createButton() override {
    return std::make_unique<WindowsButton>();
  }

  std::unique_ptr<CheckBox> createCheckBox() override {
    return std::make_unique<WindowsCheckBox>();
  }
};

// Concrete Factory 2
class LinuxFactory : public GUIFactory {
public:
  std::unique_ptr<Button> createButton() override {
    return std::make_unique<LinuxButton>();
  }

  std::unique_ptr<CheckBox> createCheckBox() override {
    return std::make_unique<LinuxCheckBox>();
  }
};

int main() {
  std::unique_ptr<GUIFactory> factory;

  // You can decide the factory type at runtime
  // For this example, I'll use WindowsFactory
  factory = std::make_unique<WindowsFactory>();

  // Create button and checkbox using the factory
  auto button = factory->createButton();
  auto checkBox = factory->createCheckBox();

  // Perform operations
  button->click();
  checkBox->check();

  return 0;
}
