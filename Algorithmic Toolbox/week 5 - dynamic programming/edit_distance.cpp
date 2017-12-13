#include <iostream>
using namespace std;

// Utility function to find minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }

int editDist(string str1, string str2)
{
    // Create a table to store num_of_edits
    int edits[str1.length() + 1][str2.length() + 1];

    // Fill edits[][] in bottom up manner
    for (int i = 0; i <= str1.length(); i++)
    {
        for (int j = 0; j <= str2.length(); j++)
        {
            // If first string is empty, insert all characters of second string
            if (i == 0) { edits[i][j] = j; }

            // If second string is empty, insert all characters of first string
            else if (j == 0) { edits[i][j] = i; }

            // If last characters are same, ignore last char and recur for remaining string
            else if (str1[i-1] == str2[j-1]) { edits[i][j] = edits[i-1][j-1]; }

            // If last character are different, consider all possibilities and find minimum
            else { edits[i][j] = 1 + min(edits[i][j - 1], edits[i - 1][j], edits[i - 1][j - 1]); }
        }
    }
    return edits[str1.length()][str2.length()];
}

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDist(str1, str2);
}

