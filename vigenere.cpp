#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Função para cifrar a cifra de Vigenère
string encryptVigenere(const string &message, const string &key) {
    string encryptedMessage;
    int messageLength = message.length();
    int keyLength = key.length();
    int keyIndex = 0;

    for (int i = 0; i < messageLength; i++) {
        if (isalpha(message[i])) {
            char messageChar = message[i];
            char keyChar = key[keyIndex % keyLength];
            char encryptedChar;

            char shift = isupper(messageChar) ? 'A' : 'a';

            encryptedChar = (messageChar + keyChar - 2 * shift) % 26 + shift;

            encryptedMessage += encryptedChar;
            keyIndex++;
        } else {
            // Se não for uma letra, mantenha o caractere original
            encryptedMessage += message[i];
        }
    }

    return encryptedMessage;
}

// Função para decifrar a cifra de Vigenère
string decryptVigenere(const string &message, const string &key) {
    string decryptedMessage;
    int messageLength = message.length();
    int keyLength = key.length();
    int keyIndex = 0;

    for (int i = 0; i < messageLength; i++) {
        if (isalpha(message[i])) {
            char messageChar = message[i];
            char keyChar = key[keyIndex % keyLength];
            char decryptedChar;

            char shift = isupper(messageChar) ? 'A' : 'a';

            decryptedChar = (messageChar - keyChar + 26) % 26 + shift;

            decryptedMessage += decryptedChar;
            keyIndex++;
        } else {
            // Se não for uma letra, mantenha o caractere original
            decryptedMessage += message[i];
        }
    }

    return decryptedMessage;
}

int main() {
    int choice;
    string message, key, result;

    cout << "Escolha uma opção:\n";
    cout << "1. Cifrar\n";
    cout << "2. Decifrar\n";
    cout << "Opção: ";
    cin >> choice;

    cin.ignore(); // Limpa o buffer do teclado

    switch (choice) {
        case 1:
            cout << "Digite a mensagem para cifrar: ";
            getline(cin, message);

            cout << "Digite a chave: ";
            getline(cin, key);

            result = encryptVigenere(message, key);
            cout << "Mensagem cifrada: " << result << endl;
            break;

        case 2:
            cout << "Digite a mensagem para decifrar: ";
            getline(cin, message);

            cout << "Digite a chave: ";
            getline(cin, key);

            result = decryptVigenere(message, key);
            cout << "Mensagem decifrada: " << result << endl;
            break;

        default:
            cout << "Opção inválida!" << endl;
            break;
    }
    return 0;
}
