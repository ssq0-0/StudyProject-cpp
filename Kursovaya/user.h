#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string login;
    std::string pass;
    int root;

public:
    User(const std::string& login, const std::string& pass, int root);
    virtual ~User() {}  // Виртуальный деструктор

    std::string getLogin() const;
    std::string getPass() const;
    int getRoot() const;

    void setRoot(int newRoot);
    void setLogin(const std::string& newLogin);
    void setPass(const std::string& newPass);
    static bool validateLogin(const std::string& login, const std::string& pass);

    virtual void manageUser(User& user) = 0; // Абстрактный метод
};

class Admin : public User {
    Admin(const std::string& login, const std::string& pass);

        void manageUser(User& user) override;

    User createUser(const std::string& login, const std::string& pass);
};
#endif // USER_H
