#include "../inc/Span.hpp"

void displaySpan(Span &sp) {
    try {
      std::cout << "Calculating the shortest span ...\n"
                << sp.shortestSpan() << std::endl;
      std::cout << "Calculating the longest span ...\n"
                << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
  
  void sampleTest() {
    std::cout << "=== Sample Test ===" << std::endl;
  
    Span sp = Span(5);
  
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
  
    try {
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
  
    } catch (const std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
  
  void edgeCaseTest() {
    std::cout << "=== Edge Case Test ===" << std::endl;
  
    std::cout << "> When exceeding the capacity limit" << std::endl;
    try {
      Span sp = Span(1);
      sp.addNumber(7);
      sp.addNumber(13); // error
      displaySpan(sp);
    } catch (const std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  
    std::cout << "\n> When without enough numbers to calculate span" << std::endl;
    try {
      Span sp = Span(7);
      sp.addNumber(17);
      displaySpan(sp);
    } catch (const std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  
    std::cout << "\n> When receiving INT_MAX and INT_MIN" << std::endl;
    try {
      Span sp = Span(7);
      sp.addNumber(std::numeric_limits<int>::min());
      sp.addNumber(std::numeric_limits<int>::max());
      sp.addNumber(std::numeric_limits<int>::max());
      displaySpan(sp);
    } catch (const std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
  
  int main() {
    sampleTest();
    edgeCaseTest();
    return 0;
  }