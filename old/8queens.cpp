#include <cstdio>
#include <cstring>
using namespace std;

char board[10][10], atk[10][10];

int main()
{
	while (scanf("%s ", board[0]) != EOF)
	{
		for (int i = 1; i < 8; i++)
			scanf("%s ", board[i]);
		
		for (int i = 0; i < 8; i++)
			fprintf(stderr, "%s\n", board[i]);

		memset(atk,0,sizeof atk);
		
		int valid = 1, count = 0;
		for (int r = 0; r < 8; r++) for (int c = 0; c < 8; c++) if (board[r][c] == '*')
		{
			count++;
			if (atk[r][c]) valid = 0;
			for (int r_ = 0; r_ < 8; r_++) for (int c_ = 0; c_ < 8; c_++)
				if (r_ == r || c_ == c || r_ + c_ == r + c || r_ - c_ == r - c)
					atk[r_][c_] = 1;
		}

		valid &= count == 8;

		printf("%s\n", valid ? "valid" : "invalid");
	}

	return 0;
}
