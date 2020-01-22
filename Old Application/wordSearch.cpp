#include "project.hpp"

using namespace std;

bool comparePtrToPart(Part *a, Part *b)
{
  return (a > b);
}

wordSearch::wordSearch()
{
  root = NULL;
}

wordSearch::~wordSearch()
{
  destructorHelper(root);
}

void wordSearch::findCommonPtrs(vector<Part *> &a, vector<Part *> &b)
{
  vector<Part *> in1 = a;
  a.clear();

  for (vector<Part *>::iterator i = in1.begin(); i < in1.end(); i++)
  {
    for (vector<Part *>::iterator j = b.begin(); j < b.end(); j++)
    {
      if (*i == *j)
      {
        a.push_back(*i);
      }
    }
  }

  return;
}

Part *wordSearch::searchPart(string words, vector<Part *> &commonParts)
{
  std::transform(words.begin(), words.end(), words.begin(), ::tolower); // Convert to all lowercase
  // Parse set of words
  // Use std::set_intersection to identify whether or not there is a common part pointer

  if (words.empty())
  {
    return NULL;
  }

  words = words + " ";
  stringstream s1(words);
  string word;

  int counter = 0;

  while (getline(s1, word, ' '))
  {
    counter++;
  }

  int n = counter;
  counter = 0;

  vector<Part *> maybeParts[n];

  wordNode *foundWord;

  stringstream s2(words);

  while (getline(s2, word, ' '))
  {
    foundWord = searchWordHelper(root, word);

    if (foundWord != NULL)
    {
      for (vector<Part *>::iterator i = foundWord->parts.begin(); i < foundWord->parts.end(); i++)
      {
        maybeParts[counter].push_back(*i);
      }
    }
    counter++;
  }

  commonParts = maybeParts[0];

  for (int i = 1; i < n; i++)
  {
    findCommonPtrs(commonParts, maybeParts[i]);
  }

  return NULL;

  /*
  At this point, the commonParts vector contains pointers to the parts which match the user's query/ies.
  The following are only print statements for diagnostics; return at this point to avoid printing.
  */

  cout << "The number of common pointers is: " << commonParts.size() << endl;

  counter = 0;

  if (!commonParts.size())
  {
    return NULL;
  }
  else
  {
    cout << "Found the following parts:\n\n";

    for (unsigned int i = 0; i < commonParts.size(); i++)
    {
      cout << ++counter << ".\n   Part Name: " << commonParts[i]->name.getStr() << "\n   Part Number: " << commonParts[i]->partNum << endl
           << endl;
    }

    string temp;

    cout << "Which part do you want to see? \n   >>";
    getline(cin, temp);

    return commonParts[stoi(temp) - 1];
  }

  return NULL;
}

void wordSearch::addPart(Part *part)
{
  string name = part->name.getStr();

  std::transform(name.begin(), name.end(), name.begin(), ::tolower);

  stringstream s(name);
  string word;

  while (getline(s, word, ' '))
  {
    addNode(word, part);
  }
}

wordNode *wordSearch::addNodeHelper(wordNode *currNode, string word, Part *part)
{
  wordNode *prev = NULL;
  wordNode *curr = currNode;
  bool isL;

  while (curr != NULL)
  {
    if (curr->word == word)
    {
      curr->parts.push_back(part);
      return curr;
    }
    else if (curr->word > word)
    {
      prev = curr;
      curr = curr->left;

      isL = true;
    }
    else
    {
      prev = curr;
      curr = curr->right;

      isL = false;
    }
  }

  curr = new wordNode;
  curr->word = word;
  curr->parts.push_back(part);
  if (curr != root)
  {
    if (isL)
    {
      prev->left = curr;
    }
    else
    {
      prev->right = curr;
    }
  }
  return currNode;
}

wordNode *wordSearch::createNode(string word, Part *part)
{
  wordNode *temp = new wordNode;
  temp->word = word;
  temp->parts.push_back(part);
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

void wordSearch::addNode(string word, Part *part)
{
  if (root == NULL)
  {
    root = createNode(word, part);
  }
  else
  {
    addNodeHelper(root, word, part);
  }
}

void wordSearch::destructorHelper(wordNode *curr)
{
  if (curr == NULL)
  {
    return;
  }
  else
  {
    destructorHelper(curr->left);
    destructorHelper(curr->right);
    delete curr;
    curr = NULL;
  }
}

wordNode *wordSearch::searchWordHelper(wordNode *currNode, string word)
{
  if (currNode == NULL)
  {
    return NULL;
  }
  else if (currNode->word == word)
  {
    return currNode;
  }
  else if (currNode->word > word)
  {
    return searchWordHelper(currNode->left, word);
  }
  else
  {
    return searchWordHelper(currNode->right, word);
  }
}

void wordSearch::printTreeHelper(wordNode *currNode)
{
  if (currNode == NULL)
  {
    return;
  }

  printTreeHelper(currNode->left);
  cout << "   " << currNode->word << " - " << currNode->parts.size() << endl;
  printTreeHelper(currNode->right);
}
void wordSearch::printTree()
{
  cout << "In-order traversal of the tree:" << endl;
  printTreeHelper(root);
  cout << endl;
  return;
}