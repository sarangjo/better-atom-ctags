#include <iostream>
#include <cstring>

#include "readtags.h"

int main(int argc, char **argv) {
  tagFileInfo info;
  std::memset(&info, 0, sizeof(tagFileInfo));

  tagFile *file;
  file = tagsOpen(argv[1], &info);
  if (file == NULL) {
    std::cout << "Unable to open file" << std::endl;
  }
}
