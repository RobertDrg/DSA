// C++ program for Naive Pattern 
// Searching algorithm 
#include <iostream> 
#include <chrono> 
using namespace std;
using namespace std::chrono;
void search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            cout << "Pattern found at index "
            << i << endl;
    }
}

// Driver Code 
int main()
{
    char txt[] = "AABRAACADABRAACAADABRAADCNBADAAACAAA";
    char pat[] = "AACAAA";
    auto start = high_resolution_clock::now();
    search(pat, txt);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
        << duration.count() << " microseconds" << endl;
    return 0;
}

// This code is contributed 
// by Akanksha Rai 