#ifndef CHILDACCOUNT_HH_
#define CHILDACCOUNT_HH_

#include "Accounts/A_Account.hh"

class ChildAccount : public A_Account {
private:
    int     _idParent;
public:
    ChildAccount (arguments);
    virtual ~ChildAccount ();

    double      withdrawal(const double amount);
};

#endif /* !CHILDACCOUNT_HH_ */
