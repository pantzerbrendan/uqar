#ifndef CHILDACCOUNT_HH_
#define CHILDACCOUNT_HH_

#include "Accounts/A_Account.hh"

class ChildAccount : public A_Account {
private:
    u_int     _idParent;
public:
    ChildAccount (u_int idParent, User *owner, u_int id);
    virtual ~ChildAccount ();

    double      withdrawal(const double amount);
};

#endif /* !CHILDACCOUNT_HH_ */
