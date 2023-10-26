#include <iostream>
#include <string> 
#include <cctype> //for toupper()
#include <fstream> //to read file contents
//https://www.udacity.com/blog/2021/05/how-to-read-from-a-file-in-cpp.html (RESOURCE)


//using a user input file 
void readingfile()
{
	std::string fileinput; //stores the contents of the file
	std::string fileresult = "";
	std::string filename;
	std::ifstream readfile; //created a variable to read the file input

	std::cout << "Enter name of file: " << std::endl;
	std::cin >> filename;

	readfile.open(filename);

	if (readfile.is_open()) //checks if file is opem
	{
			while(readfile)
		{
			std::getline (readfile, fileinput);
			for (int i = 0; i < fileinput.length(); i++)
			{
			char temp = toupper(fileinput[i]);
			fileresult = fileresult + temp;
			}

		std::cout << fileresult << std::endl;
		fileresult = ""; //error: last line repeats twice
		}
		

			//std::getline (readfile, fileinput);
			//std::cout << fileinput << std::endl;
	} //this gets everything written in the file 
		
		//readfile >> fileinput; //pipe the file's content into stream/ put it into the string
		//std::cout << fileinput; //only gets the first word
	else 
	std::cout << "Error: File couldn't be located." << std::endl;
	
}

//using user input 
void readinginput(){
	std::string input; 
	std::string result = "";	

	std::cout << "Enter: ";

	//(Resource) https://cplusplus.com/forum/beginner/248026/     https://www.geeksforgeeks.org/getline-string-c/
	std::cin.ignore(); //cin will not ignore white spaces 
	std::getline(std::cin, input); //error: doesnt allow any user input for some reason

	for (int i = 0; i < input.length(); i++)
	{
		char temp = toupper(input[i]); //creates a temporary storage for the output of the function
		result = result + temp; //concats the new string output
	}
	
	std::cout << result << std::endl; 

	
}

int main(){
	
	char input;
	std::cout << "Choose F for file based input, T for typed input." << std::endl;
	std::cin >> input;

	switch(input)
	{
		case 'F':
		readingfile();
		break;

		case 'T':
		readinginput();
		break;

		default: 
		std::cout << "Invalid Input" << std::endl;
		break;
	}
	return 0;
}

/*next steps: 
make it all lowercase
make it in proper name format (first letter uppercase for ever name)
reorder in a user given syntax
*/