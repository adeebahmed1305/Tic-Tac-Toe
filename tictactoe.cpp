#include <iostream>
using namespace std;

char space[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int row;
int column;
char token = 'X';
bool tie = false;
string p1;
string p2;

void ticOne() {

	cout << "      |     | " << endl;
	cout << " " << space[0][0] << "    | " << space[0][1] << "   | " << space[0][2] << endl;
	cout << " _____|_____|_____ " << endl;
	cout << "      |     | " << endl;
	cout << " " << space[1][0] << "    | " << space[1][1] << "   | " << space[1][2] << endl;
	cout << " _____|_____|_____" << endl;
	cout << "      |     | " << endl;
	cout << " " << space[2][0] << "    | " << space[2][1] << "   | " << space[2][2] << endl;
	cout << "      |     | " << endl;

}

void tacTwo() {

	int digit;

	if (token == 'X') {
		cout << p1 << " choose a spot!: ";
		cin >> digit;
	}
	if (token == 'O') {
		cout << p2 << " choose a spot!: ";
		cin >> digit;
	}

	if (digit == 1) {
		row = 0;
		column = 0;
	}

	if (digit == 2) {
		row = 0;
		column = 1;
	}

	if (digit == 3) {
		row = 0;
		column = 2;
	}

	if (digit == 4) {
		row = 1;
		column = 0;
	}

	if (digit == 5) {
		row = 1;
		column = 1;
	}

	if (digit == 6) {
		row = 1;
		column = 2;
	}

	if (digit == 7) {
		row = 2;
		column = 0;
	}

	if (digit == 8) {
		row = 2;
		column = 1;
	}

	if (digit == 9) {
		row = 2;
		column = 2;
	}

	else if(digit < 1 || digit > 9) {

		cout << "Try again! " << endl;

	}

	if (token == 'X' && space[row][column] != 'X' && space[row][column] != 'O') {

		space[row][column] = 'X';
		token = 'O';
	}

	else if (token == 'O' && space[row][column] != 'X' && space[row][column] != 'O') {

		space[row][column] = 'O';
		token = 'X';

	}

	else {

		cout << "There are no empty spaces left! " << endl;
		tacTwo();
	}

	//ticOne();
}

bool toeThree() {

	for (int i = 0; i < 3; i++) {

		if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
			return true;
	}

	if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0])
		return true;

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			if (space[i][j] != 'X' && space[i][j] != 'O') {
				return false;
			}
		}
	}

	tie = true;
	return false;

}

int main() {

	cout << "Enter Player 1's name: ";
	cin >> p1;
	cout << "Enter Player 2's name: ";
	cin >> p2;
	cout << p1 << " goes first" << endl;

	while (!toeThree()) {
		ticOne();
		tacTwo();
		toeThree();

	}

	if (token == 'X' && tie == false) {

		cout << p2 << " WINS! " << endl;
		cout << p1 << " GET BETTER KID! " << endl;

	}

	else if(token == 'O' && tie == false){
	
		cout << p1 << " WINS! " << endl;
		cout << p2 << " GET BETTER KID! " << endl;

	}

	else {

		cout << "ITS A TIE! " << endl;

	}
}