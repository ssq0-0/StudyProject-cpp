#include "user.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <QDebug>
using namespace std;

User::User(const std::string& login, const std::string& pass, int root)
    : login(login), pass(pass), root(root) {}

std::string User::getLogin() const {
    return login;
}

std::string User::getPass() const {
    return pass;
}

int User::getRoot() const {
    return root;
}

void User::setLogin(const std::string& newLogin) {
    login = newLogin;
}

void User::setPass(const std::string& newPass) {
    pass = newPass;
}

void User::setRoot(int newRoot) {
    root = newRoot;
}

bool User::validateLogin(const std::string& login, const std::string& pass) {
    std::ifstream file("/Users/ssq/Desktop/kursach/Kursovaya/users.txt");
    if (!file) {
            qDebug() << "Ошибка при открытии файла users.txt";
            return false;
        }
        std::string line;

        while (std::getline(file, line)) {
            istringstream iss(line);
            string storedLogin, storedPass;

            if (!(iss >> storedLogin >> storedPass)) {
                qDebug() << "Ошибка в формате строки:" << QString::fromStdString(line);
                break; // Ошибка в формате строки
            }

            if (storedLogin == login && storedPass == pass) {
                return true; // Успешная проверка логина и пароля
            }
        }

        return false;
}

Admin::Admin(const std::string& login, const std::string& pass)
    : User(login, pass, 1) {}

void Admin::manageUser(User& user) {
    std::string newPassword;
    std::cin >> newPassword;
    user.setPass(newPassword);

    int newRootLevel;
    std::cin >> newRootLevel;
    user.setRoot(newRootLevel);
}


