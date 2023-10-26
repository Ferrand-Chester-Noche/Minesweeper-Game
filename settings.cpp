#include<bits/stdc++.h>
using namespace std;

//To assign a choice to a specific difficulty
#define EASY 1
#define MEDIUM 2
#define HARD 3

#define MAX_SIDES 25
#define MAX_MINES 99
#define MOVE_SIZE 526 // To get 526 = (25 * 25 - 99)

//Variable Declarations
int rows, columns, mine, level, marker = 0, act;
