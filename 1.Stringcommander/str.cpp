#include <cctype>
#include "str.h"
// Prototypes of auxiliary functions.
// Note: If skip is true, nonallowable leading characters are
// skipped. If end-of-file is encountered while skipping
// characters, the empty string is returned. If the number
// of allowable characters exceeds MAX_CHARS, the rest are
// read and discarded.
void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only alphanumeric characters.
void GetAlpha(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only alphabetic characters.
void GetNonWhite(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only nonwhitespace characters.
void GetTilNew(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains everything up to newline character.


void StrType::GetStringFile(bool skip, InType charsAllowed, std::ifstream& inFile)
{
	switch (charsAllowed)
	{
	case ALPHA_NUM: GetAlphaNum(skip, letters, inFile);
		break;
	case ALPHA: GetAlpha(skip, letters, inFile);
		break;
	case NON_WHITE: GetNonWhite(skip, letters, inFile);
		break;
	case NOT_NEW: GetTilNew(skip, letters, inFile);
		break;
	}
}


void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile)
// Post: If skip is true, non-alphanumeric letters are skipped.
// Alphanumeric characters are read and stored until a
// non-alphanumeric character is read or MAX_CHARS characters
// have been stored. If the stream is not in the fail state,
// the last character read was a non-alphanumeric character.
{
	using namespace std;
	char letter;
	int count = 0;
	if (skip)
	{// Skip non-alphanumeric characters.
		inFile.get(letter);
		while (!isalnum(letter) && inFile)
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	if (!inFile || !isalnum(letter))
		// No legal character found; empty string returned.
		letters[0] = '\0';
	else
	{// Read and collect characters.
		do
		{
			letters[count] = letter;
			count++;
			inFile.get(letter);
		} while (isalnum(letter) && inFile && (count < MAX_CHARS));
		letters[count] = '\0';
		// Skip extra characters if necessary.
		if (count == MAX_CHARS && isalnum(letter))
			do
			{
				inFile.get(letter);
			} while (isalnum(letter) && inFile);
	}
}


void GetAlpha(bool skip, char letters[], std::ifstream& inFile)
// Post: If skip is true, non-alphanumeric letters are skipped.
// Alphanumeric characters are read and stored until a
// non-alphanumeric character is read or MAX_CHARS characters
// have been stored. If the stream is not in the fail state,
// the last character read was a non-alphanumeric character.
{
	using namespace std;
	char letter;
	int count = 0;
	if (skip)
	{// Skip non-alphanumeric characters.
		inFile.get(letter);
		while (!isalpha(letter) && inFile)
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	if (!inFile || !isalpha(letter))
		// No legal character found; empty string returned.
		letters[0] = '\0';
	else
	{// Read and collect characters.
		do
		{
			letters[count] = letter;
			count++;
			inFile.get(letter);
		} while (isalpha(letter) && inFile && (count < MAX_CHARS));
		letters[count] = '\0';
		// Skip extra characters if necessary.
		if (count == MAX_CHARS && isalpha(letter))
			do
			{
				inFile.get(letter);
			} while (isalpha(letter) && inFile);
	}
}

void GetNonWhite(bool skip, char letters[], std::ifstream& inFile)
// Post: If skip is true, non-alphanumeric letters are skipped.
// Alphanumeric characters are read and stored until a
// non-alphanumeric character is read or MAX_CHARS characters
// have been stored. If the stream is not in the fail state,
// the last character read was a non-alphanumeric character.
{
	using namespace std;
	char letter;
	int count = 0;
	if (skip)
	{// Skip non-alphanumeric characters.
		inFile.get(letter);
		while (!isspace(letter) && inFile)
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	if (!inFile || !isspace(letter))
		// No legal character found; empty string returned.
		letters[0] = '\0';
	else
	{// Read and collect characters.
		do
		{
			letters[count] = letter;
			count++;
			inFile.get(letter);
		} while (isspace(letter) && inFile && (count < MAX_CHARS));
		letters[count] = '\0';
		// Skip extra characters if necessary.
		if (count == MAX_CHARS && isspace(letter))
			do
			{
				inFile.get(letter);
			} while (isspace(letter) && inFile);
	}
}


void GetTilNew(bool skip, char letters[], std::ifstream& inFile)
// Post: If skip is true, newline characters are skipped.
// All characters are read and stored until a newline
// character is read or MAX_CHARS characters have been
// stored. If the stream is not in the fail state, the
// last character read was a newline character.
{
	using namespace std;
	char letter;
	int count = 0;
	if (skip)
	{// Skip newlines.
		inFile.get(letter);
		while ((letter == '\n') && inFile)
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	if (!inFile || letter == '\n')
		letters[0] = '\0';
	else
	{// Read and collect characters.
		do
		{
			letters[count] = letter;
			count++;
			inFile.get(letter);
		} while ((letter != '\n') && inFile && (count < MAX_CHARS));
		letters[count] = '\0';
		// Skip extra characters if necessary.
		if (count == MAX_CHARS && letter != '\n')
			do
			{
				inFile.get(letter);
			} while ((letter != '\n') && inFile);
	}
}





//Funkcja GetString prawie identyczna jak GetStringFile.


void StrType::PrintToScreen(bool newLine)
// Post: letters has been sent to the output stream.
{
	using namespace std;
	if (newLine)
		cout << endl;
	cout << letters;
}


//PrintToFile prawie identyczna jak  PrintToScreen, .

void StrType::PrintToFile(bool newLine, std::ofstream& outFile)
{
	using namespace std;
	if (newLine)
		outFile << endl;

	outFile << letters;
}

#include <cstring>
void StrType::CopyString(StrType& newString)
// Post: letters has been copied into newString.letters.
{
	strcpy_s(newString.letters, letters);
}

int StrType::LengthIs()
// Post: Function value = length of letters string
{
	return std::strlen(letters);
}

void StrType::MakeEmpty() // Post: letters is empty string.
{
	letters[0] = '\0';
}