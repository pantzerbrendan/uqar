#ifndef RETIREMENTACCOUNT_HH_
#define RETIREMENTACCOUNT_HH_

#include "Accounts/A_Account.hh"

class RetirementAccount : public A_Account {
private:
    bool    _auth;
public:
    RetirementAccount (User *owner, u_int id);
    ~RetirementAccount ();

    double      withdrawal(const double amount);
    void        setAuth(const bool auth);
};

#endif /* !RETIREMENTACCOUNT_HH_ */
