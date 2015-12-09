#pragma once
#include <string>
using namespace std;

string int_to_word(int n) {
	int divisor = 100000000, dd = 0, temp = 0;
	bool t, m;
	t = false;
	m = false;
	string word;
	if (n == 0)
		word = "zero";
	else
	{
		if (n < 0) {
			n *= -1;
			word += "negative ";
		}
		for (int i = 1; i <= 3; i++)
		{
			if ((n / 1000000) > 0 && i == 1)
				m = true;
			else if ((n / 1000) > 0 && i == 2)
				t = true;
			for (int j = 1; j <= 3; j++)
			{
				switch (n / divisor)
				{
				case 1:
					if (j % 2 == 0)
					{
						dd = divisor / 10;
						temp = n / dd;
						if ((temp % 10) > 0)
						{
							switch (temp % 10)
							{
							case 1:
								word += "eleven ";
								break;
							case 2:
								word += "twelve ";
								break;
							case 3:
								word += "thirteen ";
								break;
							case 4:
								word += "fourteen ";
								break;
							case 5:
								word += "fifteen ";
								break;
							case 6:
								word += "sixteen ";
								break;
							case 7:
								word += "seventeen ";
								break;
							case 8:
								word += "eighteen ";
								break;
							case 9:
								word += "nineteen ";
								break;
							}
							j++;
							n %= divisor;
							divisor /= 10;
						}
						else {
							word += "ten ";
							j++;
						}
					}
					else
						word += "one ";
					break;
				case 2:
					if (j % 2 == 0)
						word += "twenty ";
					else
						word += "two ";
					break;
				case 3:
					if (j % 2 == 0)
						word += "thirty ";
					else
						word += "three ";
					break;
				case 4:
					if (j % 2 == 0)
						word += "fourty ";
					else
						word += "four ";
					break;
				case 5:
					if (j % 2 == 0)
						word += "fifty ";
					else
						word += "five ";
					break;
				case 6:
					if (j % 2 == 0)
						word += "sixty ";
					else
						word += "six ";
					break;
				case 7:
					if (j % 2 == 0)
						word += "seventy ";
					else
						word += "seven ";
					break;
				case 8:
					if (j % 2 == 0)
						word += "eighty ";
					else
						word += "eight ";
					break;
				case 9:
					if (j % 2 == 0)
						word += "ninety ";
					else
						word += "nine ";
					break;
				}//end switch
				if (j == 1 && (n / divisor) != 0)
					word += "hundred ";
				n %= divisor;
				divisor /= 10;
			}
			if (m && (i == 1)) {
				word += "million ";
				m = false;
			}

			if (t && (i == 2)) {
				word += "thousand ";
				t = false;
			}
		}
	}
	word.erase(word.end() - 1);
	return word;
}