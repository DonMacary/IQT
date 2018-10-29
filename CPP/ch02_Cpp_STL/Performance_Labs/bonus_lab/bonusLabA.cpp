/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C++ Programming
/   PROGRAM NAME: bonusLabA.cpp
/   PROGRAM DESCRIPTION: BONUS LAB: CPP_CRYPTOGRAHAM CRACKER
/   INSTRUCTIONS:
BONUS LAB: CPP_CRYPTOGRAHAM CRACKER

objective: Design a CPP program that will encode user input.

requirements: print user input as both plain text and CODED. output to FILE!. alpha numeric only (a-z, A-Z, 0-9)


**********************************************************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int get_int_input();
std::string get_text();
std::string encode_message(std::string key, std::string message);
std::string decode_message(std::string key, std::string encodedMessage);

int main(void)
{
	std::string message;
	std::string encodedMessage;
    std::string line;
    std::cout << "Enter a string key for encryption/decryption: ";
	std::string key = get_text();
	int choice = 0;
    std::fstream file("encrypted.txt");
    std::ofstream decryptFile("decrypt.txt");
    if(!file.is_open())
    {
        perror("Error opening file!");
    }
    if(!decryptFile.is_open())
    {
        perror("Error opening file!");
    }
    while(choice != 3)
    {
        std::cout << "OPTIONS:" << std::endl;
        std::cout << "1.)Encrypt Message" << std::endl;
        std::cout << "2.)Decrypt Message" << std::endl;
        std::cout << "3.)Exit" << std::endl;
        choice = get_int_input();

        switch (choice)
        {
        case 1:
            std::cout << "Enter a message you would like to encode:" << std::endl;
            message = get_text();
            encodedMessage = encode_message(key, message);
            file << encodedMessage << std::endl;
            std::cout << "Encoded Message: " << encodedMessage << std::endl;
            break;
        case 2:

            while(getline(file,encodedMessage))
            {
                message = decode_message(key, encodedMessage);
                decryptFile << message << std::endl;
                std::cout << "Decoded Message: " << message << std::endl;
            }
            break;
        case 3:
            std::cout << "Have a nice day!" << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
        }
    }
	file.close();
    decryptFile.close();
	return 0;
}


int get_int_input()
{
	int number = 0;
	std::string input = "";
	while (true)
	{
		std::getline(std::cin, input);
		std::stringstream myStream(input);
		if (myStream >> number)
			break;
		std::cout << "Invalid number, please try again" << std::endl;
	}
	return number;
}

std::string get_text()
{

	std::string plainText = "";
	std::getline(std::cin, plainText);
	
	return plainText;

}

std::string encode_message(std::string key, std::string message)
{
	std::string encodedMessage;
	for (int i = 0; i < message.length(); i++)
	{
		
        if(message[i] == 32)
        {
            encodedMessage += message[i];
        }
        else
        {
            //add the key to the message
            encodedMessage += message[i] + (key[i%key.length()] % 93);
            //if we go over z then were going to loop back around and start at A (which is 97)
            if (encodedMessage[i] > 126)
            {
                encodedMessage[i] = (encodedMessage[i] - 126) + 32;
            }
        }
		
	}

	return encodedMessage;
}


std::string decode_message(std::string key, std::string encodedMessage)
{
	std::string message;
    for(int i =0; i < encodedMessage.length(); i++)
    {

        if(encodedMessage[i] == 32)
        {
            message += encodedMessage[i];
        }
        else
        {
            message += encodedMessage[i] - key[i%key.length()] % 93;
            if(message[i] < 33)
            {
                message[i] = 126 - (33 - message[i]);
            }
        }

    }

	return message;

}