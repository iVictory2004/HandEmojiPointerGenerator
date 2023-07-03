#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define N 14

ofstream out("out.txt");
vector<vector<string>> emojis{{"👉🏿", "👉🏾", "👉🏽", "👉🏼", "👉🏻", "👉"},
                              {"👇🏿", "👇🏾", "👇🏽", "👇🏼", "👇🏻", "👇"},
                              {"👈🏿", "👈🏾", "👈🏽", "👈🏼", "👈🏻", "👈"},
                              {"👆🏿", "👆🏾", "👆🏽", "👆🏼", "👆🏻", "👆"}};
void paintLine(int step, bool down)
{
    for (int i = 0; i < step; i++)
        out << emojis[0][i];

    for (int i = 0; i < N - 2 * step; i++)
        out << emojis[(down ? 1 : 3)][step];
    if (step != 0)
        for (int i = step; i >= 0; i--)
            out << emojis[2][i];
    else
        out << emojis[(down ? 1 : 3)][step];
    out << '\n';
}
void PaintMiddleLineWithEmojilol(string emoji)
{
    for (int i = 0; i < 6; i++)
        out << emojis[0][i];
    out << emoji;
    for (int i = 5; i >= 0; i--)
        out << emojis[2][i];
    out << '\n';
}
void GoofyAahArt(string emoji)
{
    // paint uppder half
    for (int i = 0; i < 6; i++)
        paintLine(i, 1);
    PaintMiddleLineWithEmojilol(emoji);
    // paint lower half
    for (int i = 5; i >= 0; i--)
        paintLine(i, 0);
}
int main()
{
    GoofyAahArt("💀💀💀");
    return 0;
}