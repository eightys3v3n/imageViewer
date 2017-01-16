#ifndef FILESYSTEM_
#define FILESYSTEM_

#define FAILED_TO_OPEN_DIRECTORY 1

#include <string>
#include <vector>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

typedef std::string string;

bool fileExists( string path );
string filePath(string input);
std::vector<string> directoryContents(string path);
std::vector<string> listImages(string path);

#endif // FILESYSTEM_

// written by terrence plunkett (eightys3v3n)