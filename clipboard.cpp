#include "clip.h"
#include <iostream>
#include <string>

extern "C" {
void send_to_clipboard(char *text) {
  clip::set_text(text);
  std::cout << "Text sent to clipboard: " << text << std::endl;
}
}
