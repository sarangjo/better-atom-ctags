#include <iostream>
#include <cstring>
#include <cstdlib>

#include "readtags.h"

int main(int argc, char **argv) {
  if (argc < 3) {
    std::cout << "./a.exe [tagfile] [symbol]" << std::endl;
    exit(69);
  }

  tagFileInfo info;
  std::memset(&info, 0, sizeof(tagFileInfo));

  tagFile *file;
  file = tagsOpen(argv[1], &info);
  if (file == NULL) {
    std::cout << "Unable to open file" << std::endl;
  }

  tagEntry entry;
  std::memset(&entry, 0, sizeof(tagEntry));
  tagResult r = tagsFind(
    file,
    &entry,
    argv[2],
    TAG_PARTIALMATCH
  );

  if (r == TagFailure) {
    std::cout << "Failed to find tag" << std::endl;
    exit(69);
  }

  std::cout << "Name: " << entry.name << std::endl;
  std::cout << "File: " << entry.file << std::endl;
  std::cout << "Pattern: " << entry.address.pattern << std::endl;
  std::cout << "Line Number: " << entry.address.lineNumber << std::endl;
}
