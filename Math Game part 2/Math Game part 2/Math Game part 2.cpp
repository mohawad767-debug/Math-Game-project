// Math Game part 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

enum enlevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum entype { Add = 1, Sub = 2, Mul = 3, Div = 4, mix = 5 };
enum enpassfail { Pass = 1, Fail = 2 };

struct stGameInfo {


	short num_of_questions;
	enlevel questions_level;
	entype questions_operations_type;
	short num_of_correct=0;
	short num_of_wrong=0;
	enpassfail result;

};

struct stQuestionInfo {

	int operand1;
	int operand2;
	entype operation_type;
	int user_answer;
	int correct_answer;

};

int RandomNumber(int from, int to)
{

	return rand() % (to - from + 1) + from;

}

short Read_num_of_questions()
{

	int c;
	do
	{

		cout << "How Many questions do you want to answer: ";
		cin >> c;

	} while (c <= 0);

	return c;




}

enlevel Read_questions_level()
{
	int c;
	do
	{


		cout << "Enter questions level [1] Easy, [2]Med, [3] Hard, [4] Mix : ";
		cin >> c;

	} while (c < 1 || c > 4);

	return (enlevel)c;







}

entype Read_operation_type()
{

	int c;

	do
	{


		cout << "Enter operation type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix : ";
		cin >> c;
	} while (c < 1 || c>5);

	return (entype)c;






}

stGameInfo Read_Game_Info()
{
	stGameInfo GameInfo;

	GameInfo.num_of_questions = Read_num_of_questions();
	GameInfo.questions_level = Read_questions_level();
	GameInfo.questions_operations_type = Read_operation_type();

	return GameInfo;







}

int Set_Operand(enlevel level)
{ 
	switch (level)
	{
	case enlevel::Easy:
		return RandomNumber(1, 10);
	case enlevel::Med:
	    return RandomNumber(25, 50);
	case enlevel::Hard:
		return RandomNumber(50, 100);









	}



}

void Get_Operands(stGameInfo GameInfo,stQuestionInfo &QuestionInfo)
{
     enlevel Random;
	if (GameInfo.questions_level == enlevel::Mix)
	{
		Random = (enlevel) RandomNumber(1, 3);
		QuestionInfo.operand1 = Set_Operand(Random);
		QuestionInfo.operand2 = Set_Operand(Random);

	}
	else
	{
		QuestionInfo.operand1 = Set_Operand(GameInfo.questions_level);
		
		QuestionInfo.operand2 = Set_Operand(GameInfo.questions_level);


	}


}

entype Set_question_OP_type(int random)
{
	switch (random)
	{

	case 1:
		return entype::Add;
	case 2:
		return entype::Sub;
	case 3:
		return entype::Mul;
		case 4:
			return entype::Div;

	}



}


entype Get_question_OP_type(stGameInfo GameInfo)
{
	entype Random;

	if (GameInfo.questions_operations_type == entype::mix)
	{


		Random = (entype)RandomNumber(1, 4);
		return Set_question_OP_type(Random);

	}
	else
	{

		return GameInfo.questions_operations_type;


	}


}

int Get_Final_answer(stQuestionInfo QuestionInfo)
{
	switch (QuestionInfo.operation_type)
	{
	case entype::Add:
		return QuestionInfo.operand1 + QuestionInfo.operand2;
	case entype::Sub:
		return QuestionInfo.operand1 - QuestionInfo.operand2;
	case entype::Div:
		return QuestionInfo.operand1 / QuestionInfo.operand2;
	case entype::Mul:
		return QuestionInfo.operand1 * QuestionInfo.operand2;









	}
}


stQuestionInfo Read_Question_Info(stGameInfo GameInfo)
{
	stQuestionInfo QuestionInfo;

	Get_Operands(GameInfo, QuestionInfo);

	QuestionInfo.operation_type = Get_question_OP_type(GameInfo);
	QuestionInfo.correct_answer = Get_Final_answer(QuestionInfo);

	return QuestionInfo;






}

void Print_Operands(stQuestionInfo QuestionInfo)
{
	cout << QuestionInfo.operand1 << endl;
	cout << QuestionInfo.operand2;




}

string Print_Operator(entype type)
{
	switch (type)
	
	{
	case entype::Add:
		return "+";

	case entype::Div:
		return "/";

	case entype::Mul:
		return "*";

	case entype::Sub:
		return "-";
	case entype::mix:
		return "Mix";


	}




}

bool Check_answer(int answer)
{
	int c;
	cin >> c;

	return(c == answer);






}

enpassfail passorfail(stGameInfo GameInfo)
{
	if (GameInfo.num_of_correct >= GameInfo.num_of_wrong)
	{


		return enpassfail::Pass;
	}
	else
	{

		return enpassfail::Fail;
	}



}

string Returnpassorfail(enpassfail result)
{


	switch (result)
	{

	case enpassfail::Pass:
		return "Pass!";
	case enpassfail::Fail:
		return "Fail!";
	}
}

string ReturnQuestionsLevel(enlevel level)
{


	switch (level)
	{
	case enlevel::Easy:
		return "Easy";
	case enlevel::Med:
		return "Med";
	case enlevel::Hard:
		return "Hard";
	case enlevel::Mix:
		return "Mix";




	}
}

void Print_final_results(stGameInfo GameInfo)
{

	cout << "\n\n_______________________________________________\n\n";
	cout << "   Final Results is " << Returnpassorfail(GameInfo.result) << endl;
	cout << "\n\n_______________________________________________\n\n";

	cout << "Number of questions    : " << GameInfo.num_of_questions << endl;
	cout << "Questions level        : " << ReturnQuestionsLevel(GameInfo.questions_level) << endl;
	cout << "OPType                 : " << Print_Operator(GameInfo.questions_operations_type) << endl;
	cout << "Number of right answers: " << GameInfo.num_of_correct << endl;
	cout << "Number of wrong answers: " << GameInfo.num_of_wrong << endl;

	cout << "\n_______________________________________________\n\n";








}


void Program()
{
	stGameInfo GameInfo = Read_Game_Info();
	stQuestionInfo QuestionInfo;


	for (short i = 1;i <= GameInfo.num_of_questions;i++)
	{
		cout << "\n\nQuestion [" << i << "/" << GameInfo.num_of_questions << "]\n\n";
		QuestionInfo = Read_Question_Info(GameInfo);

		Print_Operands(QuestionInfo);
		cout<< Print_Operator(QuestionInfo.operation_type);
		cout << "\n\n______________________________________\n";

		if (Check_answer(QuestionInfo.correct_answer))
		{
			system("color 2F");
			cout << "\nRight Answer!\n";
			GameInfo.num_of_correct++;



		}
		else
		{
			system("color 4F");
			cout << "\n\aWrong Answer!\n";
			cout << "The right answer is " << QuestionInfo.correct_answer << endl;
			GameInfo.num_of_wrong++;


		}







	}


	GameInfo.result = passorfail(GameInfo);



	Print_final_results(GameInfo);










}

void StartProgram()
{

	char c;
	do
	{
		system("cls");
		system("color 0F");

		Program();


		cout << "\nDo you want to play again y/n: ";
		cin >> c;


	} while (c == 'y');





}



int main()
{ 
	  
	srand((unsigned)time(NULL));
	 
	 
	StartProgram();
	 
	 
	 

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
