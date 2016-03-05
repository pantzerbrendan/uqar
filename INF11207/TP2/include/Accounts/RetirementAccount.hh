#ifndef RETIREMENTACCOUNT_HH_
#define RETIREMENTACCOUNT_HH_

#include "Accounts/A_Account.hh"

class RetirementAccount : public A_Account {
private:
    bool    _auth;
public:
    RetirementAccount (arguments);
    virtual ~RetirementAccount ();

    double      withdrawal(const double amount);
};

#endif /* !RETIREMENTACCOUNT_HH_ */
