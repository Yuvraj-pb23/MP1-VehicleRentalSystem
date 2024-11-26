#include "string_helper.h"

vector<string> split(const string & s, char DELIMITER)
{

  vector<string> tokens;
  string token;
  istringstream tokenstream ( s );

  while (getline(tokenstream, token, DELIMITER))
  {
    tokens.push_back (token);
  }
  return tokens;
}