#include "filesystem.hpp"

bool fileExists( std::string path )
{
  struct stat buffer;
  return ( stat( path.c_str(), &buffer) == 0 );
}

string filePath(string input)
{
  unsigned int position;

  position = input.find_last_of('/');
  if (position <= input.length())
    return input.substr(0, position);

  return "";
}

std::vector<string> directoryContents(string directory)
{
	std::vector<string> contents;
	DIR *dir;
	struct dirent *ent;

	if (directory == "")
	{
		errno = FAILED_TO_OPEN_DIRECTORY;
		return contents;
	}

	if ((dir = opendir (directory.c_str())) != NULL)
	{
	  /* print all the files and directories within directory */
	  while ((ent = readdir (dir)) != NULL)
	  {
	  	if (std::string(ent->d_name) != "." && std::string(ent->d_name) != "..")
	  	contents.push_back(ent->d_name);
	  }

	  closedir (dir);
	}
	else
	{
	  errno = FAILED_TO_OPEN_DIRECTORY;
	  return contents;
	}

	return contents;
}

std::vector<string> listImages(string path)
{
	std::vector<string> images;
	std::vector<string> files = directoryContents(path);

	if (files.size() == 0)
		return images;

	for (unsigned int i = 0; i < files.size(); i++)
	{
		if (files[i].length() < 4)
			continue;

		{
			string b = files[i].substr(files[i].length()-4).c_str();
			if (b == ".png" || b == ".PNG" || b == ".jpg" || b == ".JPG" || b == "jpeg" || b == "JPEG")
				images.push_back(files[i]);
		}
	}

	return images;
}

// written by terrence plunkett (eightys3v3n)