#include "string_helper.h"

vector<string> split (const string & s, char delimiter)
{

  vector<string> tokens;
  string token;
  istringstream tokenstream ( s );

  while (getline(tokenstream, token, delimiter))
  {
    tokens.push_back (token);
  }
  return tokens;
}