#include<iostream>
#include<sstream>//for stringstream
#include<stdlib.h>
using namespace std;

void errMessages(int argc)
{
    if(argc<2)
        cout<<" Incorrect usage \n"
              " Use as follows :  <shift> <operation> <message>\n";
    else if(argc<4)
        cout<<" Not enough parameters \n"
              " Use as follows :  <shift> <operation> <message>\n";
    exit(1);
}

void encryptMessage(string message, int key)
{
    string clearText;
    clearText.resize(message.length()); //empty string objects cannot be extended otherwise
    for(int i=0; i<(message.length()); i++)
    {
        if(isalpha(message[i]))
        {
            if(islower(message[i]))
                clearText[i] = (message[i] + key - 'a') % 26 + 'a';
            else
                clearText[i] = (message[i] + key - 'A') % 26 + 'A';
        }
        else clearText[i] = message[i];
    }
    cout<<" The encrypted message is : "<<clearText<<endl;
}

void decryptMessage(string message, int key)
{
    string clearText;
    for(int i=0; i<(message.length()-1); i++)
    {
        if(isalpha(message[i]))
        {
            if(islower(message[i]))
                clearText[i] = (message[i] - key - 'a') % 26 + 'a';
            else
                clearText[i] = (message[i] - key - 'A') % 26 + 'A';
        }
        else clearText[i] = message[i];
    }
    cout<<" The decrypted message is : "<<clearText<<endl;
}

int main( int argc, char * argv[] )
{
    errMessages(argc);
    cout<<argc<<" "<<argv[0]<<" "<<" "<<argv[2]<<" "<<argv[3];
    int shift = 0;
    stringstream converter(argv[1]);
    if(!(converter>>shift))
    {
         std::cout<<"Failed to convert to integer ! "
                    " Try again ";
    }
    string operation(argv[2]);
    string message;
    while(int i = 3 < argc)
    {
        message+=argv[i];
        message+=" ";
        i++;
    }
    if(operation=="decrypt")
        decryptMessage(message, shift);
    else if(operation=="encrypt")
        encryptMessage(message, shift);
    else cout<<" Use as follows :  <shift> <operation> <message>\n";
    return 0;
}