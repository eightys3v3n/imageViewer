#include <string>
#include <sys/stat.h>

bool fileExists( std::string path )
{
  struct stat buffer;
  return ( stat( path.c_str(), &buffer) == 0 );
}

// written by terrence plunkett (eightys3v3n)